#include <stdio.h>
// #include<Vector.h>
// #include<Pair.h>
// #include<string.h>
int s[9] = { 12, 4, 6, 11, 5, 3, 10, 7, 8 };
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
// class Piece{
//   public:
//   Pair<int,int>pos;
//   char*name;
//   Piece(char*name,Pair<int,int>pos){
//     name=name;
//     pos=pos;
//   }
//   // bool queenMove()
//   // {

//   // }
//   // bool camelMove()
//   // {

//   // }
//   // bool horseMove(){

//   // }
// };
Sensor S[9];
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
        moved = S[i].piece;
        // S[i].piece=NULL;
        initialPos = (S[i].x * 3) + S[i].y;
      }
      if (S[i].fval == LOW) {
        finalPos = (S[i].x * 3) + S[i].y;
        S[i].piece = moved;

      }
      times = 0;
    }
    S[i].pval = S[i].fval;
  }
}
bool valid() {
  if (moved == 'E') {
    return validElephant();
  } else if (moved == 'H') {
    return validHorse();
  } else if (moved == 'C') {
    return validCamel();
  }
}


bool validElephant() {
  int xf = finalPos / 3, xi = initialPos / 3, yf = finalPos % 3, yi = initialPos % 3;
  int onlyOneChanged = 0;
  if (times == 0) {
    // Serial.print(xi);
    // Serial.print(",");
    // Serial.print(yi);
    // Serial.print("-");

    // Serial.print(xf);
    // Serial.print(",");
    // Serial.print(yf);
    times = 1;
    if (xf - xi == 0 && yi - yf != 0)
      return true;
    if (xf - xi != 0 && yf - yi == 0)
      return true;
    return false;
  }
}

bool validCamel() {
  int xf = finalPos / 3, xi = initialPos / 3, yf = finalPos % 3, yi = initialPos % 3;
  if (times == 0) {
    // Serial.print(initialPos / 3);
    // Serial.print(",");
    // Serial.print(initialPos % 3);
    // Serial.print("-");

    // Serial.print(finalPos / 3);
    // Serial.print(",");
    // Serial.print(finalPos % 3);
    times = 1;
    if (abs(xf - xi) == abs(yi - yf))
      return true;
    return false;
  }
}

bool validHorse() {
  int xf = finalPos / 3, xi = initialPos / 3, yf = finalPos % 3, yi = initialPos % 3;
  if (times == 0) {
    // Serial.print(initialPos / 3);
    // Serial.print(",");
    // Serial.print(initialPos % 3);
    // Serial.print("-");

    // Serial.print(finalPos / 3);
    // Serial.print(",");
    // Serial.print(finalPos % 3);
    times = 1;
    if ((abs(xf - xi) == 1 && abs(yf - yi) == 2) || (abs(xf - xi) == 2 && abs(yf - yi) == 1))
      return true;
    return false;
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
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < 9; i++) {
    S[i].pin = s[i];
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
  if (times == 0) {
    if (initialPos != finalPos) {
      Serial.println();
      Serial.print(moved);
      Serial.print(" moved ");
      Serial.print(initialPos);
      Serial.print("-");
      Serial.print(finalPos);
      Serial.println();
      if (valid())  
      {
        Serial.print("true");
        digitalWrite(13, HIGH);
        delay(100);
        digitalWrite(13, LOW);
      } else  //Serial.print("false");
      {
        digitalWrite(2, HIGH);
        delay(100);
        digitalWrite(2, LOW);
      }
      times = 1;
    }
  }
}