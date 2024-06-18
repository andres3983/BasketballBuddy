#include <stdbool.h>
#include <LiquidCrystal.h>

#define trigPin 13
#define echoPin 12
//#define LED_PIN 8
#define LED_PIN_2 7
#define buttonPin 11
#define button_Pin2 8

int buttonState = 0;
int prevbuttonState = 0;


int button_State2 = 0;
int prevbuttonState2 = 1;

const int rs = 4, en = 5, d4 = 3, d5 = 2, d6 = 10, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float count_shot = 0;
float made_shot = 0;
float field_pct = 0;
float toll = 0.05;
float normal_z = 0;

int shot = 0;
int score = 0;

int time = 60;

void setup() {
  
  //LCD display
  lcd.begin(16, 2);
  lcd.clear();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Shot Tracker");
  lcd.setCursor(0, 1);
  lcd.print("Field Goal:");  
  lcd.setCursor(12, 1);
  lcd.print(made_shot, 0);
  lcd.setCursor(13, 1);
  lcd.print("-");
  lcd.setCursor(14, 1);
  lcd.print(count_shot, 0);
  lcd.setCursor(15, 1);

  //Defines pins for ultrasonic sensor 
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

  //LED part
  //pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  //Buttons 
  pinMode(buttonPin, INPUT);
  pinMode(button_Pin2, INPUT_PULLUP);
}

void loop() {

  //Defines duration/distance 
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) /29.1;
  
  if (distance < 5) {
    tone(9,400 , 100);
}
  if (distance > 5 and distance <= 12) {
    noTone(9);
  }
delay(50);

//LED distance when it turns on 
  if (distance < 5) {
    digitalWrite(7, HIGH);
    delayMicroseconds(10);
    digitalWrite(8, LOW);
    delayMicroseconds(10);
  }
   else {
    digitalWrite(8, HIGH);
    delayMicroseconds(10);
    digitalWrite(7, LOW);
    delayMicroseconds(10);
  }

  //F.G. % calc & tracking shots
  if (distance < 5) {
    made_shot++;      
    delay(500);
  }

  if (distance < 5 or distance < 15){
    count_shot++;
    delay(500);
  }

  if (made_shot == 1 and count_shot == 1) {
     lcd.setCursor(13, 0); 
     lcd.print('100%');
  }
  else {
    field_pct = 0;
    }
    
//LCD display
  if (made_shot <= 10 and made_shot >= 0) {
    lcd.setCursor(12, 1);
    lcd.print(made_shot, 0);
    lcd.setCursor(13, 1);
    lcd.print("-");
    lcd.setCursor(14, 1);
    lcd.print(count_shot, 0);
    } 
  else if(made_shot <= 100 and made_shot >= 10) {       
    lcd.setCursor(11, 1);
    lcd.print(made_shot, 0);
    lcd.setCursor(13, 1);
    lcd.print("-");
    lcd.setCursor(14, 1);                                       
    lcd.print(count_shot, 0);
    } 
  else {
    lcd.setCursor(12, 1);
    lcd.print(made_shot, 0);
    lcd.setCursor(13, 1);
    lcd.print("-");
    lcd.setCursor(14, 1);
    lcd.print(count_shot, 0);
    }
    
  int field_percentage = made_shot / count_shot * 100;  

  if (field_percentage == 100) {
    lcd.setCursor(14, 0);
    lcd.print('100%'); 
  }
  lcd.setCursor(15, 0); 
  lcd.print('%');                                    
  lcd.setCursor(13, 0);
  lcd.print(field_percentage, 1);

  //Button1 -RESET
  buttonState = digitalRead(buttonPin);
  if (buttonState != prevbuttonState) {
    Serial.println("button pressed");
    made_shot = 0;
    count_shot = 0;
    field_pct = 0;
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print('RESET');
    delay(1000);
    lcd.clear();
    lcd.begin(16,2);
    lcd.clear();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Shot Tracker");
    lcd.setCursor(0, 1);
    lcd.print("Field Goal:");  
    lcd.setCursor(12, 1);
    lcd.print(made_shot, 0);
    lcd.setCursor(13, 1);
    lcd.print("-");
    lcd.setCursor(14, 1);
    lcd.print(count_shot, 0);
    lcd.setCursor(15, 1);
    }

    button_State2 = digitalRead(button_Pin2);

    if (button_State2 == LOW){
      Serial.println('button2 pressed');
      time = 60;
      shot = 0;
      score = 0;
      made_shot = 0;
      count_shot = 0;
      field_pct = 0;
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Next game");
      delay(1000);
      lcd.clear();
      lcd.begin(16,2);
      lcd.setCursor(0,0);
      lcd.print("Shots in 30");
      lcd.setCursor(0,1);
      lcd.print("Time:");
      lcd.setCursor(8, 1);
      lcd.print("Shots:");

      //Arduino UNO doesen`t have enough RAM 

      while (time != 0) {
        time--;
        delay(1000);
      }

      lcd.setCursor(12, 1);
      lcd.print(made_shot, 0);
      lcd.setCursor(13, 1);
      lcd.print("-");
      lcd.setCursor(14, 1);
      lcd.print(count_shot, 0);
      lcd.setCursor(15, 1);
      }
      if (time == 0) {
        Serial.println("Game ended");
        lcd.clear();
        lcd.begin(16,2);
        lcd.setCursor(0,1);
        lcd.print('End');
      
      } 
}

//Add more "game modes in the future?..."
  


