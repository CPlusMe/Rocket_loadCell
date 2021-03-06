/*
 Example using the SparkFun HX711 breakout board with a scale
 By: Nathan Seidle
 SparkFun Electronics
 Date: November 19th, 2014
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 This example demonstrates basic scale output. See the calibration sketch to get the calibration_factor for your
 specific load cell setup.

 This example code uses bogde's excellent library: https://github.com/bogde/HX711
 bogde's library is released under a GNU GENERAL PUBLIC LICENSE

 The HX711 does one thing well: read load cells. The breakout board is compatible with any wheat-stone bridge
 based load cell which should allow a user to measure everything from a few grams to tens of tons.
 Arduino pin 2 -> HX711 CLK
 3 -> DAT
 5V -> VCC
 GND -> GND

 The HX711 board can be powered from 2.7V to 5V so the Arduino 5V power should be fine.

*/

#include "HX711.h"
include <SPI.h>
#include <SD.h>
#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  3
#define CLK  2
#define onLED 3 // Make this one green
#define offLED 4 //make this one red
#define FILENAME "datalog.csv"
int check = 0;


HX711 scale(DOUT, CLK);
FILE myfile;

void setup() {
  //PinModes
  
  pinMode(onLED,OUTPUT);
  pinMode(offLED,OUTPUT);
  //pinstates
  digitalWrite(onLED,LOW);
  digitalWrite(offLED,LOW);

  //check sequence
  Serial.begin(9600);
  if(Serial)
  check++;

  if(SD.begin())
  check++

  if(check == 2)
  {
    digitalWrite(onLEd,HIGH)
    }
    else if (check != 2)
    {
        digitalWrite(offLED,HIGH);
        while(true)
        {};
      };

  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

}

void loop() {
myfile = SD.open(FILENAME,FILE_WRITE);
  
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1); //scale.get_units() returns a float
  Serial.println(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
  myfile.close();

}
