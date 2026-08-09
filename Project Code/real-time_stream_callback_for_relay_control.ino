void streamCallback(FirebaseStream data) {
if (data.dataPath() == "/Relay1") {
digitalWrite(RELAY_PIN, data.stringData().toInt());
}
}
void setupStream() {
Firebase.RTDB.beginStream(&fbdo, "/Controls");
Firebase.RTDB.setStreamCallback(&fbdo, streamCallback, nullptr);
}