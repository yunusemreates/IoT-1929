#include <dht11.h>     // DHT11 modülünü kullanmak için kütüphanemizi koda dahil ediyoruz.
#include <OLED_I2C.h>  // Oled ekranı kullanabilmek için kütüphanemizi koda dahil ediyoruz.

OLED  myOLED(SDA, SCL, 8);   // Oled ekran için olan kodlar.
extern uint8_t SmallFont[]; 

int DhtPin=2;     // DhtPin olarak Dijital 2'yi belirliyoruz.
dht11 dht_sensor; // dht_sensor adında bir DHT11 nesnesi oluşturuyoruz.

void setup()
{
  myOLED.begin(); // Oled ekranı başlatıyoruz.      
  myOLED.setFont(SmallFont); // Oled ekranda olacak yazı tipini belirliyoruz.
}

void loop()
{
  int chk = dht_sensor.read(DhtPin);  // Sensör konrol ediliyor. 

  String deger1;
  deger1 = (float)dht_sensor.humidity, 2;
  String deger2;
  deger2 = (float)dht_sensor.temperature, 2;      // Oled ekrana yazı yazabilmek için okunan değerleri string yapılarına dönüştürüyoruz.
  String deger3;
  deger3 = dht_sensor.kelvin(), 2;
  String deger4;
  deger4 = dht_sensor.fahrenheit(), 2;

  // DHT11 sensöründen okuduğumuz değerleri Oled ekrana yazdırıyoruz.
  // Her bir değerin ekranda 5 saniye kalması için delay'ler ekliyoruz.
  
  myOLED.clrScr();
  myOLED.print("Nem Orani (%): ", LEFT, 0);
  myOLED.print(deger1, CENTER, 24);
  myOLED.update();
  delay (5000);

  myOLED.clrScr();
  myOLED.print("Sicaklik (Celcius): ", LEFT, 0);
  myOLED.print(deger2, CENTER, 24);
  myOLED.update();
  delay (5000);

  myOLED.clrScr();
  myOLED.print("Sicaklik (Kelvin): ", LEFT, 0);
  myOLED.print(deger3, CENTER, 24);
  myOLED.update();
  delay (5000);

  myOLED.clrScr();
  myOLED.print("Sicaklik (Fahrenheit): ", LEFT, 0);
  myOLED.print(deger4, CENTER, 24);
  myOLED.update();
  delay (5000);
  }
