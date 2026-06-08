#include "DHT.h"

#define DHTPIN 2      
#define DHTTYPE DHT22 
#define RED_PIN 3     // PA3
#define GRN_PIN 5     // PA5
#define BUZ_PIN 4     // PA4

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Add this line!
  pinMode(RED_PIN, OUTPUT);
  pinMode(GRN_PIN, OUTPUT);
  pinMode(BUZ_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000);
  float temp = dht.readTemperature();
  
  // DEBUGGING: Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.println(temp);

  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Reset all
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GRN_PIN, LOW);
  digitalWrite(BUZ_PIN, LOW);

  if (temp < 30.0) {
    // Green
    digitalWrite(GRN_PIN, HIGH);
  } 
  else if (temp >= 30.0 && temp <= 40.0) {
    // Yellow (Red + Green)
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GRN_PIN, HIGH);
  } 
  else {
    // Red + Buzzer
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BUZ_PIN, HIGH);
  }
}