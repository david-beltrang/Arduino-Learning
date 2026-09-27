// ============================================================
// Laboratorio: LED con fotorresistencia
// Enciende el LED cuando hay poca luz ambiente
// ============================================================

// Pin del LED
int ledPin = 9;
// Valor leído del sensor de luz
int sensorVal = 0;
// Pin del fotorresistencia
int sensorPin = 0;

// CONFIGURACIÓN INICIAL
void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);
  // Configurar el LED como salida
  pinMode(ledPin, OUTPUT);
  // Las entradas analógicas no necesitan pinMode
}

// PROGRAMA PRINCIPAL
void loop() {
  // Leer la cantidad de luz ambiente
  sensorVal = analogRead(sensorPin);
  // Mostrar el valor leído
  Serial.println(sensorVal);

  // Si hay poca luz, encender el LED
  if (sensorVal < 170) {
    digitalWrite(ledPin, LOW);
  } else {
    // Si hay suficiente luz, apagar el LED
    digitalWrite(ledPin, HIGH);
  }

  // Pequeña pausa antes de la siguiente lectura
  delay(100);
}
