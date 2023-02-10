#define WIFI_SERIAL    Serial1
#include <TroykaThermometer.h>
#include "MPU6050.h"
MPU6050 mpu;
bool flag_prosh = true;
uint8_t i = 0; 
TroykaThermometer thermometer(A0);
void setup()
{
 Wire.begin();
  Serial.begin(9600);
  mpu.initialize();     // запускаем датчик

 
  
  WIFI_SERIAL.begin(9600);
  Serial.begin(9600);
}float angle_old=0;
 
void loop()
{
 



  
  if(flag_prosh){
    WIFI_SERIAL.write("AT\r\n");
    delay(10000);
    WIFI_SERIAL.write("AT+CWMODE=3\r\n");
    
    delay(10000);
      WIFI_SERIAL.write("AT+CWJAP_CUR=");
      WIFI_SERIAL.write(34);
      WIFI_SERIAL.write("NARFU2021");
      WIFI_SERIAL.write(",");
      WIFI_SERIAL.write(34);
      WIFI_SERIAL.write("NARFU2021!");
      WIFI_SERIAL.write(34);
      WIFI_SERIAL.write("\r\n");

     delay(10000);

      WIFI_SERIAL.write("AT+CIPSTART=");
      WIFI_SERIAL.write(34);
      WIFI_SERIAL.write("TCP");
      WIFI_SERIAL.write(34);
      WIFI_SERIAL.write(",");
      WIFI_SERIAL.write(34);
      WIFI_SERIAL.write("172.28.133.117");
      WIFI_SERIAL.write(34);
      WIFI_SERIAL.write(",65500\r\n");

     delay(10000);
      WIFI_SERIAL.write("AT+CIPMODE=1\r\n");

     delay(10000);
      WIFI_SERIAL.write("AT+CIPSEND\r\n");

     delay(1000);
     flag_prosh=false;   
  }
 if(!flag_prosh){
int16_t ax = mpu.getAccelerationX();  // ускорение по оси Х
  // стандартный диапазон: +-2g
  ax = constrain(ax, -16384, 16384);    // ограничиваем +-1g
  float angle = ax / 16384.0;           // переводим в +-1.0
  // и в угол через арксинус
  if (angle < 0) angle = 90 - degrees(acos(angle));
  else angle = degrees(acos(-angle)) - 90;
  
 
  delay(1000);
   


 int8_t d=abs(angle_old-angle);
 
  if (d >= 45){
  WIFI_SERIAL.write("hight");}


   if (d<45&&d>=20){
   WIFI_SERIAL.write("mid");}

  
   if (d<20){
   WIFI_SERIAL.write("low");}
 Serial.println(d);   
 angle_old=angle;
 
}
}
