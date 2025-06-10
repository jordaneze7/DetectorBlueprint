#include <LiquidCrystal.h>

int buzzerPin = 4;
const int trigPin = 6;
const int echoPin = 5;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
  //lcd.setCursor(0, 0);
  //lcd.print("Area is Empty");
}

void loop() {
   // put your main code here, to run repeatedly:
long duration, inches, cm;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);

Serial.print(inches);
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(100);

if(cm <= 10)
{
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("WARNING!");
  lcd.setCursor(2, 1);
  lcd.print("Foreign Body");
  digitalWrite(buzzerPin, HIGH);
}
if(cm > 10)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Area is Empty");
  digitalWrite(buzzerPin, LOW);
}
}


long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
