#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "ชื่อ WiFi";
const char* password = "รหัส WiFi";
const char* serverUrl = "http://your-php-server.com/your-php-script.php";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  sendGetRequest();
}

void loop() {

}

void sendGetRequest() {
  HTTPClient http;

  String url = serverUrl + "?param1=value1&param2=value2";

  http.begin(url);

  int httpResponseCode = http.GET();

  if(httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }


  http.end();
}
