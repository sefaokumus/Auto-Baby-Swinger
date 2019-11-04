#include <Servo.h> 

class Swinger
{
  Servo servo;              // the servo
  int pos;                  // current servo position 
  int increment;            // increment to move for each interval
  int  updateInterval;      // interval between updates
  int newRoundDelay;        // delay between the sweeps
  unsigned long lastUpdate; // last update of position
  bool isAttached;
  int attachPin;
  
public: 
  Swinger(int interval)
  {
    updateInterval = interval;
    pos = 20;
    increment = 1;
  }
  
  void Attach(int pin)
  {
    attachPin = pin;
  }
  
  void Detach()
  {
    attachPin = -1;
    isAttached = false;
  }

  void setInterval(int val, int delayForNewRound)
  {
    updateInterval = val;
    newRoundDelay = delayForNewRound ==0? 1 : delayForNewRound;
  }

  void increaseInterval()
  {
    if(updateInterval <100)
      updateInterval+=5;
  }
  void decreaseInterval()
  {
    if(updateInterval > 5)
      updateInterval-=5;
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
        delay(100);
      } 
      if((millis() - lastUpdate) > updateInterval)  // time to update
      {
        lastUpdate = millis();
        pos += increment;
        servo.write(pos);
        Serial.println(pos);

        if ((pos >= 180)) {
          increment = -1;
          
        }
        
        if(pos <= 80){
            increment= 1;
        
          if(updateInterval > 3)
          {
              pos = 180;
              delay(50 * newRoundDelay);
          }    
        }
      }
    }
    else{
      servo.write(180);
      delay(500);
      servo.detach();
      
    }
  }
};


