#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    accelerometerZ, sensorAccelerometer)
#pragma config(Sensor, in3,    accelerometerY, sensorAccelerometer)
#pragma config(Sensor, in4,    accelerometerX, sensorAccelerometer)
#pragma config(Sensor, in5,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in6,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, dgtl1,  sonarInput,     sensorSONAR_cm)
#pragma config(Sensor, dgtl8,  disableAuton,   sensorDigitalIn)
#pragma config(Sensor, dgtl9,  flag1,          sensorDigitalIn)
#pragma config(Sensor, dgtl10, flag2,          sensorDigitalIn)
#pragma config(Sensor, dgtl11, flag3,          sensorDigitalIn)
#pragma config(Sensor, dgtl12, flag4,          sensorDigitalIn)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_5,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           rightBaseOne,  tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightBaseTwo,  tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port3,           rightBaseThree, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightTopLift,  tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_4)
#pragma config(Motor,  port5,           rightBottomLift, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393_MC29, openLoop, encoderPort, I2C_5)
#pragma config(Motor,  port7,           leftBottomLift, tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port8,           leftBaseThree, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           leftBaseTwo,   tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port10,          leftBaseOne,   tmotorVex393_HBridge, openLoop, reversed)

void Goforward (int speed, int time){
	motor[rightBaseOne] = speed;
	motor[rightBaseThree] = speed;
	motor[leftBaseOne] = speed;
	motor[leftBaseThree] = speed;
	wait1Msec(time);
}
//void Turn (int speed,int reverse, int time){
		//motor[rightBaseOne] = speed;
	//motor[rightBaseThree] = speed;
	//motor[leftBaseOne] = reverse;
	//motor[leftBaseThree] = reverse;
	//wait1Msec(time);
//}
void Armovement (int speed, int time){
	motor[rightTopLift] = speed;
	motor[rightBottomLift] = speed;
	motor[leftBottomLift] = speed;
	wait1Msec(time);
}
void ClawMovement ( int speed, int time){
	motor[clawMotor] = speed;
	wait1Msec(time);
}
task main()
{
Goforward (127, 1000);
Armovement (127, 1000);
ClawMovement (127, 1000);
//Goforward (-127, 500);
//Turn (-127,-127, 500);
}
