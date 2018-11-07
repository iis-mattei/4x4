#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <TCS34725_Color_Sensor.h>

#define TCAADDR 0x70
#define CSLAddr 2
#define CSRAddr 5
#define CSCAddr 4

class 4x4Sensors {
	public :
		char getColorRight();
		char getColorLeft();
		char getColorCenter();
	private :
		Adafruit_TCS34725 colorSensorL, colorSensorR, colorSensorC;
}