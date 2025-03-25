
#include <Wire.h> // i2c 통신을 위한 기본 라이브러리 밑의 헤더파일에도 포함되있다.
// 하지만 명시하기위해서 사용한다.
#include <LiquidCrystal_I2C.h>
기본 아두이노에서는 이런 기능이 포함되어있지않다. 그래서 stetch >> library 관리 >> LuquidCrystal_I2C를 다운로드 받아야한다.


#define TRIG 13 
#define ECHO 12 


LiquidCrystal_I2C lcd(0x27, 16, 2); // 주소, 열, 행
// 클래스 이름(인자1, 인자2,인자3)
void setup(){
  lcd.init();          // LCD 초기화
  lcd.backlight();     // 백라이트 켜기
  lcd.print("LCD init");
  delay(2000);         // 2초 대기
  lcd.clear();         // LCD 화면 지우기
  
  pinMode(TRIG,OUTPUT);
  pinMode (ECHO, INPUT);
}

void loop(){
  lcd.setCursor(0, 0); // 올바른 위치로 커서 설정 (열 0, 행 0)
  // lcd.print("Hello, World!"); // "Hello, World!" 출력
  long duration , distance;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2); // delay(2)
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration / 58.2;

  lcd.print("Distance : ");
  lcd.setCursor(0, 1); 
  lcd.print(distance); // 개행 X
  lcd.print(" CM" );

  delay(1000);
  lcd.clear();  // 화면을 지운 후
  	
  // for(int position = 0; position < 16; position++){
  //   lcd.scrollDisplayLeft();  // 화면 왼쪽으로 스크롤 NonArgument :  인자가 없는 함수이다.
  //   delay(250);               // 150ms 대기
  // }
  
}
