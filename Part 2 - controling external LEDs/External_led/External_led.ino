void setup() {
  // put your setup code here, to run once:
  
  pinMode(5,OUTPUT);     // Initialize pin 5 as output
  pinMode(6,OUTPUT);     // Initialize pin 6 as output
  pinMode(13,OUTPUT);    // Initialize pin 13 as output

  digitalWrite(13,HIGH); // Turn on pin 13 LED on
  digitalWrite(5,HIGH);  // Turn external red LED on
  delay(4000);           // Wait 4 seconds

  digitalWrite(5,LOW);   // Turn external red LED off
  digitalWrite(6,HIGH);  // Turn external green LED on

}

void loop() {
  // put your main code here, to run repeatedly:

}
