int val;
// подключите пины контроллера к цифровым пинам Arduino
// первый двигатель
int ENA=3; 
int IN1=8;  
int IN2=9;
int ENB=2; 
int IN3=10;  
int IN4=11;

void setup()
{
// инициализируем все пины для управления двигателями как outputs
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
 
void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    if (val == 'W') // При получении символа "W" движемся вперед
    {
      digitalWrite(IN1, HIGH); digitalWrite(IN3, HIGH);
      digitalWrite(IN2, LOW);  digitalWrite(IN4, LOW);
      analogWrite(ENA, 200);   analogWrite(ENB, 200);
    }
    if (val == 'S') // При получении символа "S" движемся назад
    {
      digitalWrite(IN1, LOW); digitalWrite(IN3, LOW);
      digitalWrite(IN2, HIGH);  digitalWrite(IN4, HIGH);
      analogWrite(ENA, 200); analogWrite(ENB, 200);
    }
    if (val == 'A'){ // При получении символа "A" движемся влево
    digitalWrite(IN1,  HIGH);   digitalWrite(IN3, LOW);
    digitalWrite(IN2, LOW);  digitalWrite(IN4,  HIGH);
     analogWrite(ENA, 200);   analogWrite(ENB, 200);
    }
    if (val == 'D'){ // При получении символа "D" движемся вправо
     digitalWrite(IN1, LOW);  digitalWrite(IN3, HIGH);
    digitalWrite(IN2, HIGH);  digitalWrite(IN4, LOW);
    analogWrite(ENA, 200);  analogWrite(ENB, 200);
    }
    //---------- Стоп режим —-------------
    // При отпускании клавиш движения в программе в порт шлется "T"

    if ( val == 'T') // При нажатии клавиши "T"
    {
      // Выводы ENABLE притянуты к минусу, моторы не работают
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }    
  }
}

