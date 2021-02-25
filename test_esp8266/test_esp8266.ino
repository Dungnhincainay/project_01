// Them thu vien
#include <ESP8266WiFi.h>
// Thong so WiFi
const char* ssid = "Wifi Cua Tuan";  //Thay  ten_wifi bang ten wifi nha ban
const char* password = ""; //Thay mat_khau_wifi bang mat khau cua ban
void setup(void){

  pinMode(LED_BUILTIN, OUTPUT); 
// Khoi dong serial de debug
  Serial.begin(115200);
// Ket noi voi WiFi
Serial.print("/n");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { //Kiem tra xem trang thai da ket noi chua neu chua thi in ra dau .
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
// Neu da ket noi duoc voi wifi se in ra dia chi IP
  Serial.println(WiFi.localIP());
  //digitalWrite(LED_BUILTIN, HIGH);
}
void loop() {
    //while (WiFi.status()) {
    while (WiFi.status() != WL_CONNECTED) { //Kiem tra xem trang thai da ket noi chua neu chua thi in ra dau .
    digitalWrite(LED_BUILTIN, HIGH);
    delay(400);
  };
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off by making the voltage HIGH
  delay(800);
  
}
