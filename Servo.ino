#include <Servo.h>

Servo servo1, servo2;
const int servo1Pin = 5;
const int servo2Pin = 6;
int servo1Angle = 90;
int servo2Angle = 90;

const int ledPin1 = 9;  // 페트병 LED 핀 번호
const int ledPin2 = 10; // 캔 LED 핀 번호
const int ledPin3 = 11; // 유리병 LED 핀 번호

void setup() {
  Serial.begin(9600);
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.println("Setup complete");
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    Serial.print("Received data: ");
    Serial.println(data);  // 디버깅을 위한 출력
  
    if(data == "X"){
      digitalWrite(ledPin1, LOW);  // 모든 LED 끄기
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      servo1Angle = 70;
      servo2Angle = 90;
      Serial.println("모든 LED 끄기, 1번 서보모터 70도, 2번 서보모터 90도");
    } else if (data == "캔") {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);  
      digitalWrite(ledPin3, HIGH);   // 캔 LED 켜기
      servo1Angle = 180;
      servo2Angle = 90;
      Serial.println("캔 LED 켜기, 1번 서보모터 180도, 2번 서보모터 90도");
    } else if (data == "유리병") {
      digitalWrite(ledPin1, LOW);  
      digitalWrite(ledPin2, HIGH);   // 유리병 LED 켜기
      digitalWrite(ledPin3, LOW);
      servo1Angle = 45;
      servo2Angle = 180;
      Serial.println("유리병 LED 켜기, 1번 서보모터 45도, 2번 서보모터 180도");
    } else if (data == "페트병") {
      digitalWrite(ledPin1, HIGH);   // 페트병 LED 켜기
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW); 
      servo1Angle = 60;
      servo2Angle = 60;
      Serial.println("페트병 LED 켜기, 1번 서보모터 60도, 2번 서보모터 60도");
    }
    servo1.write(servo1Angle);  // 서보모터 각도 변경
    servo2.write(servo2Angle);
  }
}
