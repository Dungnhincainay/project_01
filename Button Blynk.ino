#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define LED D4
#define Button D3

int Status = 1;

int VIRTUAL_PIN_0;
bool isPushOnApp = false;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "iWP_e-4LA9tR6t6JGal00Ryic6SEp_Kl";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Set";
char pass[] = "25251325";
  BLYNK_CONNECTED() 
  {
     Blynk.syncAll();
  }
  BLYNK_WRITE(V0)
  {
     VIRTUAL_PIN_0 = param.asInt();
     isPushOnApp = true;
  }
void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(Button, INPUT_PULLUP);
  digitalWrite(LED,Status);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  if(isPushOnApp == true) // neu Nut nhan tren App duoc nhan
  {
      Serial.println("Nhan Tren APP:" + String(VIRTUAL_PIN_0));
      digitalWrite(LED, VIRTUAL_PIN_0); //ghi trang thai V0 len LED
      isPushOnApp = false; // xoa bien cap nhat
  }
  if(digitalRead(Button) == 0) // neu nut nhan dc nhan
  {
    delay(50);
    if(digitalRead(Button)!=0)
    {
      VIRTUAL_PIN_0 = !VIRTUAL_PIN_0; // dao gia trị 
      Serial.println("Nhan Tren Board:" + String(VIRTUAL_PIN_0));
      digitalWrite(LED,VIRTUAL_PIN_0); // ghi gia tri len LED
      Blynk.virtualWrite(V0, VIRTUAL_PIN_0); // ghi gia tri len App qua V0
    }
  }
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}