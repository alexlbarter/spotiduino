#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.home();
  Serial.begin(9600);
  
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    char letter = Serial.read();
    if(letter != '\n') {
      lcd.write(letter);
    }
  }

  int button1 = digitalRead(11);
  int button2 = digitalRead(12);
  int button3 = digitalRead(13);

  if (button1 == HIGH) {
    lcd.clear();
    lcd.print("Button 1");
  } else if (button2 == HIGH) {
    lcd.clear();
    lcd.print("Button 2"); 
  } else if (button3 == HIGH) {
    lcd.clear();
    lcd.print("Button 3");
  }

}
