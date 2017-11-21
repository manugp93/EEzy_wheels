#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // TX | RX
Servo griper;
Servo base;
Servo horizontal;
Servo vertical;
char val;
int b=80;
int c=50;
int d=90;
void setup() {
griper.attach(A5);
base.attach(A4);
horizontal.attach(A3);
vertical.attach(A2);
griper.write(15);
base.write(80);
horizontal.write(50);
vertical.write(90);
Serial.begin(9600);
BTSerial.begin(9600);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);

}

void loop() {
  if(BTSerial.available())
val=BTSerial.read();
Serial.print(val);
switch(val)
{
  case 'q':
  //alante
  analogWrite(5,255);
  analogWrite(6,255);
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(7,0);
  digitalWrite(8,1);
  Serial.print("alante");
  break;
  case 'a':
  //paro
  analogWrite(5,0);
  analogWrite(6,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
  Serial.print("para");
  break;
  case 'r':
  //atras
  analogWrite(5,255);
  analogWrite(6,255);
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(7,1);
  digitalWrite(8,0);
  break;
   case 'w':
   //izq
  analogWrite(5,255);
  analogWrite(6,0);
  digitalWrite(3,0);
  digitalWrite(4,1);
  break;
  case 'e':
  //der  
  analogWrite(5,0);
  analogWrite(6,255);
  digitalWrite(7,0);
  digitalWrite(8,1);
  break;
  case 'o':
  b=b+1;
  if(b>180)b=180;
  base.write(b);
  delay(20);
  break;
  case 'p':
   b=b-1;
  if(b<3)b=3;
  base.write(b);
  delay(20);
  break;
   case 'i':
  c=c+1;
  if(c>140)c=140;
  horizontal.write(c);
  delay(20);
  break;
  case 'u':
   c=c-1;
  if(c<50)c=50;
  horizontal.write(c);
  delay(20);
  break;
   case 't':
  d=d+1;
  if(d>120)d=120;
  vertical.write(d);
  delay(20);
  break;
  case 'y':
   d=d-1;
  if(d<50)d=50;
  vertical.write(d);
  delay(20);
  break;
  case 'd':
  griper.write(90);
  break;
  case 's':
  griper.write(15);
   break;
} 
}
