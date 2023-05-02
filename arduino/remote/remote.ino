#include <LiquidCrystal.h>

// LCD pins
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

// Button pins
const int b1 = 11, b2 = 12, b3 = 13;


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialise LCD
  lcd.begin(16, 2);
  lcd.home();
  
  // Initialise serial communications
  Serial.begin(9600);
  
  // Initialise buttons
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
}

void loop() {
  // Read data from serial buffer if available
  if(Serial.available() > 0) {
    char letter = Serial.read();
    if(letter != '\n') {
      lcd.write(letter);
    }
  }

  delay(150);

  int b1State = digitalRead(b1);
  int b2State = digitalRead(b2);
  int b3State = digitalRead(b3);


  // Encode state of buttons as 3 bit binary number
  int buttonStates = 0;
  if (b1State == 1) {
    buttonStates = buttonStates + 4;
  }
  if (b2State == 1) {
    buttonStates = buttonStates + 2;
  }
  if (b3State == 1) {
    buttonStates = buttonStates + 1;
  }


  switch (buttonStates) {
    case 4:
      lcd.clear();
      lcd.print("Previous track");
      break;

    case 2:
      lcd.clear();
      lcd.print("Play/pause");
      break;
    
    case 1:
      lcd.clear();
      lcd.print("Next track");
      break;
    
    case 6:
      lcd.clear();
      lcd.print("Volume down");
      break;

    case 3:
      lcd.clear();
      lcd.print("Volume up");
      break;
  }  

}
