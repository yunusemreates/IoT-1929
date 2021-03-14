#include <Servo.h> // Servo kullanabilmek için servo kütüphanemizi koda dahil ediyoruz.

#define pot_1 A0 // Potansiyometrelerimizi arduino üzerinde hangi pinlere takdığımızı belirtiyoruz.
#define pot_2 A1 

Servo servo_1; // Servolarımıza isim veriyoruz.
Servo servo_2;

int deger_1; // Potansiyometrelerden okuduğumuz değerler için iki farklı int tanımlıyoruz.
int deger_2;      

void setup() {
  servo_1.attach(9);  // Servolarımızı arduino üzerinde hangi pinlere bağladığımızı belirtiyoruz. 
  servo_2.attach(10); 
}

void loop() {
  deger_1 = analogRead(pot_1);            
  deger_1 = map(deger_1, 0, 1023, 0, 180);    // Burada pot1'den okuduğumuz değeri map komutu ile 0-180 arasına çekip servonun hareketi için kullanıyoruz. 
  servo_1.write(deger_1);                 
   
  
  deger_2 = analogRead(pot_2);            
  deger_2 = map(deger_2, 0, 1023, 0, 90);     // Burada ise pot2'den okuduğumuz değeri map komutu ile 0-180 arasına çekip servonun hareketi için kullanıyoruz. 
  servo_2.write(deger_2);                  
   
}
