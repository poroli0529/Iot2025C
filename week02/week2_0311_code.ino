// C++ code
//

#define TRIG 13 
#define ECHO 12 
#define green 8
#define red 7
void setup()
{
  Serial.begin(9600);
  // 9600은 속도 낮을 수록 안정적이고 느린 속도 통신,
  // USB포트를 사용하는 시리얼(데이터 통신) 부팅하겠다. 
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
 // 기본 코드에 써져있는 LED_BUILTIN은 우리가 말하는 내장 LED이다.
  pinMode(TRIG,OUTPUT);
  pinMode (ECHO, INPUT);
  
}

void loop()
{
//  digitalWrite(green, HIGH);
//  // digital pin을 신호를 보낸다. 
//  delay(1000); // Wait for 1000 millisecond(s)
//  digitalWrite(green, LOW);
//  delay(1000);
//  digitalWrite(red, HIGH);
//  // digital pin을 신호를 보낸다. 
//  delay(1000); // Wait for 1000 millisecond(s)
//  digitalWrite(red, LOW);
//  delay(1000); // Wait for 1000 millisecond(s)
//  
  
  long duration , distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2); // delay(2)
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH); // echo가 초음파가 돌아와서 ' 1 ' 이 될때까지의 시간을 측정하는 객체이다. 
  
  distance = duration / 58.2;
  Serial.println(duration); // 개행 O
   Serial.print("\nDistance : ");
   Serial.print(distance); // 개행 X
   Serial.println(" CM" );
  
  delay(1000);
  
  if(distance >= 100){
  
   	digitalWrite(red , HIGH);
     delay(1000); 
    digitalWrite(red , LOW);
     delay(1000); 
    digitalWrite(green, LOW);
  }
  else{
    
    digitalWrite(green, HIGH); 
    delay(1000); 
    digitalWrite(green, LOW);
    delay(1000); 
    digitalWrite(red , LOW); 
  }
}
