#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

void setup() {
  // Start Serial Monitor
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("Connecting to WiFi...");

  // Connect to WiFi
  WiFi.begin(ssid, password);

  // Wait for connection
  int maxRetries = 20; // Retry count
  int retryCount = 0;

  while (WiFi.status() != WL_CONNECTED && retryCount < maxRetries) {
    delay(500);
    Serial.print(".");
    retryCount++;
  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.println("");
    Serial.println("WiFi connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("");
    Serial.println("Failed to connect to WiFi.");
  }
}

void loop() {
  // Optional: print WiFi status every 10 seconds
  if(WiFi.status() == WL_CONNECTED){
    Serial.print("Connected, IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi disconnected, retrying...");
    WiFi.begin(ssid, password); // Retry connection
    delay(5000);
  }

  delay(10000); // Wait 10 seconds
}