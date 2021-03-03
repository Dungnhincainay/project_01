
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include <SimpleTimer.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "8TytNxie25BVKYolzRm_yLjF1vAGbrCA";

char ssid[] = "Wifi Cua Tuan";
char pass[] = "";

float t=0;
float h=0;
WidgetLED led1(V1);

BlynkTimer timer;

// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    Serial.println("LED on V1: on");
  }
}

void setup()
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
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass,"iot.htpro.vn", 8080);
  //Blynk.begin(auth, ssid, pass);
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
