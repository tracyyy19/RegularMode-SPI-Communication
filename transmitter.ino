#include <SPI.h>

const int slaveSelect1 = 10;  // Slave 1
const int slaveSelect2 = 9;   // Slave 2 (newly added)

void setup() {
  pinMode(slaveSelect1, OUTPUT);
  pinMode(slaveSelect2, OUTPUT);
  digitalWrite(slaveSelect1, HIGH);
  digitalWrite(slaveSelect2, HIGH);
  Serial.begin(9600);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop() {
  communicateWithSlave(slaveSelect1);
  delay(500);
  communicateWithSlave(slaveSelect2);
  delay(1000);
}

void communicateWithSlave(int slaveSelectPin) {
  digitalWrite(slaveSelectPin, LOW);

  int i = 0;
  char c[50] = "Lab 1 Complete";
  while (c[i] != '\0') {
    SPI.transfer(c[i]);
    i++;
  }
  Serial.print("Master Sends: ");
  Serial.println(c);
  SPI.transfer('\r');
  digitalWrite(slaveSelectPin, HIGH);
}
