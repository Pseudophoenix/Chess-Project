#include<stdio.h>
#include<Vector.h>
#include<Pair.h>
#include<string.h>
// // String name="Abc";
// // using namespace std;
// // int s[4]={12,11,10,9};
// // int a[20];
// struct B{
//     Pair<char*,int>pos;
//     char name;
// };
typedef struct B sB;
struct W{
    Pair<char*,int>pos;
    char name;
};
typedef struct W sW;
void initialPosition(Vector<Pair<char*,Pair<char*,int>>>&Black,Vector<Pair<char*,Pair<char*,int>>>&White){
  Black.push_back({"Pawn1",{"A",1}});
  Black.push_back({"Pawn2",{"B",1}});
  Black.push_back({"Pawn3",{"C",1}});
  Black.push_back({"Pawn4",{"D",1}});
  Black.push_back({"Pawn5",{"E",1}});
  Black.push_back({"Pawn6",{"F",1}});
  Black.push_back({"Pawn7",{"G",1}});
  Black.push_back({"Pawn8",{"H",1}});

  Black.push_back({"Elephant1",{"A",0}});
  Black.push_back({"Horse1",{"B",0}});
  Black.push_back({"Camel1",{"C",0}});
  Black.push_back({"Queen",{"D",0}});
  Black.push_back({"King",{"E",0}});
  Black.push_back({"Camel2",{"F",0}});
  Black.push_back({"Horse2",{"G",0}});
  Black.push_back({"Elephant2",{"H",0}});

  White.push_back({"Pawn1",{"A",7}});
  White.push_back({"Pawn2",{"B",7}});
  White.push_back({"Pawn3",{"C",7}});
  White.push_back({"Pawn4",{"D",7}});
  White.push_back({"Pawn5",{"E",7}});
  White.push_back({"Pawn6",{"F",7}});
  White.push_back({"Pawn7",{"G",7}});
  White.push_back({"Pawn8",{"H",7}});

  White.push_back({"Elephant1",{"A",8}});
  White.push_back({"Horse1",{"B",8}});
  White.push_back({"Camel1",{"C",8}});
  White.push_back({"Queen",{"D",8}});
  White.push_back({"King",{"E",8}});
  White.push_back({"Camel2",{"F",8}});
  White.push_back({"Horse2",{"G",8}});
  White.push_back({"Elephant2",{"H",8}});
  
  return;
}
// Vector<Pair<char*,Pair<int,int>>>Pieces;
// // //int s[14]={13,12,11,10,9,8,7,6,5,4,3,2,1,0};
// // int nv[4];
// // int pv[4]={0,0,0,0};
// // //int v[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
// // void readSensors()
// // {
// // for(int i=0;i<4;i++)
// //   nv[i] = digitalRead(s[i]);
// // }
// // void setup() {
// //   // declare the ledPin as an OUTPUT:
// //   for(int i=0;i<4;i++)
// //   pinMode(s[i],INPUT);

// //   /*
// //   pinMode(s[7*1+2],INPUT);
// //   pinMode(s[7*1+3],INPUT);
// //   pinMode(s[7*1+4],INPUT);
// //   pinMode(s[7*1+5],INPUT);
// //   pinMode(s[7*1+6],INPUT);
// //  */
// //    readSensors();
// //     for (int i = 0; i < 4; i++) {
// //         pv[i] = nv[i];
// //     }
// //   Serial.begin(9600);

// // Pieces.push_back({"Horse1",{0,1}});
// // Serial.print(Pieces[0].val_1);
// // }

// // void loop() {
// // readSensors();
// // // int arr[3];
// // //   Vector<int>vector(arr);
// //   // Vector<Vector<char>> vector(arr);
// // // vector.push_back(32);
// //     // Serial.print(vector[0]);
// //   for(int i=0;i<4;i++)
// // {
// //     if(pv[i]!=nv[i])
// //   {	
// //     Serial.print(i);
// //     Serial.print(",");
// //     Serial.print(nv[i]);
// //   	Serial.println();
// //   }
// // }

// // // Serial.print(H.val_1);
// // // Serial.print(H.val_2.val_1);
// // // Serial.print(H.val_2.val_2);
// // for(int i=0;i<4;i++)
// //   pv[i] = nv[i];
// //   delay(500);
// // }

// int s[6]={11,10,9,8,7,6};
int s[9]={37,33,35,31,23,25,27,29};
//int s[14]={13,12,11,10,9,8,7,6,5,4,3,2,1,0};
int nv[9];
int pv[9]={0,0,0,0,0,0,0,0,0};
//int v[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void readSensors()
{
for(int i=0;i<9;i++)
  nv[i] = digitalRead(s[i]);
}
void setup() {
  // declare the ledPin as an OUTPUT:
  for(int i=0;i<9;i++)
  pinMode(s[i],INPUT);
  Vector<Pair<char*,Pair<char*,int>>>White;
  Vector<Pair<char*,Pair<char*,int>>>Black;
  // sB Barr;
  // sW Warr=(struct);
  initialPosition(White,Black);
  /*
  pinMode(s[7*1+2],INPUT);
  pinMode(s[7*1+3],INPUT);
  pinMode(s[7*1+4],INPUT);
  pinMode(s[7*1+5],INPUT);
  pinMode(s[7*1+6],INPUT);
 */
   readSensors();
    for (int i = 0; i < 9; i++) {
        pv[i] = nv[i];
    }
  Serial.begin(9600);
}

void loop() {
readSensors();

  for(int i=0;i<9;i++)
    if(pv[i]!=nv[i])
  {	
    Serial.print(i);
    Serial.print(",");
    Serial.print(nv[i]);
    Serial.print("   |   ");
  	// Serial.println();
  }
    

for(int i=0;i<9;i++)
  pv[i] = nv[i];
  delay(200);
}