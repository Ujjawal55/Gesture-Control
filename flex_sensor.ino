#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

int littlefinger = A0;
int ringfinger = A1;
int middlefinger = A2;
int indexfinger = A3;
float maxlittle = 60;
float minlittle = 33;
float maxring = 70;
float minring = 36;
float maxmiddle = 35;
float minmiddle = 20;
float maxindex = 70;
float minindex = 36;


int value;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(littlefinger, INPUT);
  pinMode(ringfinger, INPUT);
  pinMode(middlefinger, INPUT);
  pinMode(indexfinger, INPUT);
  Serial.begin(9600);

}

void loop() {
  //put your main code here, to run repeatedly:

  float littlefingervalue = analogRead(littlefinger);
  float ringfingervalue = analogRead(ringfinger);
  float middlefingervalue = analogRead(middlefinger);
  float indexfingervalue = analogRead(indexfinger);
  float littlefingerdeci = (littlefingervalue - minlittle) / (maxlittle - minlittle);

  // Serial.print("little finger: ");
  // Serial.println(littlefingerdeci);
  // Serial.print("littlefingervalue:  ");
  // Serial.println(littlefingervalue);

  float ringfingerdeci = (ringfingervalue - minring) / (maxring - minring);

  // Serial.print("ringfingervalue: ");
  // Serial.println(ringfingervalue);
  // Serial.print("ringerfingerdeci: ");
  // Serial.println(ringfingerdeci);

  float middlefingerdeci = (middlefingervalue - minmiddle) / (maxmiddle - minmiddle);

  // Serial.print("middlefingervalue: ");
  // Serial.println(middlefingervalue);
  // Serial.print("middlefingerdeci: ");
  // Serial.println(middlefingerdeci);

  float indexfingerdeci = (indexfingervalue - minindex) / (maxindex - minindex);

  // Serial.print("indexfinger: ");
  // Serial.println(indexfingervalue);
  // Serial.print("indexfingerdeci: ");
  // Serial.println(indexfingerdeci); 
  func(littlefingerdeci, ringfingerdeci, middlefingerdeci, indexfingerdeci);
  


  
  delay(1000);

  // delay(2000);

  

}

void func(float l, float r, float m, float i) {

  while(l < 0.5 && r < 0.5 && m < 0.5 && i < 0.5) {

    Serial.println("inside the while loop");
    int count = 0;

    float littlefingervalue = analogRead(littlefinger);
    delay(1);
    float ringfingervalue = analogRead(ringfinger);
    delay(1);
    float middlefingervalue = analogRead(middlefinger);
    delay(1);
    float indexfingervalue = analogRead(indexfinger);

    
    float lv = (littlefingervalue - minlittle) / (maxlittle - minlittle);
    if (lv > 0.5) {count++;}
    float rv = (ringfingervalue - minring) / (maxring - minring);
    if (rv > 0.5) {count++;}
    float mv = (middlefingervalue - minmiddle) / (maxmiddle - minmiddle);
    if (mv > 0.5) {count++;}
    float iv = (indexfingervalue - minindex) / (maxindex - minindex);
    if (iv > 0.5) {count++;}

    if (count == 1) {
      oneFingerGesture(iv, mv, rv, lv);

    } else if (count == 2) {
      twoFingerGesture(iv, mv, rv, lv);

    } else if (count == 3) {
      threeFingerGesture(iv, mv, rv, lv);

    } else if (count == 4) {
      fourFingerGesture(iv, mv, rv, lv);

    }else {
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("no move");
      delay(100);
    }


  }
}

void oneFingerGesture(float iv, float mv, float rv, float lv) {

  if (iv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("medicine time");
    Serial.println("index finger bend only");
    delay(100);

  } else if (mv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("yes");
    // Serial.print("middle finger bend only");
    delay(100);

  } else if (rv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("emergency");
    delay(100);

  } else if (lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("rest room");
    delay(100);
  }

}
void twoFingerGesture(float iv, float mv, float rv, float lv) {
  if (iv > 0.5 && mv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("headache");
    delay(100);

  } else if (iv > 0.5 && rv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("stomach ache");
    delay(100);

  } else if (iv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("feeling nauseous");
    delay(100);

  } else if (mv > 0.5 && rv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("hungry");
    delay(100);

  } else if (mv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("How are you?");
    delay(100);

  } else if (rv > 0.5 &&  lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("I'm fine");
    delay(100);

  }
}

void threeFingerGesture(float iv, float mv, float rv, float lv) {
  
  if (iv > 0.5 && mv > 0.5 > rv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("feeling unwell");
    delay(100);

  } else if (iv > 0.5 && mv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("thank you");
    delay(100);

  } else if (iv > 0.5 && rv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("");
    delay(100);

  } else if (mv > 0.5 && rv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("You are welcome");
    delay(100);
  }
}

void fourFingerGesture(float iv, float mv, float rv, float lv) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("hello everyone");
    delay(100);
 }