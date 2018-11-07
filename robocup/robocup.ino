#include <4x4Motors>
#include <4x4Sensors>

void setup() {
  Serial.begin(9600);
  Serial.println("Avvio del robot...");
  4x4Motors motors = new 4x4Motors();
  4x4Sensors sensors = new 4x4Sensors();
}

void loop() {
  motors.travel(30, 50);
}
