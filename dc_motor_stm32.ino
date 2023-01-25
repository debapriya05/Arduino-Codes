/*const int motorpin=PB0;
  const int motorpin2=PB1;
  void setup()
  {
  pinMode(motorpin,OUTPUT);
  pinMode(motorpin2,OUTPUT);
  }
  void loop()
  {
  digitalWrite(motorpin,HIGH);
  digitalWrite(motorpin2,LOW);


  delay(5000);

  digitalWrite(motorpin,LOW);
  digitalWrite(motorpin2,LOW);


  delay(5000);


  digitalWrite(motorpin,LOW);
  digitalWrite(motorpin2,HIGH);


  delay(5000);

  digitalWrite(motorpin,LOW);
  digitalWrite(motorpin2,LOW);


  delay(5000);

  }*/
#include<Keypad.h>
#include <LiquidCrystal.h> // include the LCD library

const int motorpin = PB0;
const int motorpin2 = PB1;
const int rs = PB11, en = PB10, d4 = PA4, d5 = PA3, d6 = PA2, d7 = PA1; //STM32 Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Initialize the LCD
const int i = 4; //four rows
const int j = 3; //three columns

char keys[i][j] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte pin_rows[i] = {PB9, PB8, PB7, PB6}; //connect to the row pinouts of the keypad
byte pin_column[j] = {PB5, PB4, PB3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, i, j );

void setup()
{
  int runmotorR;
  pinMode(motorpin, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  lcd.begin(16, 2);//Defining 16*2 LCD
  lcd.setCursor(0, 0);
  lcd.print("Press key");

}

void loop()
{
  char key = keypad.getKey();

  //lcd.print("Press key");
  lcd.setCursor(0, 1);
  if (key )
  {
    runRight();
    lcd.clear(); //Clear the screen
  }
}
void runRight()
{
  digitalWrite(PB0, HIGH);
  digitalWrite(PB1, LOW);
  delay(1000); //wait for four secounds
  digitalWrite(PB0, LOW);
  digitalWrite(PB1, LOW);

  while(millis()<900)
  {
    digitalWrite(PB0,LOW);
    digitalWrite(PB1,HIGH);
  }
  digitalWrite(PB0, HIGH);
  digitalWrite(PB1, LOW);
  delay(1000); //wait for four secounds
  digitalWrite(PB0, LOW);
  
}
