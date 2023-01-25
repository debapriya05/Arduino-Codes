const int pinout = PC13; // declare pinout with int data type and pin value
char inputdata = 0;  //Variable for storing received data

void setup()
{
  
    Serial1.begin(9600);                      //Sets the baud rate for bluetooth pins 
    Serial1.print("BLUETOOTH WITH STM32\n");                     
    pinMode(pinout, OUTPUT);                  //Sets digital pin PA0 as output pin for led
}

void loop()
{
   if(Serial1.available() > 0)      // Send data only when you receive data:
   {
      inputdata = Serial1.read();        //Read the incoming data & store into data
           
      if(inputdata == 'a') 
      {
         digitalWrite(pinout, HIGH); 
         Serial1.print("LED OFF\n");  
      }
         
      else if(inputdata == 'b')  
      {      
         digitalWrite(pinout, LOW);  
         Serial1.print("LED ON\n");     
      }
   }
}
