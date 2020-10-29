// base values 10-160  thumb = 90
// grab values 165-255 thumb = 160
// pins 5,6  motor1
// pins 9,10 motor2
// pins 7,8  lift
// pins 2,3  grab
// pins 4    base

#include <Servo.h>

Servo base;
Servo grab;
Servo grab2;
int m1=5,m2=6,m3=9,m4=10,l1=7,l2=8;
long unsigned int x=0;
unsigned long int b=0,g=0;

void setup() {
  
  Serial.begin(9600);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  base.attach(4);
  grab.attach(3);
  grab2.attach(2);
  
}
void loop() {
  while (Serial.available()>0)
  { x = Serial.read();
    Serial.println(x);
  }
  if(x==1)
 {
  Serial.println("forward");
  moveforward();  
 }
 if(x==2)
 {
  Serial.println("reverse");
  movereverse();
 }
 if(x==4)
 {
  Serial.println("right");
  moveright();
 }
 if(x==3)
 {
  Serial.println("left");
  moveleft();
 }
 if(x==5)
 {
  Serial.println("stop");
  movestop();
 }
 if(x==6)
 {
  Serial.println("lifting up");
  lift();
 }
 if(x==7)
 {
  Serial.println("stopping lift");
  stoplift();
 }
 if(x==8)
 {
  liftdown();
  Serial.println("lifting down");
 }
 if(x >= 10 && x <= 160)
 {
   base.write(x);
   delay(2);
 }
 if(x >= 165 && x <= 255)
 {
   g = map(x,165,255,0,90);
   grab.write(g);
   grab2.write(g);
   delay(2);   
 }
 
}
//================================stop================================
void movestop()
{ digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}
//==============================forward=====================
void moveforward()
{ 
  delay(100);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
  
}
//===============================reverse=====================
  void movereverse()
{
  delay(100);
  digitalWrite(m2,LOW);
  digitalWrite(m1,HIGH);
  digitalWrite(m4,LOW);
  digitalWrite(m3,HIGH);
  
}
//==================================right===============
void moveright()
{
  delay(100);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m4,LOW);
  digitalWrite(m3,HIGH);
}
//===================================left===============
void moveleft()
{ 
  delay(100);
   digitalWrite(m2,LOW);
  digitalWrite(m1,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
  
}
//=====================================liftstop=============
void stoplift()
{
 delay(50);
 digitalWrite(l1,LOW);
 digitalWrite(l2,LOW);
}
//=====================================lift====================
void lift()
{
  delay(50);
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  
}
//=====================================liftdown================
void liftdown()
{
  delay(50);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
 
}



//===================================END======================
