// ============================================================
// Laboratorio: Sensor de temperatura con termistor
// Calcula la temperatura usando la ecuación de Steinhart-Hart
// ============================================================

#include <math.h>

// Lectura analógica del sensor
int a;
// Temperatura calculada en grados Celsius
float temperature;
// Constante B del termistor
int B = 3975;
// Resistencia calculada a partir de la lectura
float resistance;

// CONFIGURACIÓN INICIAL
void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);
}

// PROGRAMA PRINCIPAL
void loop() {
  // Leer el valor analógico del termistor
  a = analogRead(0);

  // Calcular la resistencia del termistor
  resistance = (float)(1023 - a) * 10000 / a;

  // Convertir la resistencia a temperatura
  temperature = 1 / (log(resistance / 10000) / B + 1 / 298.15) - 273.15;

  // Esperar un segundo antes de mostrar la lectura
  delay(1000);

  // Mostrar la temperatura en el monitor serial
  Serial.print("Current temperature is ");
  Serial.println(temperature);
}
