/*
using the arduino nana CSPI pins at the base of the board

this end programming cable
plugs
123
456


1: vcc
2: MOSI
3: GND
4: MISO
5: CLOCK
6:

CHIP SELECT PIN: digital 10
 */

#include <SPI.h>
#include <SD.h>
#include "Filesystem.h"
#include "Initalization.h"
#include "HX711.h"

#define calibration_factor -8000.0 //Calibrated with 2.4 kg on 11/9/17

#define DOUT  3
#define CLK  2

HX711 scale(DOUT, CLK);

#define chipSelect 10
int GoLED= 7;
int NoLED= 8;
char FILENAME[]= "Thrust0.csv";
File file;
//   int initialEEProm = EEPROM.read(1);

//Filename(&FILENAME[0]);
void setup() 
{
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
   
  pinMode(chipSelect, OUTPUT);
  pinMode(GoLED,OUTPUT);
  pinMode(NoLED,OUTPUT);
  digitalWrite(GoLED,LOW);
  digitalWrite(NoLED,LOW);
  
  
  Serial.begin(9600);
  inital(&GoLED,&NoLED);
 

  file = SD.open(FILENAME, FILE_WRITE);
    if(file)
    {
      file.print("Time");
      file.print(",");
      file.println("Thrust");
      };
  file.close();
  
}

void loop() 
{
  file = SD.open(FILENAME, FILE_WRITE);
  
  if(file)
  {
    file.print(millis());
    file.print(",");
    file.println(scale.get_units(),1);
    };
    
  file.close();
}

  


