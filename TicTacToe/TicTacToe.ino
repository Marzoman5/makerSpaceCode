
  char board [9] = {49,50,51,52,53,54,55,56,57};
  int input;
  int player = 1;
  int p;

  #include "button_input.h"
#include "tic_tac_toe_functions.h"


void setup() {
  Serial.begin(9600);
  startButtons ();  
}

void loop() 
{
  
printBoard();
CheckWinner();
getInput();

}

void getInputKeyBoard()
{
  if (player == 1)
  {
    Serial.println("Player 1, select square");
  }

  if (player == 2)
  {
    Serial.println("Player 2, select square");
  }
  
while (!Serial.available())
{
delay(50);
}
input = Serial.parseInt();
if (player == 1) 
{
  board[input-1] = 88;
  player = 2;
}
else
{
  board[input-1] = 79;
  player = 1;
}
}


