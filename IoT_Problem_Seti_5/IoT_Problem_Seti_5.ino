#include <Servo.h>  // Servo motoru kullanmak için servo kütüphanesini koda dahil ediyoruz.
#include <OLED_I2C.h> // Oled ekran kullanabilmek için oled kütüphanesini koda dahil ediyoruz.

OLED  myOLED(SDA, SCL, 8);  // Oled ekran ile ilgili kodlar.
extern uint8_t SmallFont[];  
Servo canim_servom; // Servomuzun adını belirliyoruz :).

void setup() {

  canim_servom.attach(9); // Servonun kaçıncı pine bağlı olduğunu tanımlıyoruz.
  myOLED.begin();            
  myOLED.setFont(SmallFont);  // Oled ekranı başlatıp yazı tipini belirliyoruz.
}

void loop() {

  // Problem Seti 5'de bizden istenilen şekilde iki tane for döngüsü oluşturuyoruz.
  for(int x = 0; x <= 180; x=x+15){

    canim_servom.write(x);
    String basilacak_deger; // Ekrana basabilmek için integer türünde olan ifadeyi string olarak değiştiriyoruz.
    basilacak_deger = x;
    myOLED.clrScr();
    myOLED.print("SERVO DEGERI : " , LEFT, 0);
    myOLED.print(basilacak_deger , CENTER, 24);   // Oled ekrana basma işlemini yapıyoruz.
    myOLED.update();
    delay(1000);
  }
  for(int x = 180; x >= 0 ; x=x-30){

    canim_servom.write(x);
    String basilacak_deger; // Ekrana basabilmek için integer türünde olan ifadeyi string olarak değiştiriyoruz.
    basilacak_deger = x;
    myOLED.clrScr();
    myOLED.print("SERVO DEGERI : " , LEFT, 0);
    myOLED.print(basilacak_deger , CENTER, 24);   // Oled ekrana basma işlemini yapıyoruz.
    myOLED.update();
    delay(1000);
  }

}
