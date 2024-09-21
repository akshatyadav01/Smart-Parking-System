#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

Servo motr;
int pos = 0;



int counter = 10;
const int trig1 = 7;
const int echo1 = 6;
const int trig2 = 4;
const int echo2 = 3;
long dur1;
int d1 = 40;
long dur2;
int d2;


void setup() {
  // put your setup code here, to run once:
  //servo motor
  motr.attach(5);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  Serial.begin(9600);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  //lcd
  lcd.begin(16, 2);
  motr.write(0);

  //lcd.clear()
  //delay(ms)
  //red
  pinMode(A0, OUTPUT);
  //green
  pinMode(A1, OUTPUT);
  //blue
  pinMode(A2, OUTPUT);
  digitalWrite(A0, HIGH);
}

void loop() {
  //lcd.setCursor(0,0 )
  // put your main code here, to run repeatedly:
  //lcd display
  lcd.clear();
  if (counter == 0) {
    lcd.print("Parking is full");
  } 
  else {
    lcd.print(" FREE SPACE FOR");
    lcd.setCursor(0, 1);
    lcd.print("  PARKING:- ");
    lcd.setCursor(12, 1);
    lcd.print(counter);

    //BLUetooth module open/close:
    if (Serial.available() > 0) {
      if (Serial.read() == "1") {
        open();
      }
      if (Serial.read() == "2") {
        close();
      }
    }
    //sensor 1
    digitalWrite(trig1, LOW);
    delayMicroseconds(2);
    digitalWrite(trig1, HIGH);
    delayMicroseconds(10);
    dur1 = pulseIn(echo1, HIGH);
    d1 = dur1 * 0.034 / 20;
    //distance at entry
    if (d1 < 5) {

      open();
    }
    delay(100);
    digitalWrite(trig2, LOW);
    delayMicroseconds(2);
    digitalWrite(trig2, HIGH);
    delayMicroseconds(10);
    dur2 = pulseIn(echo2, HIGH);
    d2 = dur2 * 0.034 / 20;
    if (d2 < 5) {
      close();
    }
  }
}


void open() {
  for (pos = 0; pos <= 90; pos += 1) {
    motr.write(pos);
    delay(20);
  }
  digitalWrite(A0, LOW);
  digitalWrite(A2, HIGH);
  Serial.println("Entry");
  delay(5000);
  digitalWrite(A0, HIGH);
  digitalWrite(A2, LOW);

  counter -= 1;
  for (pos = 90; pos >= 0; pos -= 1) {
    motr.write(pos);
    delay(20);
  }
}
void close() {
  for (pos = 0; pos <= 90; pos += 1) {
    motr.write(pos);
    delay(20);
  }
  digitalWrite(A0, LOW);
  digitalWrite(A2, HIGH);
  delay(5000);
  digitalWrite(A0, HIGH);
  digitalWrite(A2, LOW);
  counter += 1;
  for (pos = 90; pos >= 0; pos -= 1) {
    motr.write(pos);
    delay(20);
  }
  Serial.println("Exit");
  delay(3000);
}
