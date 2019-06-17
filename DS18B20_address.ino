
#include <OneWire.h>
#include <FS.h>
// ROM = 28 D8 B4 79 97 6 3 A
//ROM = 28 4F CE 79 97 6 3 EE
// Based on the OneWire library example

OneWire ds(33);  //data wire connected to GPIO15

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  byte i;
  byte addr[8];
  
  if (!ds.search(addr)) {
    Serial.println(" No more addresses.");
    Serial.println();
    ds.reset_search();
    delay(250);
    return;
  }
  Serial.print(" ROM =");
  for (i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
  }
}
