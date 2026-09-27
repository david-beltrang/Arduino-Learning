// ============================================================
// Laboratorio: Sensor de temperatura LM35
// Lee la temperatura ambiente y la muestra por monitor serial
// ============================================================

// Pin del sensor de temperatura
int sensorPin = 0;
// Valor leído del sensor
int sensorVal = 0;
// Temperatura calculada en grados Celsius
float temperatura;

// CONFIGURACIÓN INICIAL
void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);
}

// PROGRAMA PRINCIPAL
void loop() {
  // Leer el valor analógico del sensor
  sensorVal = analogRead(sensorPin);
  // Convertir la lectura a temperatura (10 mV por grado)
  temperatura = ((sensorVal * 5.0) / 1024) / 0.01;

  // Mostrar la temperatura en el monitor serial
  Serial.println(temperatura);

  // Esperar medio segundo antes de la siguiente lectura
  delay(500);
}
