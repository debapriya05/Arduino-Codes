       
void setup() {
  // put your setup code here, to run once:
                                                                                                 
  pinMode(A0,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(A2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(A1)==HIGH)
  {
    tone(A2,1000);
    //delay(1000);
    digitalWrite(A0,HIGH);
  }
  else
  {
    noTone(A2);
    //delay(1000);
    digitalWrite(A0,LOW);
  }
   // delay(1000);
}
