#include "Flasher.h"

// create flasher objects
Flasher led1(12, 100, 400);
Flasher led2(13, 350, 350);

void setup()
{

}

void loop()
{
  //update the flashers
  led1.Update();
  led2.Update();
}
