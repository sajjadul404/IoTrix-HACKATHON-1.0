#include <WiFi.h>
#include <WebServer.h>
WebServer server(80);
String htmlPage = "<html><body> ... ";
void setup() {
server.on("/", []() {
server.send(200, "text/html", htmlPage);
});
server.begin();
}
void loop() {
server.handleClient();
}