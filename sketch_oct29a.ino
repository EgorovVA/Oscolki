#include <TroykaThermometer.h>

#define WIFI_SERIAL    Serial1

bool flag_prosh = true;
uint8_t i = 0; 
TroykaThermometer thermometer(A1);
void setup()
{
 
  
  WIFI_SERIAL.begin(9600);
  Serial.begin(9600);
}
 
void loop()
{

  
 



  
thermometer.read();
int ololo = int(thermometer.getTemperatureC());
Serial.print(ololo);
Serial.print("\r\n");
int ol = ololo/10;
int olo = ololo%10;
  WIFI_SERIAL.write(48+ol);
WIFI_SERIAL.write(48+olo);
  WIFI_SERIAL.write("\r\n");
 i+=8;
  delay(1000);
      
}
