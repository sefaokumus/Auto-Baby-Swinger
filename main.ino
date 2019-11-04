#include <IRremote.h>
#include "Swinger.h"

int RECV_PIN = 11;
int SERVO_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;
int previousCode =0;

#define BUTTON_1 0xFFA25D
#define BUTTON_2 0xFF629D
#define BUTTON_3 0xFFE21D
#define BUTTON_4 0xFF22DD
#define BUTTON_5 0xFF02FD
#define BUTTON_6 0xFFC23D
#define BUTTON_7 0xFFE01F
#define BUTTON_8 0xFFA857
#define BUTTON_9 0xFF906F
#define BUTTON_STAR 0xFF6897
#define BUTTON_0 0xFF9867
#define BUTTON_DASH 0xFFB04F
#define UP_ARROW 0xFF18E7
#define LEFT_ARROW 0xFF10EF
#define BUTTON_SELECT 0xFF38C7
#define RIGHT_ARROW 0xFF5AA5
#define DOWN_ARROW 0xFF4AB5

int state = LOW ;
Swinger swinger1(10);
void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); 
  Serial.println("Enabled IRin");
  swinger1.Attach(9);
}

void loop() {
  if (irrecv.decode(&results)) {
    
    int code = results.value;
    Serial.println(code);
    if(code == -1)
      code = previousCode;
    
    switch (code) {
      case BUTTON_1:
        Serial.println("Pressed Button 1"); // for debuging
        state = LOW;
        swinger1.setInterval(3,0);
        state = HIGH;
        break;
      case BUTTON_2:
        Serial.println("Pressed Button 2"); // for debuging
        state = LOW;
        swinger1.setInterval(5,3);
        state = HIGH;
        break;
      case BUTTON_3:
        Serial.println("Pressed Button 3"); // for debuging
        state = LOW;
        swinger1.setInterval(5,5);
        state = HIGH;
        break;
      case BUTTON_4:
        Serial.println("Pressed Button 4"); // for debuging
        state = LOW;
        swinger1.setInterval(7,0);
        state = HIGH;
        break;
      case BUTTON_5:
        Serial.println("Pressed Button 5"); // for debuging
        state = LOW;
        swinger1.setInterval(7,5);
        state = HIGH;
        break;
      case BUTTON_6:
        Serial.println("Pressed Button 6"); // for debuging
        state = LOW;
        swinger1.setInterval(9,0);
        state = HIGH;
        break;
      case BUTTON_7:
        Serial.println("Pressed Button 7"); // for debuging
        state = LOW;
        swinger1.setInterval(9,5);
        state = HIGH;
        break;
      case BUTTON_8:
        Serial.println("Pressed Button 8"); // for debuging
        state = LOW;
        swinger1.setInterval(11,0);
        state = HIGH;
        break;
      case BUTTON_9:
        Serial.println("Pressed Button 9"); // for debuging
        state = LOW;
        swinger1.setInterval(11,5);
        state = HIGH;
        break;
      case BUTTON_STAR:
        Serial.println("Pressed Button *"); // for debuging
        state = HIGH;
        break;
      case BUTTON_0:
        Serial.println("Pressed Button 0"); // for debuging
        break;
      case BUTTON_DASH:
        Serial.println("Pressed Button #"); // for debuging
        state = LOW;
        break;
      case UP_ARROW:
        Serial.println("Pressed Button UP"); // for debuging
        state = LOW;
        swinger1.increaseInterval();
        state = HIGH;
        break;
      case LEFT_ARROW:
        Serial.println("Pressed Button LEFT"); // for debuging
        break;
      case BUTTON_SELECT:
        Serial.println("Pressed Button OK"); // for debuging
        break;
      case RIGHT_ARROW:
        Serial.println("Pressed Button Right"); // for debuging
        break;
      case DOWN_ARROW:
        Serial.println("Pressed Button DOWN"); // for debuging
        state = LOW;
        swinger1.decreaseInterval();
        state = HIGH;
        break;
      default:
        Serial.println(code);
        break;
    }

    previousCode = code;
    irrecv.resume(); // Receive the next value
  }
  if(state == HIGH)
      swinger1.Attach(SERVO_PIN);
  else
    swinger1.Detach();
    
    swinger1.Update();
    
 
}
