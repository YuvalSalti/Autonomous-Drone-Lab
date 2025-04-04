
float Voltage;                          // Create a parmter for Voltage
void battary_voltage(void){     
  Voltage = (float)analogRead(15)/62;   // Calc the voltage from analog pin 15 which is limited by 3.3V and is conected in a 1/5 voltage divaider
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);    // Initialize serial communication at 57600 baud
  pinMode(13, OUTPUT);    // Initialize pin 13 as output
  digitalWrite(13, HIGH); // Turn on pin 13 LED on
}

void loop() {
  // put your main code here, to run repeatedly:
  battary_voltage();      // Call the function to read and calculate battery voltage
  Serial.print(Voltage);  // Print read voltage to the screen
  Serial.println("V");    //print the letter V
  delay(500);             // Wait 4 seconds
}
