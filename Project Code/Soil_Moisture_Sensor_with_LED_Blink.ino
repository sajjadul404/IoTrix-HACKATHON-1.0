#define SOIL_PIN 34 // Analog (ADC) input
#define LED_PIN 2
#define DRY_THRESHOLD 2200 // Adjust based on calibration

IoTrix – Hackathon 1.0 Project Report IEEE BUBT Student Branch

11

void setup() {
pinMode(LED_PIN, OUTPUT);
Serial.begin(115200);
}
void loop() {
int soilValue = analogRead(SOIL_PIN);
Serial.print("Soil Moisture Raw: "); Serial.println(soilValue);
if (soilValue > DRY_THRESHOLD) {
// Soil is dry -> blink LED as an alert
digitalWrite(LED_PIN, HIGH);
delay(200);
digitalWrite(LED_PIN, LOW);
delay(200);
} else {
// Soil is sufficiently moist -> LED off
digitalWrite(LED_PIN, LOW);
}
delay(500);
}