// Pin connections for Uno and similar:
// Chip pin 1 (/PL)  goes to LATCH (D9)  (or any other pin by changing LATCH below)
// Chip pin 2 (CP)   goes to SCK   (D13)
// Chip pin 9 (Q7)   goes to MISO  (D12)
// Pin connections for Mega2560:
// Chip pin 1 (/PL)  goes to LATCH (D9)  (or any other pin by changing LATCH below)
// Chip pin 2 (CP)   goes to SCK   (D52)
// Chip pin 9 (Q7)   goes to MISO  (D50)

#include <RCSwitch.h>
#include <SPI.h>

const byte LATCH = 9;
byte shift_1;

RCSwitch mySwitch = RCSwitch();

void setup() {
  mySwitch.enableTransmit(46);
  mySwitch.setPulseLength(0); // Was 1
  mySwitch.setProtocol(2); // Was 1
  mySwitch.setRepeatTransmit(1); // Should be 2?
  SPI.begin();
  pinMode(LATCH, OUTPUT);
  digitalWrite(LATCH, HIGH);
}

void loop() {
  digitalWrite(LATCH, LOW);
  digitalWrite(LATCH, HIGH);
  shift_1 = SPI.transfer(0);
  mySwitch.send(shift_1, 24);
}
