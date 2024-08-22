#include <LiquidCrystal.h>

// Initialize the LCD with the pin numbers for RS, EN, D4, D5, D6, and D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

// Constants for calibration values
const int AirValue = 576;  // Value for dry soil (air)
const int WaterValue = 307;  // Value for wet soil (water)

int soilMoistureValue = 0;  // Variable to store raw soil moisture sensor value
int soilMoisturePercent = 0;  // Variable to store soil moisture percentage

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  soilMoistureValue = analogRead(A0);  // Read the analog value from the soil moisture sensor
  Serial.println(soilMoistureValue);  // Print the raw value to the Serial Monitor

  // Map the raw value to a percentage (0% = water, 100% = air)
  soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  // If the soil is very dry or beyond the dry calibration value
  if (soilMoisturePercent >= 100) {
    Serial.println("100 %");  // Print "100 %" to the Serial Monitor
    lcd.setCursor(0, 0);  // Set the cursor to the first column of the first row on the LCD
    lcd.print("Soil Moisture");  // Print "Soil Moisture" on the LCD
    lcd.setCursor(0, 1);  // Set the cursor to the first column of the second row
    lcd.print("100%");  // Print "100%" on the LCD
    delay(250);  // Wait for 250 milliseconds
    lcd.clear();  // Clear the LCD display
  }

  // If the soil is very wet or beyond the wet calibration value
  else if (soilMoisturePercent <= 0) {
    Serial.println("0 %");  // Print "0 %" to the Serial Monitor
    lcd.setCursor(0, 0);  // Set the cursor to the first column of the first row
    lcd.print("Soil Moisture");  // Print "Soil Moisture" on the LCD
    lcd.setCursor(0, 1);  // Set the cursor to the first column of the second row
    lcd.print("0%");  // Print "0%" on the LCD
    delay(250);  // Wait for 250 milliseconds
    lcd.clear();  // Clear the LCD display
  }

  // If the soil moisture is between 0% and 100%
  else if (soilMoisturePercent > 0 && soilMoisturePercent < 100) {
    Serial.print(soilMoisturePercent);  // Print the moisture percentage to the Serial Monitor
    Serial.println(" %");  // Print "%" to the Serial Monitor
    lcd.setCursor(0, 0);  // Set the cursor to the first column of the first row
    lcd.print("Soil Moisture");  // Print "Soil Moisture" on the LCD
    lcd.setCursor(0, 1);  // Set the cursor to the first column of the second row
    lcd.print(soilMoisturePercent);  // Print the moisture percentage on the LCD
    lcd.print(" %");  // Print "%" on the LCD
    delay(250);  // Wait for 250 milliseconds
    lcd.clear();  // Clear the LCD display
  }
}
