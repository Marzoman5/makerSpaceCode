#include <EEPROM.h>
int data;
char state;
int address;
void setup(){
 Serial.begin (9600);
}

void loop() {
while(!Serial.available()){
  delay(10);
}
state =Serial.read();
if (state == 'w')
  {
  Serial.println("where is it boy");
  
  while(!Serial.available())
  {
  delay(10);
  }
  
  address= Serial.parseInt();
  Serial.println("what int man");
  
  while(!Serial.available())
  {
  delay(10);
  }
  
  data=Serial.parseInt();
  EEPROM.write(address,data);
  Serial.println("wrote data to Address");
  }
else if( state=='r')
  {
  Serial.println("reading Data");
  Serial.println ("from where ");
  while(!Serial.available()){
  delay(10);
}
address=Serial.parseInt();
data = EEPROM.read(address);
Serial.println(data); 
  }
  else 
  {
  Serial.println("bad command");
  }
}
void EEPROMWriteInt(int address,int value)
{
  byte lowbyte = ((value>>0)& 0xff);
  byte highbyte =((value>>8)& 0xff);
  EEPROM.write(address ,highbyte);
  EEPROM.write(address+1, lowbyte);
} 
int EEPROMReadInt(int address)
{
 
    byte lowbyte = EEPROM.read(address);
    byte highbyte = EEPROM.read(address+1);
    int value= lowbyte+(highbyte<<8);
    return(value);
  }
  



