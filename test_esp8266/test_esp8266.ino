#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
          
//#include <SimpleTimer.h>

 
SimpleTimer timer;
char auth[] = "C39HJavn-IoVsrHbYA7ea3IqlKhGauFL";

char ssid[] = "Wifi Cua Tuan";
char pass[] = "";

float t=0;
float h=0;

void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass,"iot.htpro.vn", 8080);
    
    timer.setInterval(1000, sendUptime);
}

void sendUptime()
{
  h = h+0.845 ;
  t = t+1.23 ;
  if (h>=100){
    h=0;
  }
  if(t>=100){
    t=1;
  }
  Serial.println("Ket qua do duoc:\n");
  Serial.print("Do Am = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("Nhiet do = ");
  Serial.print(t); 
  Serial.print("°C \n");
  Blynk.virtualWrite(V6, t);
  Blynk.virtualWrite(V5, h);
  
}

void loop()
{
  Blynk.run();
  timer.run();
    

}
