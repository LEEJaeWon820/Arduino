// ---------------------------------------------------------------------------
// MAX DISTANCE 수정 전
// ---------------------------------------------------------------------------

#include <NewPing.h> // Newping 라이브러리를 추가

#define TRIGGER_PIN  2  // 트리거 핀을 2번으로 정의
#define ECHO_PIN     3  // 에코 핀을 3번으로 정의
#define MAX_DISTANCE 100 // 최대 거리를 100으로 정의 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
//TriggerPin과 EchoPin과 최대제한거리의 값을 선언합니다.

void setup() {
  Serial.begin(115200); // 115200의 속도로 시작
}

void loop() {
  delay(50);                     
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());  // 센서 거리를 'cm'로 계산된 값을 출력한다.
  Serial.println("cm");
}

// ---------------------------------------------------------------------------
// MAXDISTANCE 수정 후
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  2  
#define ECHO_PIN     3  
#define MAX_DISTANCE 100 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(115200); 
}

void loop() {
  float distance = 0.0;
  delay(50);                     
  distance = sonar.ping_cm();
  if (distance ==0) distance = MAX_DISTANCE; // 만약 거리가 0이라면 거리를 최대 거리로 정의
  Serial.print("Ping: ");
  Serial.print(distance); 
  Serial.println("cm");
}
