// ============================================================
// Laboratorio: Prueba de pulsador con secuencia de alarma
// Detecta la temperatura y activa una secuencia de LEDs
// ============================================================

// PINES LEDs
// Pines del LED RGB
int red = 6;
int green = 5;
int blue = 3;
// Pines de los tres LED normales
int led1 = 9;
int led2 = 10;
int led3 = 11;
// Pines de los LED de la secuencia de alarma
int ledverde1 = 12;
int ledverde2 = 13;
int ledamarillo1 = 7;
int ledamarillo2 = 8;
int ledrojo1 = 4;

// Pines de sensores y pulsador
float sensorPin = A0;
float sensorPin2 = A1;
float potenciometro = A2;
int pulsador = 2;

// Variables de lectura
int sensorVal = 0;
int sensorVal2 = 0;
int ValPul;
int a;
float temperatura;
int B = 3975;
float resistance;

// CONFIGURACIÓN INICIAL
void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);

  // Configurar el LED RGB como salida
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  // Configurar los tres LED normales como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Configurar los LED de la secuencia como salidas
  pinMode(ledverde1, OUTPUT);
  pinMode(ledverde2, OUTPUT);
  pinMode(ledamarillo1, OUTPUT);
  pinMode(ledamarillo2, OUTPUT);
  pinMode(ledrojo1, OUTPUT);

  // Configurar el pulsador como entrada
  pinMode(pulsador, INPUT);

  // Inicializar los tres LED apagados
  analogWrite(led1, 255);
  analogWrite(led2, 255);
  analogWrite(led3, 255);
}

// SECUENCIA DE LOS LEDS
void secuenciaAlarma() {
  // Apagar todos los LED de la secuencia
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarillo1, LOW);
  digitalWrite(ledamarillo2, LOW);
  digitalWrite(ledrojo1, LOW);

  // Encender los LEDs en secuencia
  digitalWrite(ledverde1, HIGH);
  delay(150);
  digitalWrite(ledverde2, HIGH);
  delay(150);
  digitalWrite(ledamarillo1, HIGH);
  delay(150);
  digitalWrite(ledamarillo2, HIGH);
  delay(150);

  // Encender el LED rojo y mantenerlo un poco más
  digitalWrite(ledrojo1, HIGH);
  delay(300);

  // Apagar en orden inverso
  digitalWrite(ledamarillo2, LOW);
  delay(150);
  digitalWrite(ledamarillo1, LOW);
  delay(150);
  digitalWrite(ledverde2, LOW);
  delay(150);
  digitalWrite(ledverde1, LOW);
  delay(150);

  // Pausa antes de repetir
  delay(100);
}

// PROGRAMA PRINCIPAL
void loop() {
  // Si la temperatura supera el umbral, activar la alarma
  if (temperatura > 27) {
    // LED RGB de color verde azulado
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue, 80);

    // Leer el estado del pulsador
    ValPul = digitalRead(pulsador);

    // Activar la secuencia solo si se presiona el pulsador
    if (ValPul == HIGH) {
      secuenciaAlarma();
    } else {
      // Mantener los LED de la secuencia apagados
      digitalWrite(ledverde1, LOW);
      digitalWrite(ledverde2, LOW);
      digitalWrite(ledamarillo1, LOW);
      digitalWrite(ledamarillo2, LOW);
      digitalWrite(ledrojo1, LOW);
    }
  }

  // Mostrar la temperatura en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  // Esperar un segundo antes del siguiente ciclo
  delay(1000);
}
