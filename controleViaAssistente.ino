#include <ESP8266WiFi.h>   
#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID     "REP"
#define WIFI_PASS     "18032022"
#define APP_KEY       "cc19f812-a3ae-4c7f-bf80-1160d7b2c18a"
#define APP_SECRET    "2ace9b6d-4d81-46a9-98f8-b51f7ed15264-36cc2ed5-5222-4261-8b17-8c4cfcdf65c8"

// ID do dispositivo (copie do portal Sinric Pro)
#define Abajour_ID        "67df070abddfc53e33bd5ab3"

// Pino do dispositivo (GPIO seguro)
#define Abajour_Pin        15  // D1

// Baud rate
#define BAUD_RATE 9600


// Protótipos
void setupWiFi();
void setupSinricPro();
bool AbajourState(const String &deviceId, bool &state);


void setup() {
  Serial.begin(BAUD_RATE); Serial.printf("\r\n\r\n");
  setupWiFi();
  setupSinricPro(); 

  // Configura o pino como saída
  pinMode(Abajour_Pin, OUTPUT);

}

void loop() {
  SinricPro.handle();
}


// Função para alterar o estado do dispositivo
bool AbajourState(const String &deviceId, bool &state) {
  Serial.printf("Abajour %s\r\n", state ? "ligado" : "desligado");
  //digitalWrite(Abajour_Pin, state);
  if (state) {
    digitalWrite(Abajour_Pin, LOW);  // Ligar o abajur
  } else {
    digitalWrite(Abajour_Pin, HIGH);   // Desligar o abajur
  }
  return true;
}


// Conexão WiFi
void setupWiFi() {
  Serial.printf("\r\n[WiFi] Conectando...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf(".");
    delay(250);
  }
  Serial.printf("\r\n[WiFi] Conectado! IP: %s\r\n", WiFi.localIP().toString().c_str());
}


// Conexão Sinric Pro
void setupSinricPro() {
  SinricProSwitch &s1 = SinricPro[Abajour_ID];
  s1.onPowerState(AbajourState);

  SinricPro.onConnected([]() {
    Serial.println("[SinricPro] Conectado à nuvem!");
  });
  
  SinricPro.onDisconnected([]() {
    Serial.println("[SinricPro] Desconectado da nuvem.");
  });

  SinricPro.begin(APP_KEY, APP_SECRET);
}