// saveConfiguration(filename, config);
//loadConfiguration(filename, config);

#pragma once
#include <ArduinoJson.h>
#include "FS.h"
#include "SPIFFS.h"


struct Config {
  String ssid;
  String password;
  String email;
  int temperature;
  int humidity;
  int moisture;
  };

char *filename = "/config.txt";  
Config config;                        


// Loads the
// configuration from a file
void loadConfiguration(char *filename, Config &config) {
  // Open file for reading
  File file = SPIFFS.open(filename);
  Serial.println("opened config file for reading");

  StaticJsonDocument<512> doc;

  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, file);
  if (error)
    Serial.println(F("Failed to read file, using default configuration"));

  // Copy values from the JsonDocument to the Config
  config.temperature = doc["temperature"] | 25;
  config.humidity = doc["humidity"] | 60;
  config.moisture = doc["moisture"] | 70;
  config.ssid = doc["ssid"] | "isempty";
  config.password = doc["password"] | "isempty";
  config.email = doc["email"] | "isempty";
  file.close();
}

// Saves the configuration to a file
void saveConfiguration(char *filename, const Config &config) {
  SPIFFS.remove(filename);

  // Open file for writing
  File file = SPIFFS.open(filename, FILE_WRITE);
  if (!file) {
    Serial.println(F("Failed to create file"));
    return;
  }

  // Allocate a temporary JsonDocument
  StaticJsonDocument<512> doc;

  // Set the values in the document
  doc["temperature"] = config.temperature;
  doc["humidity"] = config.humidity;
  doc["moisture"] = config.moisture;
  doc["ssid"] = config.ssid;
  doc["password"] = config.password;
  doc["email"] = config.email;


  
  // Serialize JSON to file
  if (serializeJson(doc, file) == 0) {
    Serial.println(F("Failed to write to file"));
  }

  // Close the file
  file.close();
}

 
