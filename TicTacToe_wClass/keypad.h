/*********************************************************************
  /This calles will make a 3x3 tactile Keypad
  /
  /Gus Marzoratti MMC
  /*********************************************************************/
class Keypad
{
    // Class Member Variables
    // These are initialized at startup

    //X pins
    int  x1;
    int  x2;
    int  x3;

    //Y pins
    int  y1;
    int  y2;
    int  y3;


  public:

    // Constructor - creates a keyboard object
    // and initializes the Digital Inputs and Outputs
    Keypad (int x1_pin, int x2_pin, int x3_pin, int y1_pin, int y2_pin, int y3_pin)
    {
      x1 = x1_pin;
      x2 = x2_pin;
      x3 = x3_pin;
      y1 = y1_pin;
      y2 = y2_pin;
      y3 = y3_pin;

      startButtons ();

    }


    void startButtons () {

      pinMode(x1, OUTPUT);
      pinMode(x2, OUTPUT);
      pinMode(x3, OUTPUT);

      digitalWrite(x1, HIGH);
      digitalWrite(x2, HIGH);
      digitalWrite(x3, HIGH);

      pinMode(y1, INPUT_PULLUP);
      pinMode(y2, INPUT_PULLUP);
      pinMode(y3, INPUT_PULLUP);
    }


    int getInput() {
      while (1) {
        digitalWrite(2, LOW);
        if (!digitalRead(5)) {
          Serial.println("2,5");
          digitalWrite(2, HIGH);
          return 1;
        }
        digitalWrite(2, LOW);
        if (!digitalRead(6)) {
          Serial.println("2,6");
          digitalWrite(2, HIGH);
          return 4;
        }
        digitalWrite(2, LOW);
        if (!digitalRead(7)) {
          Serial.println("2,7");
          digitalWrite(2, HIGH);
          return 7;
        }
        digitalWrite(2, HIGH);


        digitalWrite(3, LOW);
        if (!digitalRead(5)) {
          Serial.println("3,5");
          digitalWrite(3, HIGH);
          return 2;
        }
        digitalWrite(3, LOW);
        if (!digitalRead(6)) {
          Serial.println("3,6");
          digitalWrite(3, HIGH);
          return 5;
        }
        digitalWrite(3, LOW);
        if (!digitalRead(7)) {
          Serial.println("3,7");
          digitalWrite(3, HIGH);
          return 8;
        }
        digitalWrite(3, HIGH);

        digitalWrite(4, LOW);
        if (!digitalRead(5)) {
          Serial.println("4,5");
          digitalWrite(4, HIGH);
          return 3;
        }
        digitalWrite(4, LOW);
        if (!digitalRead(6)) {
          Serial.println("4,6");
          digitalWrite(4, HIGH);
          return 6;
        }
        digitalWrite(4, LOW);
        if (!digitalRead(7)) {
          Serial.println("4,7");
          digitalWrite(4, HIGH);
          return 9;
        }
        digitalWrite(4, HIGH);
      }
    }
};




