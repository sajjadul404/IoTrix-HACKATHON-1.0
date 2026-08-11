#include <DHT.h>
#define DHT_PIN 4
#define DHT_TYPE DHT11
#define LED_PIN 2
#define TEMP_THRESHOLD_C 30.0
DHT dht(DHT_PIN, DHT_TYPE);
void setup() {
pinMode(LED_PIN, OUTPUT);
Serial.begin(115200);
dht.begin();
}
void loop() {
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
if (!isnan(temperature) && !isnan(humidity)) {
Serial.print("Temp: "); Serial.print(temperature); Serial.print(" C, ");
Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
digitalWrite(LED_PIN, temperature > TEMP_THRESHOLD_C ? HIGH : LOW);
} else {
Serial.println("Failed to read from DHT sensor!");
}
delay(2000); // DHT11 requires >= 1s between reads
}