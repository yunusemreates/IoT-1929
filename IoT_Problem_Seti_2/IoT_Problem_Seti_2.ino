#define kirmizi 8  
#define sari 9     // Ledlerimizi tanımlıyoruz.
#define yesil 10

void setup() {

  pinMode(kirmizi , OUTPUT);
  pinMode(sari , OUTPUT);    // Ledlerimizi "output" olarak belirtiyoruz.
  pinMode(yesil , OUTPUT);

}

void loop() {
  // Problem Seti 2'yi gerçekleştirmek için kırmızı,sarı ve yeşil ledlerimizi
  // bizden istenildiği gibi HIGH veya LOW yazıyoruz.
  
  digitalWrite(kirmizi , HIGH);
  delay(10000);
  digitalWrite(sari , HIGH);
  digitalWrite(kirmizi , HIGH);
  delay(12000);
  digitalWrite(kirmizi , LOW);
  digitalWrite(sari , LOW);
  digitalWrite(yesil , HIGH);
  delay(5000);
  digitalWrite(yesil , LOW);
}
