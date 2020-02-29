#include <ESP8266WiFi.h>

const char* ssid = "***";
const char* password = "***";

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  
  Serial.println("menghubungkan");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }


  Serial.println("");
  Serial.print("terhubung dengan IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Serial.print("MAC : ");
  Serial.println(WiFi.macAddress());

}

void loop(){}
