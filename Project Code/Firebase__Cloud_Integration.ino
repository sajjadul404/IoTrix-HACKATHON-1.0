#include <Firebase_ESP_Client.h>
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
config.api_key = "YOUR_FIREBASE_API_KEY";
config.database_url = "YOUR_DATABASE_URL";
if (Firebase.signUp(&config, &auth, "", "")) {
Serial.println("Auth Successful");
}
Firebase.begin(&config, &auth);
Firebase.reconnectWiFi(true);
}