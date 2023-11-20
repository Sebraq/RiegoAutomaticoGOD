#include "MyLibrary.h"
Info hum;

void setup() {
  hum.Mode(2,3,4,12,11);
}

void loop() {
  hum.SensorHumedad();
  hum.LEDS(2,3);
  hum.NivelDeAgua(4);
  hum.bomba();
}
