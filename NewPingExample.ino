// ---------------------------------------------------------------------------
// MAX DISTANCE 수정 전
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
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
