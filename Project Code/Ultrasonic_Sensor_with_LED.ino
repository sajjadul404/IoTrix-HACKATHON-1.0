#define TRIG_PIN 5
#define ECHO_PIN 18
#define LED_PIN 2
#define THRESHOLD_CM 15
void setup() {
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(LED_PIN, OUTPUT);
Serial.begin(115200);
}
void loop() {
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
long duration = pulseIn(ECHO_PIN, HIGH);
float distanceCm = duration * 0.0343 / 2;
Serial.print("Distance: "); Serial.println(distanceCm);
if (distanceCm > 0 && distanceCm < THRESHOLD_CM) {
digitalWrite(LED_PIN, HIGH); // Object detected nearby
} else {
digitalWrite(LED_PIN, LOW);
}
delay(300);
}