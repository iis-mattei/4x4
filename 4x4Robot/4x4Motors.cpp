4x4Motors::4x4Motors() {
	
}

4x4Motors::travel(int speed, float dist) {
	evshield.bank_b.motorRunRotations(SH_Motor_Both, SH_Direction_Reverse, speed, ((double) (dist / COEFFCM)), SH_Completion_Wait_For, SH_Next_Action_Brake);
}

4x4Motors::travel(int speed) {
	evshield.bank_b.motorRunRotations(SH_Motor_Both, SH_Direction_Reverse, speed);
}

// curva a destra dir=-1, curva a sinistra dir=1
4x4Motors::spin(int speed, int dir, float arc) {
	double rounds = (arc*2.50)/360;
	evshield.bank_b.motorRunRotations(SH_Motor_1, SH_Direction_Forward, (dir*speed), rounds,  SH_Completion_Wait_For, SH_Next_Action_Brake);
    evshield.bank_b.motorRunRotations(SH_Motor_2, SH_Direction_Reverse, ((dir)*(-speed)), rounds,  SH_Completion_Dont_Wait, SH_Next_Action_Brake);
}

// curva a destra dir=-1, curva a sinistra dir=1
4x4Motors::spin(int speed, int dir) {
	evshield.bank_b.motorRunRotations(SH_Motor_1, SH_Direction_Forward, (dir*speed));
    evshield.bank_b.motorRunRotations(SH_Motor_2, SH_Direction_Reverse, ((dir)*(-speed)));
}

4x4Motors::arc(int ext_speed, float radius, float arc) {
	
}

4x4Motors::arc(int ext_speed, float radius) {
	
}

4x4Motors::stop() {
    evshield.bank_b.motorStop(SH_Motor_Both, SH_Next_Action_Brake);
}