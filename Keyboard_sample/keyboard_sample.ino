#include "Keyboard.h"
#include <SoftwareSerial.h>

const int button1 = 2;     // the number of the pushbutton pin
const int button2 = 3;

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;

void setup() {
  // Serial.begin(57600);
  // Keyboard.begin();
  // initialize the pushbutton pin as an input:
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == LOW) {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('`');
    delay(500);
    Keyboard.releaseAll();
  }
  if (buttonState2 == LOW) {
    // pressでは押しっぱなしの判定
    // printでは文字列を一気に打てる
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print("notepad");  // launch notepad
    Keyboard.press(KEY_RETURN);
    delay(300);
  }
}
