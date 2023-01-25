#define echoPin PB4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin PB5 //attach pin D3 Arduino to pin Trig of HC-SR04

#include <LiquidCrystal.h> 

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

const int rs = PB11, en = PB10, d4 = PA4, d5 = PA3, d6 = PA2, d7 = PA1; //STM32 Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Initialize the LCD

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(distance);
  delay(1000);
  lcd.clear();
  //lcd.setCursor(15,1);
  //lcd.print(" cm");
}
