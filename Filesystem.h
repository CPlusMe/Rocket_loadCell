#ifndef FILESYSTEM_H
#define FILESYSTEM_H
 
 #include <EEPROM.h>

void Filename(int *string);

  void Filename(int *string)
  {

    int initialEEProm = EEPROM.read(1);
    EEPROM.write(1,initialEEProm+1);
    int lognum  = initialEEProm + 65;
    
    
    if(lognum >=65  && lognum < 90)
      {
        *(string+10) = char(lognum); 
    }else
      {
        EEPROM.write(1,0);
        *(string+10) = {'A'};
        };
    
    return;
 }



#endif




  
