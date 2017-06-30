#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
int pot = 0;
int duty = 0;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(101.1);
  Serial.begin(9600);
  yield();
}

void loop() {
  pot = analogRead(3);
  duty = (((pot/1024.0)/10)+.1)*4096;
  pwm.setPWM(0, 0, duty);
}
