#pragma once

#include <WiFi.h>
#include <HTTPClient.h>

 void postData (char* serverName){
    WiFi.begin(config.ssid.c_str(), config.password.c_str());
    while(WiFi.status() != WL_CONNECTED) {
      delay(100);
    }
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverName);
      
      // If you need an HTTP request with a content type: application/json, use the following:
      http.addHeader("Content-Type", "application/json");
      // JSON data to send with HTTP POST
      String httpRequestData = "{\"airHumidity\":\"" + String(humidity()) + "\",\"airTemperature\":\"" + String(temperature()) + "\"}";           
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
     
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
        
      // Free resources
      http.end();
      ESP.restart();
}
}
