#include <Wire.h>
#include <EVShield.h>

#define DIAMETER 5.6
#define CIRCUMFERENCE 17.6
#define AXIS 15
#define DIFF_AXIS 2.8
#define EXT_AXIS 17.8
#define ROTATIONS_PER_GRADE 0.00689
#define COEFFCM 20.48 	// 360 / (PiGreco * diametro)
#define COEFFSPIN 2.75 	// asse / diametro

class Motors {
	public :
		Motors();
		void travel(int speed, float dist);
		void travel(int speed);
		void spin(int speed, int dir, float arc);
		void spin(int speed, int dir);
		void arc(int ext_speed, float radius, float arc);
		void arc(int ext_speed, float radius);
		void stop();
	private :
		EVShield evshield;
};