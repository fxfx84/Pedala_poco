#include <Servo.h>

#define MAX_SIGNAL 2000
#define MIN_SIGNAL 1000
#define MOTOR_PIN 12
int throttlePin = 0;
int brakePin = 4;
int brake=500;
float throttle=100;
float throttleF=100;
int throttlePWM=60;
int maxthrottle=125;
int minthrottle=50;
float K=0.005;
Servo motor;

void setup() {
  Serial.begin(9600);
  pinMode(brakePin, INPUT_PULLUP);           // set pin to input
  Serial.println("Program begin...");
 // Serial.println("This program will calibrate the ESC.");
 // delay(1000); 
  motor.attach(MOTOR_PIN,MIN_SIGNAL,MAX_SIGNAL);
motor.write(179);

delay(500); 
  // Send min output
  //Serial.println("Sending minimum output");
  //motor.writeMicroseconds(MIN_SIGNAL);
  motor.write(10);
  delay(500); 
   motor.write(60);
  delay(500); 
}

void loop() { 
   int brake = digitalRead(brakePin);
   throttle = analogRead(throttlePin);
  if (brake==HIGH){ 
  
  if(throttleF<throttle){
  throttleF=(throttleF*(1-K)+throttle*K);
  
  }
  else
  {
   throttleF=throttle;
  }
throttlePWM = map(throttleF, 0, 1023, 60, maxthrottle);
motor.write(throttlePWM);
//motor.write(179);
   // Serial.println(throttleF);
  }
  else
  {
    throttlePWM = minthrottle;
    motor.write(throttle);

  }
 Serial.println(throttlePWM);
  //Serial.println(brake);     
    
  
}
