#include <Adafruit_PWMServoDriver.h>

#define frequency 107.29

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  pwm.begin();
  pwm.setPWMFreq(frequency);
  yield();
  pwm.setPWM(0, 0, getDutyPeriod(0));
  pwm.setPWM(1, 0, getDutyPeriod(0));
}

float getDutyPeriod(float period_ms) {
  return (period_ms/((1.0/frequency)*1000))*4096.0;
}

void loop() {
    delay(3000);
    pwm.setPWM(0, 0, getDutyPeriod(1.406));
    pwm.setPWM(1, 0, getDutyPeriod(1.406));
    delay(3000);
   
    float dutym = 1.406;
    float dutys = 1.000;
    
    while(dutym <= 1.980){
      pwm.setPWM(0, 0, getDutyPeriod(dutym));
      dutym += .0025;
      delay(50);
    }
    pwm.setPWM(0, 0, getDutyPeriod(0));
    
    while(dutys <= 1.980){
      pwm.setPWM(1, 0, getDutyPeriod(dutys));
      dutys += .0025;
      delay(25);
    }
    pwm.setPWM(1, 0, getDutyPeriod(0));
}
