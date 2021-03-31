#include <dht11.h>     // DHT11 modülünü kullanmak için kütüphanemizi koda dahil ediyoruz.

#define potpin A0       // Potansiyometrenin bağlı olduğu pin
#define HC_trig 9       // HC-SR04'ün Trig pininin bağlı olduğu pin
#define HC_echo 10      // HC-SR04'ün Echo pininin bağlı olduğu pin

int sure;               // HC-SR04 kullanılırken okunan süre için tanımlanan değişken
int mesafe;             // HC-SR04 kullanılırken hesaplanan mesafe için tanımlanan değişken
int deger = 0;         // Potansiyometreden veri almak için tanımlanan değişken.(başlangıcı sıfır verilmiştir.)

int DhtPin=2;           // DhtPin olarak Dijital 2'yi belirliyoruz.
dht11 dht_sensor;       // dht_sensor adında bir DHT11 nesnesi oluşturuyoruz.

void setup() {
  
  Serial.begin (9600);             // Seri haberleşme başlatılır
  pinMode(HC_trig, OUTPUT);        // HC-SR04'ün Trig pini çıkış olarak ayarlanır
  pinMode(HC_echo, INPUT);         // HC-SR04'ün Echo pini giriş olarak ayarlanır
  digitalWrite(HC_trig, LOW);      // HC-SR04'ün Trig bacağı LOW yapılır

}

void loop() {

  //Aşağıda HC-SR04 için olan kodlar yazılmıştır.
  
  digitalWrite(HC_trig, LOW);      //Trig pini 0'a çekilir.(Zorunlu değildir sadece emin olmak için.)
  delayMicroseconds(2);            //2 uS beklenir.
  digitalWrite(HC_trig, HIGH);     //Trig pini 1'e çekilir.
  delayMicroseconds(10);           //10 uS 1'de tutulur.
  digitalWrite(HC_trig, LOW);      //Trig bacağı 0'a çekilir ve sensör tetiklenmiş olur.
  sure = pulseIn(HC_echo, HIGH);   //pulseIN fonksiyonu ile Echo pininin kaç uS '1' olduğu ölçülür.
  mesafe = sure*0.034/2;           //Süreden mesafe hesaplanır 
  
  //*****************************************************************************************************
  
  int chk = dht_sensor.read(DhtPin);  // DHT11 sensörü konrol ediliyor. 
  deger  = analogRead(potpin);        //"Değer" değişkeni potansiyometrenin değerini okuyup buna göre değişir

  // Kodun bundan sonraki kısmında Seriporta yazma işlemi yapılacaktır.

  Serial.print(mesafe);                             // HC-SR04'ten okunan mesafe değeri.
  Serial.print("/");
  Serial.print((float)dht_sensor.humidity, 2);     // DHT11'den okunan nem değeri.
  Serial.print("/");
  Serial.print((float)dht_sensor.temperature, 2);  //DHT11'den okunan sıcaklık değeri.
  Serial.print("/");
  Serial.println(deger);                           // Potansiyometreden okunan değer.

 
  delay(3000);
}
