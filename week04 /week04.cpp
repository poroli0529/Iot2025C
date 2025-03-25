#include <Wire.h> // i2c 통신을 위한 기본 라이브러리 밑의 헤더파일에도 포함되있다.
// 하지만 명시하기위해서 사용한다.
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // 주소, 열, 행

void setup(){
  lcd.init();          // LCD 초기화
  lcd.backlight();     // 백라이트 켜기
  lcd.print("LCD init");
  delay(2000);         // 2초 대기
  lcd.clear();         // LCD 화면 지우기
}

void loop(){
  lcd.setCursor(15, 0); // 처음 커서 위치 설정 
  lcd.print("한국어테스트"); // "Hello, World!" 출력

    long duration , distance;
  
    digitalWrite(TRIG, LOW);
  delayMicroseconds(2); // delay(2)
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration / 58.2;
   lcd.print("\nDistance : ");
   lcd.print(distance); // 개행 X
   lcd.println(" CM" );
   delay(1000);
   
  for(int position = 0; position < 16; position++){
    lcd.scrollDisplayLeft();  // 화면 왼쪽으로 스크롤
    delay(150);               // 150ms 대기
  }
}
