#include <EEPROM.h>

void writeCharArrayIntoEEPROM(int address, char charArray[], int arraySize)
{
  Serial.print("\nEEPROM WRITE: ");
  int addressIndex = address;
  for (int i = 0; i < arraySize; i++) 
  {
    EEPROM.update(addressIndex, charArray[i]);
    //EEPROM.write(addressIndex + 1, charArray[i] & 0xFF);
    addressIndex += 1;
    Serial.print((char)charArray[i]);
  }
  Serial.print("\nEND EEPROM WRITE\n");
}
void readCharArrayFromEEPROM(int address, char charArray[], int arraySize)
{
  Serial.print("\nEEPROM: ");
  Serial.print(arraySize);
  int addressIndex = address;
  for (int i = 0; i < arraySize; i++)
  {
    charArray[i] = (char)EEPROM.read(addressIndex);// << 8) + EEPROM.read(addressIndex + 1);
    Serial.print((char)EEPROM.read(addressIndex));// << 8) + EEPROM.read(addressIndex + 1));
    Serial.print(" | char: ");
    Serial.print(charArray[i]);
    Serial.print(",");
    addressIndex += 1;
  }
  Serial.print("\nEND EEPROM\n");
}
/*
void clearEEPROM()
{
  for (int i = 0; i < EEPROM.length(); i++)
  {
    EEPROM.write(i, 0);
  }
}
*/
int freeRam() {
  extern int __heap_start,*__brkval;
  int v;
  return (int)&v - (__brkval == 0  
    ? (int)&__heap_start : (int) __brkval);  
}
void display_freeram() {
  Serial.print(F("- SRAM left: "));
  Serial.println(freeRam());
}
