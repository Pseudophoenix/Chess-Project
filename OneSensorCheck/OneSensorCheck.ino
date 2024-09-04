
#include<stdio.h>
// int s[6]={11,10,9,8,7,6};
int s[1]={12};

//int s[14]={13,12,11,10,9,8,7,6,5,4,3,2,1,0};
int nv[1];
int pv[1]={0};
//int v[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void readSensors()
{
for(int i=0;i<1;i++)
  nv[i] = digitalRead(s[i]);
}
void setup() {
  // declare the ledPin as an OUTPUT:
  for(int i=0;i<1;i++)
  pinMode(s[i],INPUT);
  
  /*
  pinMode(s[7*1+2],INPUT);
  pinMode(s[7*1+3],INPUT);
  pinMode(s[7*1+4],INPUT);
  pinMode(s[7*1+5],INPUT);
  pinMode(s[7*1+6],INPUT);
 */
   readSensors();
    for (int i = 0; i < 1; i++) {
        pv[i] = nv[i];
    }
  Serial.begin(9600);
}

void loop() {
readSensors();

  for(int i=0;i<1;i++)
    if(pv[i]!=nv[i])
  {	
    // Serial.print(i);
    // Serial.print(",");
    Serial.print(nv[i]);
  	Serial.println();
  }
    

for(int i=0;i<1;i++)
  pv[i] = nv[i];
  delay(800);
}
