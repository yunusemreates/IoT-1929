#include <OLED_I2C.h> // Hız değerini Oled ekrana bastırmak için kütüphanemizi koda dahil ediyoruz.

OLED  myOLED(SDA, SCL, 8); // Oled ekranla ilgili kodlar.
extern uint8_t SmallFont[]; 

#define DC1 4      // L298N motor sürücü aracılığıyla DC motorun bir kablosunu 4 numaralı pine tanımlıyoruz.
#define DC2 5      // L298N motor sürücü aracılığıyla DC motorun diğer kablosunu 5 numaralı pine tanımlıyoruz.
#define Enable_A 6 // DC motorun hız kontrolünü yapabilmek için L298N'den gelen enable pinini 6 numaralı pine tanımlıyoruz.
#define pot A0     // Potansiyometreyi analog pinlerden A0'a tanımlıyoruz. 
#define LED1 9
#define LED2 10
#define LED3 11   // Ledlerimizi tanımlıyoruz.
#define LED4 12
#define LED5 13
int motor;       // Potansiyometreden okuduğumuz değeri tutmak için motor adında bir integer tanımlıyoruz.

void setup() {

  myOLED.begin();            // Oled ekranı başlatıyoruz.
  myOLED.setFont(SmallFont); // Ekrana yazacağımız yazının fontunu belirliyoruz. 
  
  pinMode(DC1 , OUTPUT);
  pinMode(DC2 , OUTPUT);
  pinMode(Enable_A , OUTPUT);
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);   // Ledleri, DC motoru ve enable pinini output olarak belirtiyoruz.
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);

}

void loop() {

  motor = analogRead(pot); // Potansiyometreden okunan değeri motor adındaki int'e atıyoruz.
  motor = map(motor , 0 , 1023 , 0 , 255); // Map komutu ile okuduğumuz değeri 0-255 arasına çekiyoruz.
  analogWrite(Enable_A , motor); // Potansiyometreden okuduğumuz değer ile motorumuzun hızını belirliyoruz.
  digitalWrite(DC1 , HIGH);
  digitalWrite(DC2 , LOW);  // L298N motor sürücü kullanırken birine HIGH vermemiz yeterli. Bu sadece motorun dönüş yönünü belirler.

  String basilacak_deger;
  basilacak_deger = motor;  // Oled ekrana hız değerini basmak için bir string oluşturuyoruz.

  myOLED.clrScr();
  myOLED.print("H I Z : " , LEFT, 0);
  myOLED.print(basilacak_deger , CENTER, 24);  // Oled ekrana DC motorun hızını anlık olarak yazıyoruz.
  myOLED.update();
  delay(200);

  // Burdan sonraki kodlarda if-else yapısı kullanarak belirli aralıklarda ledlerin yanmasını ve sönmesini sağlıyoruz.

  if(motor <= 50){
    digitalWrite(LED1 , LOW);
    digitalWrite(LED2 , LOW);
    digitalWrite(LED3 , LOW);
    digitalWrite(LED4 , LOW);
    digitalWrite(LED5 , LOW);
  }
   else if(motor > 50 && motor <= 100){
    digitalWrite(LED1 , HIGH);
    digitalWrite(LED2 , LOW);
    digitalWrite(LED3 , LOW);
    digitalWrite(LED4 , LOW);
    digitalWrite(LED5 , LOW);
  }
  else if( motor > 100 && motor <= 150){
    digitalWrite(LED1 , HIGH);
    digitalWrite(LED2 , HIGH);
    digitalWrite(LED3 , LOW);
    digitalWrite(LED4 , LOW);
    digitalWrite(LED5 , LOW);
  }
  else if( motor > 150 && motor <= 200){
    digitalWrite(LED1 , HIGH);
    digitalWrite(LED2 , HIGH);
    digitalWrite(LED3 , HIGH);
    digitalWrite(LED4 , LOW);
    digitalWrite(LED5 , LOW);
  }
  else if( motor > 200 && motor <= 250){
    digitalWrite(LED1 , HIGH);
    digitalWrite(LED2 , HIGH);
    digitalWrite(LED3 , HIGH);
    digitalWrite(LED4 , HIGH);
    digitalWrite(LED5 , LOW);
  }
    else if( motor > 250){
    digitalWrite(LED1 , HIGH);
    digitalWrite(LED2 , HIGH);
    digitalWrite(LED3 , HIGH);
    digitalWrite(LED4 , HIGH);
    digitalWrite(LED5 , HIGH);
  }

 

}
