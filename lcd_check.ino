#include <LiquidCrystal.h>

int rs = 6;
int en = 7;
int d4 = 8;
int d5 = 9;
int d6 = 10;
int d7 = 11;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello world");
  delay(1000);
}
