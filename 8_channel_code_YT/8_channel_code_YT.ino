//Motor pins
#define rmf 2 //IN1 //AIN2
#define rmb 4 //IN2 //AIN1
#define lmf 5 //IN3 //BIN1
#define lmb 6 //IN4 //BIN2
//EnA and EnB
#define rms 3  //EnA //PWMA
#define lms 9  //EnB //PWMB

//Declation of Necessary Variables
#define sensorNumber 8
int threshold[sensorNumber] = { 300, 300, 300, 300, 300, 300, 300, 300};
int position[sensorNumber] = { 10, 20, 30, 40, 50, 60, 70, 80 };
int sensor_value[sensorNumber];
int sum_on_sensor;
int sensor_wight;
float error, previous_error;
int center_position = 45;
int turn_value = 0;
float line_position;
float integral;
float derivative;

float ki = 0.01, kp = 7, kd = 10;
int base_speed = 250;  //need to be adjusted


//Necessary Delays for tuning the robot
#define stop_time 50  
#define turn_speed 200
#define turn_delay 150
//Button and LED Pins
#define button1 10
#define button2 11
#define led 13

void setup() {
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(rms, OUTPUT);
  pinMode(lms, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(button1) == 0) PID_FOLLOW();
  if (digitalRead(button2) == 0) analog_value_check();
}