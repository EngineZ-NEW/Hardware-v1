#pragma once
#include <WiFi.h>
#include <WiFiClient.h> 
#include <WebServer.h>
#include <HTTPClient.h>
#include "Interface.h"

const char *ssid = "ESP32";

String WIFIssid;
String WIFIpassword;
String email;
String WIFItemperature;
String WIFIhumidity;
String WIFImoisture;

WebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>request for esp</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>
  <form  name='frm'  method='post'>
  WIFI ssid: <input type="text" name="WIFIssid"><br>
  WIFI password: <input type="text" name="WIFIpassword"><br>
  Registered email: <input type="text" name="email"><br>
  Optional:<br>
  Temperature Level (celsius):<input type="text" name="WIFItemperature"> <br>
  Humidity Level (%):<input type="text" name="WIFIhumidity"><br>
  Soil Moisture Level (%):<input type="text" name="WIFImoisture"><br>
  <input type="submit" value="Submit">
  </form><br>
  </body></html>)rawliteral";

WiFiClient client;
void webpage() {
  server.send(200, "text/html", index_html);
}

void response(){
  if(server.hasArg("WIFIssid") && (server.arg("WIFIssid").length()>0) && server.hasArg("WIFIpassword") && (server.arg("WIFIpassword").length()>0) && server.hasArg("email") && server.arg("email").length()>0){
    config.ssid = server.arg("WIFIssid");
    config.password = server.arg("WIFIpassword");
    config.email = server.arg("email");
    config.temperature = server.arg("WIFItemperature").toInt();
    config.humidity = server.arg("WIFIhumidity").toInt();
    config.moisture = server.arg("WIFImoisture").toInt(); 
    server.send(200, "text/html", "<html><body><h1>Successful</h1><a href='/'>Home</a></body></html>");
  } else {
    server.send(400, "text/html", "<html><body><h1>HTTP Error 400</h1><p>Bad request. Please enter a value.</p></body></html>");
  }
}
void logpage(){
  Serial.println();
  Serial.println("Configuring access point...");
  Serial.println();
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.println("AP IP address: ");
  Serial.println(myIP);
  server.on("/",HTTP_GET, webpage);
  server.on("/",HTTP_POST,response);
  server.begin();
  Serial.println();
  Serial.println("HTTP server started");
  }
