// ============================================================
// Laboratorio: Micrófono básico
// Lee la señal del micrófono y la muestra por monitor serial
// ============================================================

// Pin del micrófono
int sensorPin = 0;
// Valor leído del micrófono
int sensorVal = 0;

// CONFIGURACIÓN INICIAL
void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);
}

// PROGRAMA PRINCIPAL
void loop() {
  // Leer el valor del micrófono
  sensorVal = analogRead(sensorPin);

  // Mostrar el valor en el monitor serial
  Serial.println(sensorVal);

  // Esperar medio segundo antes de la siguiente lectura
  delay(500);
}
