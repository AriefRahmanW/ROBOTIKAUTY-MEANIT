// auto connect ke hostspot jika lost connect
// jangan bosen ngoding

#include <ESP8266WiFi.h>

const char * ssid = "Robotika"; // sesuaikan dengan ssid hotspot mu
const char * pass = "12345678"; // sesuaikan dengan password hotspot mu


// kumpulan ssid dan password jika dibutuhkan connect ke hotspot lain
String ssidArray[] = {"arduino", "arief", "iot"};
String passArray[] = {"12345678", "dol30IQ0", "123456789"};


void setup() {
  Serial.begin(115200); // serial yang sering di gunakan pada nodemcu

  WiFi.begin(ssid, pass); // memulai koneksi

  // menunggu terhubung ke hotspot
  Serial.println("menghubungkan");
  while(WiFi.status() != WL_CONNECTED){
    delay(300);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("ip address : ");
  Serial.println(WiFi.localIP());
  Serial.print("mac address : ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("terhubung...");
  }
  else{
    Serial.println("tidak terhubung...");
    
    // cek kumpulan ssid dan password satu persatu
    for(int i=0; i < 3; i++){
       if(cek(ssidArray[i], passArray[i])){
          Serial.println("berhasil konek lagi");
          Serial.println();
          Serial.print("ip address : ");
          Serial.println(WiFi.localIP());
          Serial.print("mac address : ");
          Serial.println(WiFi.macAddress());
          break;
       }
    }
  }

}

bool cek(String a, String b){
  WiFi.begin(a, b);

    Serial.println("menghubungkan");
    while(WiFi.status() != WL_CONNECTED){
      delay(300);
      Serial.print(".");
    }

    return true;
}
