void setup() {
  // put your setup code here, to run once:
  // Initialize port 13 as output
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Write pin 13 as high (on) and wait 500 ms.
  digitalWrite(13,HIGH);
  delay(500);
  
  // Write pin 13 as low (off) and wait 500 ms.
  digitalWrite(13,LOW);
  delay(500);
}
