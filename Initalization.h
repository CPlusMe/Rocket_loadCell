#ifndef INITAL_H
#define INITAL_H

#include <SD.h>
void inital(int *go, int *no);
void inital(int *go, int *no)
{
  Serial.begin(9600);
  
  while (!Serial) {
//    digitalWrite(*no,HIGH);
  }
  
    Serial.print("Initializing SD card...");

  while(!SD.begin()) {
    Serial.println("Card failed, or not present");
    SD.begin();
    delay(100);
//    digitalWrite(*no,HIGH);
  }
  Serial.println("card initialized.");
  digitalWrite(*no,LOW);
  digitalWrite(*go,HIGH);
  }

#endif 
