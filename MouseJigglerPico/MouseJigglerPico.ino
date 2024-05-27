#include <Mouse.h>
void setup() {

  Mouse.begin();
  pinMode(BOOTSEL, INPUT_PULLUP);
  delay(5000);
}

bool mouseEnabled = false;  // Flag to track the state of mouse movement
unsigned long lastDebounceTime = 0;  // Debounce timer
unsigned long debounceDelay = 50;  // Debounce delay in milliseconds

void move(const int val =5){
    int cnt =0 ;
    
    while(cnt != val){
        Mouse.move(cnt++, 0, 0);
        delay(100);
    }
    while(cnt != 0){
        Mouse.move(-(cnt--), 0, 0);
        delay(100);
    }
    while(cnt != val){
        Mouse.move(0, cnt++, 0);
        delay(100);
    }
    
    while(cnt != 0){
        Mouse.move(0, -(cnt--), 0);
        delay(100);
    }

}


void loop() {
  static bool lastButtonState = HIGH; 
  bool buttonState = digitalRead(BOOTSEL);

  if ((buttonState != lastButtonState) && (buttonState == LOW)) {
      mouseEnabled = !mouseEnabled;  // Toggle the mouse movement state
  }
  lastButtonState = buttonState;  // Save the current button state

  if (mouseEnabled) {
    move(5);
  }

}
