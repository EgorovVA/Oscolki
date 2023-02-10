#define WIFI_SERIAL Serial1
#define BUTTON_PIN1  3
#define BUTTON_PIN2  4
#define BUTTON_PIN3  5
#define BUTTON_PIN4  6
bool flag_prosh = true;
uint8_t i = 0;
void setup(){

WIFI_SERIAL.begin(9600);
Serial.begin(9600);
pinMode(BUTTON_PIN1, INPUT);
pinMode(BUTTON_PIN2, INPUT);
pinMode(BUTTON_PIN3, INPUT);
pinMode(BUTTON_PIN4, INPUT);
}

void loop(){

  Serial.print("Sign: ");
  
int buttonState1 = digitalRead(BUTTON_PIN1);
int x = digitalRead(BUTTON_PIN1)-1;
if (x == -1){
  (x) + 2;
}
 if(x == 0){
  (x);
  }

int buttonState2 = digitalRead(BUTTON_PIN2);
int y = digitalRead(BUTTON_PIN2)-1;
if (y == -1){
  (y) + 2;
}
 if(y == 0){
  (y);
  }

int buttonState3 = digitalRead(BUTTON_PIN3);
int z = digitalRead(BUTTON_PIN3)-1;
if (z == -1){
  (z) + 2;
}
 if(z == 0){
  (z);
  }


int buttonState4 = digitalRead(BUTTON_PIN4);
int k = digitalRead(BUTTON_PIN4)-1;
if (k == -1){
  (k) + 2;
}
 if(k == 0){
  (k);
  }
String m ;

if (x == 0){
  m +="0";

  }else{m +="1";}
if (y == 0){
  m +="0";

  }else{m +="1";}
  if (z == 0){
  m +="0";

  }else{m +="1";}
  if (k == 0){
  m +="0";

  }else{m +="1";}
   Serial.print(m);     
Serial.println(" ");
              
delay(500);

if(flag_prosh){
  
WIFI_SERIAL.write("AT\r\n");
delay(1000);
WIFI_SERIAL.write("AT+CWMODE=3\r\n");
delay(3000);
WIFI_SERIAL.write("AT+CWJAP_CUR=");
WIFI_SERIAL.write(34);
WIFI_SERIAL.write("NARFU2021");
WIFI_SERIAL.write(",");
WIFI_SERIAL.write(34);
WIFI_SERIAL.write("NARFU2021!");
WIFI_SERIAL.write(34);
WIFI_SERIAL.write("\r\n");
delay(15000);
WIFI_SERIAL.write("AT+CIPSTART=");
WIFI_SERIAL.write(34);
WIFI_SERIAL.write("TCP");
WIFI_SERIAL.write(34);
WIFI_SERIAL.write(",");
WIFI_SERIAL.write(34);
WIFI_SERIAL.write("172.28.133.117");
WIFI_SERIAL.write(34);
WIFI_SERIAL.write(",65432\r\n");
delay(10000);
WIFI_SERIAL.write("AT+CIPMODE=1\r\n");
delay(5000);
WIFI_SERIAL.write("AT+CIPSEND\r\n");
delay(5000);
flag_prosh=false;
}
 if(!flag_prosh){

  WIFI_SERIAL.write(m[0]);
  WIFI_SERIAL.write(m[1]);
  WIFI_SERIAL.write(m[2]);
  WIFI_SERIAL.write(m[3]);
  WIFI_SERIAL.write("\r\n");
  delay(500);
  }

}
