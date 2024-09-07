#include <stdio.h>
// #include<Vector.h>
// #include<Pair.h>
// #include<string.h>
int s[9]={12,4,6,11,5,3,10,7,8};
int initialPos;
int finalPos;
char moved;
int times = 0;
class Sensor {
public:
  int pin;
  char piece;
  int x;
  int y;
  int pval;
  int fval;
  Sensor() {
    this->piece = NULL;
    this->fval = 1;
  }
};
Sensor S[3];
void readSensor() {
  for (int i = 0; i < 9; i++) {
    S[i].fval = digitalRead(S[i].pin);
  }
}
void checkDiff() {
  for (int i = 0; i < 9; i++) {
    S[i].fval = digitalRead(S[i].pin);
    if (S[i].pval != S[i].fval) {
      if (S[i].fval == HIGH) {
        moved=S[i].piece;
        initialPos = (S[i].x * 3) + S[i].y;
      }
      if (S[i].fval == LOW) {
        finalPos = (S[i].x * 3) + S[i].y;
        S[i].piece=moved;
      }
      times = 0;
    }
    S[i].pval = S[i].fval;
  }
}
void setup() {
  //  37->A0    36->B0    35->C0
  //  34->A1    33->B1    32->C1
  //  31->A2    30->B2    29->C2

  // 0-12       1-4         2-6
  // 3-11       4-5         5-3
  // 6-10       7-7         8-8

  // H-72
  // C-67
  // E-69

  Serial.begin(9600);
  for (int i = 0; i < 9; i++) {
    S[i].pin =s[i];
    if (i / 3 == 0) {
      S[i].fval = 0;
      switch (i) {
        case 0:
          S[i].piece = 69;
          break;
        case 1:
          S[i].piece = 72;
          break;
        case 2:
          S[i].piece = 67;
          break;
      }
    }
    S[i].x = 0 + i / 3;
    S[i].y = i % 3;
    Serial.print("[");
    if (i % 3 == 0) {
      Serial.print(S[i].piece);
      Serial.print(",");
    }
    Serial.print(S[i].pin);
    Serial.print(",");
    Serial.print(S[i].x);
    Serial.print(",");
    Serial.print(S[i].y);
    Serial.print(",");
    Serial.print(S[i].pval);
    Serial.print("]");
    pinMode(S[i].pin, INPUT);
  }
}
void loop() {
  delay(400);
  readSensor();
  delay(400);
  checkDiff();
  if (times == 0)
    if (initialPos != finalPos) {
      Serial.println();
      Serial.print(moved);
      Serial.print(" moved ");
      Serial.print(initialPos);
      Serial.print("-");
      Serial.print(finalPos);
      Serial.println();
      times = 1;
    }
}