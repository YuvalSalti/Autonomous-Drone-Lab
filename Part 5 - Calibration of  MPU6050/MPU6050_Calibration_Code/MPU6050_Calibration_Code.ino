#include <Wire.h> // Include the I2C communication library

// Variables to hold gyro rate data for each axis
float RateRoll, RatePitch, RateYaw;

// Variables to hold average gyro bias (for calibration)
float RateCalibrationRoll, RateCalibrationPitch, RateCalibrationYaw;

// Counter for the number of calibration readings
int RateCalibrationNumber;

// Function to read and calculate gyroscope data
void gyro_signals(void) {
  // Set low-pass filter configuration (register 0x1A)
  Wire.beginTransmission(0x68);// Start communication with gyro (MPU6050 I2C address is 0x68)
  Wire.write(0x1A);// Access configuration register
  Wire.write(0x05);// Set low-pass filter to ~10Hz
  Wire.endTransmission(); // End transmission


  // Set gyro full-scale range (register 0x1B)
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);// Access gyro configuration register
  Wire.write(0x08);// Set full-scale range to ±500°/s
  Wire.endTransmission();


  // Prepare to read gyro data starting from register 0x43 (gyro X high byte)
  Wire.beginTransmission(0x68);
  Wire.write(0x43); // Start reading from gyro X-axis high byte
  Wire.endTransmission(); 

 // Request 6 bytes of gyro data (X, Y, Z: each axis has 2 bytes)
  Wire.requestFrom(0x68,6);

  // Read and combine high and low bytes for each axis
  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();

  // Convert raw data to °/s using scale factor (±500°/s => 65.5 LSB/°/s)
  RateRoll=(float)GyroX/65.5;
  RatePitch=(float)GyroY/65.5;
  RateYaw=(float)GyroZ/65.5;
}


void setup() {
  Serial.begin(57600);// Start serial communication
  pinMode(13, OUTPUT);// Set pin 13 as output
  digitalWrite(13, HIGH);// Turn on pin 13 (status LED or similar)

  Wire.setClock(400000); // Set I2C clock to 400kHz (fast mode)
  Wire.begin();// Initialize I2C communication
  
  delay(250); // Short delay for MPU6050 to power up

 // Wake up MPU6050 by writing 0 to the power management register (0x6B)
  Wire.beginTransmission(0x68); 
  Wire.write(0x6B);// Access power management register
  Wire.write(0x00);// Set to 0 to wake up sensor
  Wire.endTransmission();

  // --- Gyroscope calibration: average out 2000 readings ---
  for (RateCalibrationNumber=0; RateCalibrationNumber<2000; RateCalibrationNumber ++) {
    gyro_signals(); // Read current gyro values

    // Accumulate readings for averaging
    RateCalibrationRoll+=RateRoll;
    RateCalibrationPitch+=RatePitch;
    RateCalibrationYaw+=RateYaw;

    delay(1);// Short delay between samples
  }

  // Calculate average bias for each axis
  RateCalibrationRoll/=2000;
  RateCalibrationPitch/=2000;
  RateCalibrationYaw/=2000;   
}
void loop() {
  gyro_signals();// Read gyroscope data and update global variables
  
  // Subtract calibration offset (bias) to get accurate values
  RateRoll-=RateCalibrationRoll;
  RatePitch-=RateCalibrationPitch;
  RateYaw-=RateCalibrationYaw;

  // Print the calibrated angular rates to the Serial Monitor
  Serial.print("Roll rate [°/s]= ");
  Serial.print(RateRoll); 
  Serial.print(" Pitch Rate [°/s]= ");
  Serial.print(RatePitch);
  Serial.print(" Yaw Rate [°/s]= ");
  Serial.println(RateYaw);

  delay(50); // Small delay between reads (20 Hz sampling rate)
}