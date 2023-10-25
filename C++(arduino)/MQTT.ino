#include <ESP8266WiFi.h>
#include <AsyncMqttClient.h>


const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

const char* mqtt_server = "mqtt.yourbroker.com";
const int mqtt_port = 1883;
const char* mqtt_user = "YourMQTTUsername";
const char* mqtt_password = "YourMQTTPassword";

AsyncMqttClient mqttClient;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  mqttClient.setServer(mqtt_server, mqtt_port);
  mqttClient.setCredentials(mqtt_user, mqtt_password);


  mqttClient.onMessage([](char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total) {
    Serial.println("Message received on topic: " + String(topic));
    Serial.println("Message: " + String(payload));
  });
  mqttClient.connect();
}

void loop() {
  mqttClient.loop();
  if (mqttClient.connected()) {
    mqttClient.publish("topic/test", 0, true, "TEST");
    delay(5000);
  }
}