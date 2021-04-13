#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

// Voltage sensor is attached to A1 - Analog Input 1
const int voltageSensor = A1;

float vOUT = 0.0;
float vIN = 0.0;
float R1 = 30000.0; // 300K Ohm Resistor, on the sensor
float R2 = 7500.0;  // 75K Ohm Resistor, on the sensor
int value = 0;

void setup()
{
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight
}

void loop()
{

  // Read value from the sensor
  value = analogRead(voltageSensor);
  
  // take the value and multiply by 3.3 or 5 depending on the board used. 
  vOUT = (value * 3.3) / 1024.0;
  vIN = vOUT / (R2/(R1+R2));

  lcd.setCursor(3, 0); // set the cursor to column 3, line 0
  lcd.print("SignalWire");  // Print a message to the LCD
  
  lcd.setCursor(2, 1); // set the cursor to column 2, line 1
  lcd.print("Input=" + String(vIN));  // Print a message to the LCD.
  
  delay(500);
  
}
