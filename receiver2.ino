#include <SPI.h>


char buff[50] = "Lab 1 Complete";
boolean str_display;
int i;

void setup(void) {
  Serial.begin(9600);
  SPCR |= _BV(SPE);
  i = 0;
  str_display = false;
  SPI.attachInterrupt();
}

ISR(SPI_STC_vect) {
  byte temp = SPDR;
  buff[i++] = temp;
  if (temp == '\r')
    str_display = true;
}

void loop() {
  if (str_display == true) {
    Serial.print("Received by Slave 1: ");
    Serial.println(buff);
    i = 0;
    str_display = false;
  }
  delay(1000);  
}
