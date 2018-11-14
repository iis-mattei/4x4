4x4Sensors::4x4Sensors() {
	colorSensorL = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X);
	colorSensorR = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X);
	colorSensorC = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X);	
	Wire.begin();
}
char 4x4Sensors::getColorLeft() {
	tcaSelect(CSLAddr);
	delay(10);
	return ReadColorSensor(colorSensorL);
}
char 4x4Sensors::getColorRight() {
	tcaSelect(CSRAddr);
	delay(10);
	return ReadColorSensor(colorSensorR);
}
char 4x4Sensors::getColorCenter() {
	tcaSelect(CSCAddr);
	delay(10);
	return ReadColorSensor(colorSensorC);
}

void tcaSelect(uint8_t addr) {
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << addr);
  Wire.endTransmission();
}

char getColorID(int colors[]) {
    const int RED=0, GREEN=1, BLUE=2;
    const char COL_RED='r', COL_GREEN='g', COL_WHITE='w', COL_BLACK='b', COL_SILVER='s', COL_UNKNOWN='u';
    const int Red_min[] = {230, 40, 10} , Red_max[] = {350,90, 70};
    const int White_min[] = {130, 130, 130}, White_max[] = {350 ,350, 350};
    const int Green_min[] = {40, 140, 30}, Green_max[] = {90, 250, 100};
    const int Black_min[] = {0, 0, 0}, Black_max[] = {75, 75, 75};
    const int Silver_min[] = {350, 350, 350}, Silver_max[] = {1000, 1000, 1000};
	// se i valori sono compresi nel cuboide di uno dei colori ....
	if (colors[RED]>=Red_min[RED] && colors[RED]<Red_max[RED] &&
	colors[GREEN]>=Red_min[GREEN] && colors[GREEN]<Red_max[GREEN] &&
	colors[BLUE]>=Red_min[BLUE] && colors[BLUE]<Red_max[BLUE]) 
		return COL_RED; 
	else if (colors[RED]>=White_min[RED] && colors[RED]<White_max[RED] &&
	colors[GREEN]>=White_min[GREEN] && colors[GREEN]<White_max[GREEN] &&
	colors[BLUE]>=White_min[BLUE] && colors[BLUE]<White_max[BLUE]) 
		return COL_WHITE;   
	else if (colors[RED]>=Green_min[RED] && colors[RED]<Green_max[RED] &&
	colors[GREEN]>=Green_min[GREEN] && colors[GREEN]<Green_max[GREEN] &&
	colors[BLUE]>=Green_min[BLUE] && colors[BLUE]<Green_max[BLUE]) 
		return COL_GREEN; 
	else if (colors[RED]>=Black_min[RED] && colors[RED]<Black_max[RED] &&
	colors[GREEN]>=Black_min[GREEN] && colors[GREEN]<Black_max[GREEN] &&
	colors[BLUE]>=Black_min[BLUE] && colors[BLUE]<Black_max[BLUE]) 
		return COL_BLACK; 
	else if (colors[RED]>=Silver_min[RED] && colors[RED]<Silver_max[RED] &&
	colors[GREEN]>=Silver_min[GREEN] && colors[GREEN]<Silver_max[GREEN] &&
	colors[BLUE]>=Silver_min[BLUE] && colors[BLUE]<Silver_max[BLUE]) 
		return COL_SILVER; 
	else
		return COL_UNKNOWN; 
}

char ReadColorSensor(String tag, Adafruit_TCS34725& colorSensor) {
  uint16_t clear, red, green, blue;
  int colors[3];

  colorSensor.getRawData(&red, &green, &blue, &clear);
  colors[0] = red;
  colors[1] = green;
  colors[2] = blue;
  return getColorID(colors);
}
