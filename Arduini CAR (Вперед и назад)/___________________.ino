int ENA=3; 
int IN1=8;  
int IN2=9;
int ENB=2; 
int IN3=10;  
int IN4=11;
void setup()
{

 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);  
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
}
void loop()
{  
 digitalWrite(ENA, 1000);  digitalWrite(ENB, 1000);  
 digitalWrite(IN1,LOW); digitalWrite(IN3,LOW);
 digitalWrite(IN2,HIGH) ;digitalWrite(IN4,HIGH);
 delay(1000);   delay(1000); 
 
 digitalWrite(IN1,HIGH); digitalWrite(IN3,HIGH);
 digitalWrite(IN2,LOW); digitalWrite(IN4,LOW);
 delay(1000); delay(1000);
}

