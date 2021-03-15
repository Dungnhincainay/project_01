#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>    
//#include <SimpleTimer.h>
 
SimpleTimer timer;
//char auth[] = "C39HJavn-IoVsrHbYA7ea3IqlKhGauFL";
char auth[] = "8TytNxie25BVKYolzRm_yLjF1vAGbrCA";
char ssid[] = "Wifi Cua Tuan";
char pass[] = "";

float h=0;      // V4 - Do am khong khi
float t=0;      // V5 - Nhiet do khong khi
float hum=0;    // V6 - Do am Dat 
int flag=0;





//////
 // V1 V2 : Chọn chế độ
 float value1;
 float Kp =0;      //Kp
 float Ki =0;      //Ki
 float Kd =0;      //Kd

int ledState = LOW;
unsigned long Ago = 0;
unsigned long Now = 0;

const long Set_time = 300;



BLYNK_CONNECTED() {
    Blynk.syncAll();
}
 BLYNK_WRITE(V1){
   value1 = param.asFloat(); // Get value as integer
 }
 BLYNK_WRITE(V7){   
   Kp = param.asFloat(); // Get value as integer
 }
 BLYNK_WRITE(V8){   
   Ki = param.asFloat(); // Get value as integer
 }
 BLYNK_WRITE(V9){   
   Kd = param.asFloat(); // Get value as integer
 }

void setup()
{
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass,"iot.htpro.vn", 8080);
    pinMode(LED_BUILTIN, OUTPUT);
    timer.setInterval(1500, sendUptime);
}

void sendUptime()
{
   h = h+0.845 ;             // Đọc giá tri nhiệt độ, độ ẩm không khí
   t = t+1.23 ;              // Đọc giá tri nhiệt độ, độ ẩm không khí
   if (h>=100){              // Đọc giá tri nhiệt độ, độ ẩm không khí
     h=0;                    // Đọc giá tri nhiệt độ, độ ẩm không khí
   }                         // Đọc giá tri nhiệt độ, độ ẩm không khí
   if(t>=100){               // Đọc giá tri nhiệt độ, độ ẩm không khí
     t=1;                    // Đọc giá tri nhiệt độ, độ ẩm không khí
   }
   Now = millis();                // Nhấp nháy led
  if (Now - Ago >= Set_time) {    // Nhấp nháy led
    Ago = Now;                    // Nhấp nháy led
    if (ledState == LOW) {        // Nhấp nháy led
      ledState = HIGH;            // Nhấp nháy led
    } else {                      // Nhấp nháy led
      ledState = LOW;             // Nhấp nháy led
    }                             // Nhấp nháy led
    digitalWrite(LED_BUILTIN, ledState);       // Đảo trạng thái led
  }
   Serial.println("\nKet qua do duoc:");          // Hiển thị trên monitor
   Serial.print("Do Am = ");                     // Hiển thị trên monitor
   Serial.print(h);                             // Hiển thị trên monitor
   Serial.print("%  ");                        // Hiển thị trên monitor
   Serial.print("Nhiet do = ");               // Hiển thị trên monitor
   Serial.print(t);                                   // Hiển thị trên monitor
   Serial.print("°C \n");                            // Hiển thị trên monitor
   Serial.print("\nGia tri V1: ");                  // Hiển thị trên monitor
   Serial.print(value1);                           // Hiển thị trên monitor
   Serial.print(" ");                             // Hiển thị trên monitor

  Blynk.virtualWrite(V6, t);        // Gửi dữ liệu lên sever - lên Điện thoại.
  Blynk.virtualWrite(V5, h);      // Gửi dữ liệu lên sever - lên Điện thoại.
  //  Blynk.virtualWrite(V0, VIRTUAL_PIN_0); // ghi gia tri len App qua V0
  if(t>=70 && flag==0){
    Blynk.notify("Nhiệt độ cao");
    flag=1;
  }else if(t<70){
      flag=0;
    }  
}

void loop()
{
  Blynk.run();
  timer.run();

  // bla bla.....
}
