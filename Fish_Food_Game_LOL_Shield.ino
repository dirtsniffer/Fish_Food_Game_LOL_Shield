//Maker   www.lledapps.com

#include <Charliplexing.h> //LOL library
#include<Wire.h>//gyro
const int MPU=0x68;  // gyro. I2C address of the MPU-6050

int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int x = 6;  
int y = 4;  
int OLDx = 1;  
int OLDy = 1;
int cxMax = 13;  
int cyMax = 8 ; 
int cx, cy;

void setup() {
  Wire.begin();  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(115200);
  
  LedSign::Init();
  LoadTheBoard();
}

void loop(){   
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)

  cy = AcX;  
  cx = AcY;
  OLDx = x;  
  OLDy = y;
  
if (cx < cxMax){ cx = cxMax; x = x+1;}
  else if (cx > cxMax) {cx = cxMax;x = x-1;}
  if (cy > cyMax) {cy = cyMax; y = y+1;}
  else if (cy < cyMax) {cy = cyMax; y = y-1;} 
  if (y > 8) y = 8;
  if (x > 13) x = 13; 
  if (y < 0) y = 1;
  if (x < 0) x = 1;

  LedSign::Set(x,y,1);
  LedSign::Set(OLDx,OLDy,0);
  delay(100);
}

void LoadTheBoard(){
  LedSign::Set(0,4,1);
  LedSign::Set(1,5,1);
  LedSign::Set(1,3,1);
  LedSign::Set(2,2,1);
  LedSign::Set(2,6,1);
  LedSign::Set(3,1,1);
  LedSign::Set(3,7,1);
  LedSign::Set(3,3,1);
  LedSign::Set(4,1,1);
  LedSign::Set(4,7,1);
  LedSign::Set(5,1,1);
  LedSign::Set(5,7,1);
  LedSign::Set(6,1,1);
  LedSign::Set(6,7,1);
  LedSign::Set(7,2,1);
  LedSign::Set(7,6,1);
  LedSign::Set(8,3,1);
  LedSign::Set(8,5,1);
  LedSign::Set(8,4,1);
  LedSign::Set(8,4,1);
  LedSign::Set(10,2,1);
  LedSign::Set(10,6,1);
  LedSign::Set(9,3,1);
  LedSign::Set(9,5,1);  
  LedSign::Set(11,2,1);
  LedSign::Set(11,6,1);
  LedSign::Set(11,1,1);
  LedSign::Set(11,7,1);
  LedSign::Set(11,3,1);
  LedSign::Set(11,5,1);
  LedSign::Set(11,4,1);
  LedSign::Set(11,4,1);
}
