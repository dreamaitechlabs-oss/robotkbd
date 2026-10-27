#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11

#define LED_PIN LED_BUILTIN

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, HIGH); // LED OFF initially

  Serial.println("DHT11 Temperature Alert Started");
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Sensor Error");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C   ");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");


  if (temperature > 40) {

    digitalWrite(LED_PIN, LOW);   // Built-in LED ON
    Serial.println("Temperature High - LED ON");

  } 
  else {

    digitalWrite(LED_PIN, HIGH);  // Built-in LED OFF
    Serial.println("Temperature Normal - LED OFF");

  }

  delay(2000);
}