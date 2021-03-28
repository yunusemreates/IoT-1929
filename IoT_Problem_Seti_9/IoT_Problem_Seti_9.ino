#include <SPI.h>                          //SPI kütüphanemizi tanımlıyoruz.
#include <MFRC522.h>                      //MFRC522 kütüphanemizi tanımlıyoruz.

#define yesil 6                           // Ledlerimizi tanımlıyoruz.
#define kirmizi 7

int RST_PIN = 9;                          //RC522 modülü reset pinini tanımlıyoruz.
int SS_PIN = 10;                          //RC522 modülü chip select pinini tanımlıyoruz.

MFRC522 rfid(SS_PIN, RST_PIN);            //RC522 modülü ayarlarını yapıyoruz.
byte ID[4] = {51, 28, 52, 22};            //Yetkili kart ID'sini tanımlıyoruz. 

void setup() { 
  Serial.begin(9600);                     //Seri haberleşmeyi başlatıyoruz.
  SPI.begin();                            //SPI iletişimini başlatıyoruz.
  rfid.PCD_Init();                        //RC522 modülünü başlatıyoruz.
  pinMode(yesil , OUTPUT);
  pinMode(kirmizi , OUTPUT);             // Ledlerimizi başlangıçta OUTPUT olarak tanımlıyoruz.
  
}
 
void loop() {

  if ( ! rfid.PICC_IsNewCardPresent())    //Yeni kartın okunmasını bekliyoruz.
    return;

  if ( ! rfid.PICC_ReadCardSerial())      //Kart okunmadığı zaman bekliyoruz.
    return;

  if (rfid.uid.uidByte[0] == ID[0] &&     //Okunan kart ID'si ile ID değişkenini karşılaştırıyoruz.
    rfid.uid.uidByte[1] == ID[1] && 
    rfid.uid.uidByte[2] == ID[2] && 
    rfid.uid.uidByte[3] == ID[3] ) {
        Serial.println("Kapi acildi");
        Serial.println("A-6 Daire 19");                      // Kapı açıldığında ekrana yazılacak yazıları belirtiyoruz.
        Serial.println("Yunus Emre Ateş Hoşgeldiniz");
        Serial.println("******************************************************************");
        digitalWrite(yesil , HIGH);
        delay(2000);                        // Yetkili kart okutulduğunda 2 saniye boyunca yeşil ışığın yanmasını sağlıyoruz.
        digitalWrite(yesil , LOW);
       
    }
    else{                                 //Yetkisiz girişte içerideki komutlar çalıştırılır.
      Serial.println("Yetkisiz Kart !!");
      Serial.println("*******************************************************************");
        digitalWrite(kirmizi , HIGH);
        delay(2000);
        digitalWrite(kirmizi , LOW);
        }
  rfid.PICC_HaltA();
}
