#include <LiquidCrystal_I2C.h>
#include <Wire.h>


int tempPin = A0;
bool logging = false;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  if(logging){
    Serial.begin(9600);
  }

  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
}

double readTemp(){
  uint16_t val;
  double dat;
  val = analogRead(tempPin);
  dat = (double) val * (5/10.24);
  return dat;
}

void display(double temperature){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(temperature);
  lcd.print("C");
}

void loop() {
  // put your main code here, to run repeatedly:
  double temperature = readTemp();
  display(temperature);

  if(logging){
    Serial.print(temperature);
    Serial.println("C");
  }

  delay(1000);
}
