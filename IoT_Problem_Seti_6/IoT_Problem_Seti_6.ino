//Blynk aplikasyonu ile çalışırken önce Blynk kütüphanesini indiriyoruz. 
// Daha sonra Ardunio Ide üzerinden aşağıdaki adımları takip ediyoruz. 
// Ve hazır kod üzerinde küçük değişiklikler yapıyoruz.

// Dosya -> Örnekler -> Blynk -> Boards_WiFi -> ESP8266_Shield

#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "TOKEN'IN"; // Buraya Blynk uygulamasından mailimize gelen token'ı yazıyoruz.

char ssid[] = "Wİ-Fİ ADIN"; // Buraya ESP8266'yı bağlayacağımız Wi-Fi adını yazıyoruz.
char pass[] = "Wİ-Fİ ŞİFREN"; // Buraya ESP8266'yı bağladığımız Wi-Fi'nin şifresini yazıyoruz.

#define EspSerial Serial1
#define ESP8266_BAUD 115200 

ESP8266 wifi(&EspSerial);

void setup()
{
  Serial.begin(9600);
  delay(10);

  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{
  Blynk.run();
}
