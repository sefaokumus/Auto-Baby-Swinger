#include <Servo.h> 

class Sweeper
{
  Servo servo;              // the servo
  int pos;                  // current servo position 
  int increment;            // increment to move for each interval
  int  updateInterval;      // interval between updates
  unsigned long lastUpdate; // last update of position
  bool isAttached;
  int attachPin;
  
public: 
  Sweeper(int interval)
  {
    updateInterval = interval;
    increment = 1;
  }
  
  void Attach(int pin)
  {
    attachPin = pin;
  }
  
  void Detach()
  {
    attachPin = -1;
  }

  void increaseInterval()
  {
    updateInterval+=10;
    Serial.println(updateInterval);
  }
  void decreaseInterval()
  {
    if(updateInterval > 5)
      updateInterval-=10;
      
        Serial.println(updateInterval);
  }
  
  void Update()
  {
    if(attachPin != -1)
    {
      if(!isAttached)
      {
        servo.attach(attachPin);
        Serial.println("attached");
        isAttached= true;
        delay(1000);
      } 
      if((millis() - lastUpdate) > updateInterval)  // time to update
      {
        lastUpdate = millis();
        pos += increment;
        servo.write(pos);
        Serial.println(pos);
        if ((pos >= 180) || (pos <= 0)) // end of sweep
        {
          // reverse direction
          increment = -increment;
        }
      }
      
    }
    else
      servo.detach();
  }
};

Sweeper sweeper1(10);
void setup() {
  Serial.begin(9600);
    sweeper1.Attach(9);
}

void loop() {
    sweeper1.Update();
}
