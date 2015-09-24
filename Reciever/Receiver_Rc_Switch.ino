#include <RCSwitch.h>

#define data 2
#define clock 3

RCSwitch mySwitch = RCSwitch();

void setup() {
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  mySwitch.enableReceive(4);
  mySwitch.setProtocol(2);
  shiftOut(data, clock, LSBFIRST, B00000000);
}

void loop() {
  if (mySwitch.available()) {
    unsigned long res = mySwitch.getReceivedValue();
    if(res != 1337) {
      shiftOut(data, clock, MSBFIRST, res);
    } else {
      shiftOut(data, clock, MSBFIRST, B00000000);
    }
    mySwitch.resetAvailable();
  }
}
