void setup() {
  
  pinMode(8 , OUTPUT);
  pinMode(9 , OUTPUT);
  pinMode(10 , OUTPUT);   // Ledlerimizi "OUTPUT" olarak tanımlıyoruz.
  pinMode(11 , OUTPUT);
  pinMode(12 , OUTPUT);

}

void loop() {

  for(int x = 8 ; x < 13 ; x++){
    digitalWrite(x , HIGH);           // Problem Seti 1'de bizden istenildiği gibi led yakmak için basit bir for döngüsü kuruyoruz.
    delay(500);  
  }

  for(int x = 12 ; x > 7 ; x--){
    digitalWrite(x , LOW);           // Problem Seti 1'de bizden istenildiği gibi led söndürmek için basit bir for döngüsü kuruyoruz.
    delay(500);
  }
  
}
