#include <Wire.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#define sensor x=6
#define sensor1 y=10
int sensor;
int sensor1;
int sensorValue = 0;             
int servoPin = 9; 
int i = 0; 

Servo servo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
       pinMode(sensor, INPUT);
  pinMode(sensor1,INPUT);
      servo.attach(servoPin); 
       lcd.begin(16,2);
       lcd.setCursor(0,0);
      
}
void set()
{    lcd.clear();
  lcd.print("  I AM FULL,EMPTY ME");
   for (int positionCounter = 0; positionCounter < 25; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
  for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
}

void defaul()
{
    lcd.clear();
  lcd.setCursor(0,0); lcd.print("FEED ME!");
}

void loop()
{
       //sensorValue = analogRead(sensor1);
       int sensorValue=digitalRead(sensor1);
       //int senread1 = digitalRead(sensor);
 if(digitalRead(sensor)==HIGH)
       {
        set();
     
       }
       else
       {
        defaul();
      
       }
 if(sensorValue ==LOW)
  {
     if(digitalRead(sensor)==HIGH)
       {
        set();
     
       }
       else
       {
        defaul();
      
       }
    for (int i = 0; i<=180; i++)
    {
      servo.write(i); 
      delay(15);
      if(digitalRead(sensor1) == HIGH)
      {
      
        servo.write(i);
        delay(3000); 
           if(digitalRead(sensor)==HIGH)
       {
        set();
     
       }
       else
       {
        defaul();
      
       }
      }
    }
   
    for (int i = 180; i>=0; i--)
    {
      servo.write(i);
      delay(15);
      if(digitalRead(sensor1) ==LOW)
      {
      
        servo.write(i);
        delay(3000);
           if(digitalRead(sensor)==HIGH)
       {
        set();
     
       }
       else
       {
        defaul();
      
       }
       
      }
    }
  }
 if(digitalRead(sensor)==HIGH)
       {
        set();
     
       }
       else
       {
        defaul();
      
       }
delay(1000);
}
