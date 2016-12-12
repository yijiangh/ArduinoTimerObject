#include <TimerObject.h>

//STEPPER
#define STEP_PIN  5
#define DIR_PIN   6

TimerObject *timer1 = new TimerObject(300);

void setup()
{
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  //Serial.begin(9600);
  timer1->setOnTimer(&STEPISR);
  timer1->Start();

  digitalWrite(DIR_PIN, 1);
}

bool step_on;
void STEPISR()
{
  step_on = !step_on;
  //Serial.println(timer1->getInterval());
  digitalWrite(STEP_PIN, step_on);
}

void loop()
{
  // put your main code here, to run repeatedly:
  timer1->Update();

  //  compare with "standard" delay method
  //  step_on = !step_on;
  //  digitalWrite(STEP_PIN, step_on);
  //  delayMicroseconds(200);
}
