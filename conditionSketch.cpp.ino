#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8
#define DHTTYPE DHT11

#define LED_RED 9
#define LED_YELLOW 10
#define LED_BLUE 13

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setLED(bool red, bool yellow, bool blue) {
  digitalWrite(LED_RED, red);
  digitalWrite(LED_YELLOW, yellow);
  digitalWrite(LED_BLUE, blue);
}

void setup() {
  Serial.begin(9600);
  delay(2000);
  dht.begin();
  lcd.begin(16, 2);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("C  Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  lcd.clear();

  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    setLED(true, false, false);  // red if error
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Humid: ");
    lcd.print(humidity);
    lcd.print("%");

    // Change LED based on temperature
    if (temperature >= 30) {
      setLED(true, false, false);   // 🔴 red = hot
    } else if (temperature >= 20) {
      setLED(false, true, false);   // 🟡 yellow = warm
    } else {
      setLED(false, false, true);   // 🔵 blue = cold
    }
  }

  delay(2000);
}