// ============================================================
// Laboratorio: LED con Pulsador
// Enciende el LED cuando se presiona el botón
// ============================================================

// Pin del pulsador
int pulsador = 3;
// Pin del LED
int led = 13;
// Estado leído del pulsador
int valPul;

// CONFIGURACIÓN INICIAL
void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);
  // Configurar el LED como salida
  pinMode(led, OUTPUT);
  // Configurar el pulsador como entrada
  pinMode(pulsador, INPUT);
}

// PROGRAMA PRINCIPAL
void loop() {
  // Leer el estado del pulsador
  valPul = digitalRead(pulsador);

  // Mostrar el estado por monitor serial
  Serial.println(valPul);

  // Si el pulsador está presionado, encender el LED
  if (valPul == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    // Si no está presionado, apagar el LED
    digitalWrite(led, LOW);
  }

  // Esperar un segundo antes del siguiente ciclo
  delay(1000);
}
