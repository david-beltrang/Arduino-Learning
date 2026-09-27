/*
 * ============================================================
 * Nombre       : Proyecto 1
 * Autor        : Yerson Gomez Gomez - David Beltran Gomez
 * Fecha        : Septiembre 26
 * Plataforma   : Arduino
 * ============================================================
*/
// DECLARACIÓN DE PINES Y VARIABLES
// Pin del sensor de temperatura
float pin_Sensor_Temperatura = A0;
// Pin del sensor de sonido
float pin_Sensor_Sonido = A1;
// Lectura del sensor de sonido
int valor_Sonido = 0;
// Pin del potenciómetro
float pin_Potenciometro = A2;
// Valor leído del potenciómetro
int valor_Potenciometro;
// Lectura analógica del sensor de temperatura
int a;
// Temperatura calculada
float temperatura;
// Constante para el cálculo de la temperatura
int B = 3975;
// Resistencia calculada a partir de la lectura del sensor
float resistencia;
// Pin del pulsador
int pin_Pulsador = 2;
// Estado leído del pulsador
int estado_Pulsador;
// Velocidad de dada por el potenciometro
int velocidad;
// Delay a aplicar a la secuencia de alarma
int delaySecuencia = 0;

// PINES LEDs
// Pines del LED RGB
int led_RGB_Red = 6;
int led_RGB_Green = 5;
int led_RGB_Blue = 3;
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


// CONFIGURACIÓN INICIAL
void setup() {
  Serial.begin(9600);
  // Configurar el LED RGB como salida
  pinMode(led_RGB_Red, OUTPUT);
  pinMode(led_RGB_Green, OUTPUT);
  pinMode(led_RGB_Blue, OUTPUT);

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
  pinMode(pin_Pulsador, INPUT);

  // Inicializar los tres LED Apagados
  analogWrite(led1, 255);
  analogWrite(led2, 255);
  analogWrite(led3, 255);
}


// SECUENCIA DE LOS LEDS
// La velocidad depende del valor leído en el Potenciómetro
void secuenciaLeds(int velocidad) {
  // Apagar todos los LED de la secuencia
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarillo1, LOW);
  digitalWrite(ledamarillo2, LOW);
  digitalWrite(ledrojo1, LOW);

  // Encender el primer LED verde
  digitalWrite(ledverde1, HIGH);
  delay(velocidad);
  // Encender el segundo LED verde
  digitalWrite(ledverde2, HIGH);
  delay(velocidad);
  // Encender el primer LED amarillo
  digitalWrite(ledamarillo1, HIGH);
  delay(velocidad);
  // Encender el segundo LED amarillo
  digitalWrite(ledamarillo2, HIGH);
  delay(velocidad);
  // Encender el LED rojo y mantenerlo el doble de tiempo
  digitalWrite(ledrojo1, HIGH);
  delay(velocidad * 2);
  // Iniciar el recorrido de regreso
  digitalWrite(ledamarillo2, LOW);
  delay(velocidad);
  // Apagar el primer LED amarillo
  digitalWrite(ledamarillo1, LOW);
  delay(velocidad);
  // Apagar el segundo LED verde
  digitalWrite(ledverde2, LOW);
  delay(velocidad);
  // Apagar el primer LED verde
  digitalWrite(ledverde1, LOW);
  delay(velocidad);
  // Apagar el LED rojo
  digitalWrite(ledrojo1, LOW);
  delay(velocidad);
  // Realizar una pausa antes de repetir la secuencia
  delay(200);
}

// PROGRAMA PRINCIPAL
void loop() {
  // Leer el sensor de sonido
  valor_Sonido = analogRead(pin_Sensor_Sonido);
  // Leer el sensor de temperatura
  a = analogRead(pin_Sensor_Temperatura);
  // Calcular la resistencia a partir de la lectura analógica
  resistencia = (float)(1023 - a) * 10000 / a;
  // Convertir la resistencia en temperatura
  temperatura = 1 / (log(resistencia / 10000) / B + 1 / 298.15) - 273.15;
  // Leer el potenciómetro
  valor_Potenciometro = analogRead(pin_Potenciometro);
  // Esperar un segundo antes de mostrar la lectura
  delay(1000);
  // Mostrar la temperatura en el monitor serial
  Serial.print("Temperatura actual: ");
  Serial.println(temperatura);

  // CONDICIONES PARA LAS ACCIONES
  // Primera condición (Temperatura menor de 25 °C)
  if (temperatura < 25)  {
    // LED RGB de color Naranja
    analogWrite(led_RGB_Red, 0);
    analogWrite(led_RGB_Green, 225);
    analogWrite(led_RGB_Blue, 255);
  }

  // Segunda condición (Temperatura entre 25 °C y 35 °C)
  else if (temperatura > 25 && temperatura <= 35) {
    // LED RGB con el color Violeta
    analogWrite(led_RGB_Red, 0);
    analogWrite(led_RGB_Green, 255);
    analogWrite(led_RGB_Blue, 0);

    // Comprobar si la lectura del sensor de sonido supera el valor 32
    if (valor_Sonido > 32) {
      // Repetir el ciclo de fade in y fade out 4 veces
      for (int i = 0; i < 4; i++) {
        // FADE IN: Disminuir el brillo desde 255 hasta 0
        for (int brillo = 255; brillo >= 0; brillo--) {
          analogWrite(led1, brillo);
          analogWrite(led2, brillo);
          analogWrite(led3, brillo);
          delay(5);
        }

        // FADE OUT: Aumentar el brillo desde 0 hasta 255
        for (int brillo = 0; brillo <= 255; brillo++) {
          analogWrite(led1, brillo);
          analogWrite(led2, brillo);
          analogWrite(led3, brillo);
          delay(5);
        }

        // Apagar los tres LED
        analogWrite(led1, 255);
        analogWrite(led2, 255);
        analogWrite(led3, 255);
      }
    }
  }

  // Tercera condición (Temperatura mayor de 35 °C)
  else if (temperatura > 35) {
    // LED RGB de color VerdeAzulado
    analogWrite(led_RGB_Red, 255);
    analogWrite(led_RGB_Green, 0);
    analogWrite(led_RGB_Blue, 80);

    // Leer el estado del pulsador
    estado_Pulsador = digitalRead(pin_Pulsador);
    delay(1000);
    // Leer el potenciómetro
    valor_Potenciometro = analogRead(pin_Potenciometro);
    // Convertir el valor del potenciómetro en la velocidad de la secuencia
    velocidad = map(valor_Potenciometro, 0, 1023, 500, 50);
    // Convertir la velocidad en Delay
    // Velocidad 0 -> Delay 500 ms
    // Velocidad 500 -> Delay 50 ms
    delaySecuencia = map(velocidad, 0, 500, 500, 50);

    // Mostrar el valor del potenciómetro
    Serial.print("Potenciometro: ");
    Serial.print(valor_Potenciometro);
    // Mostrar la velocidad de la secuencia
    Serial.print(" | Velocidad: ");
    Serial.print(velocidad);
    // Mostrar el delay de la secuencia
    Serial.print(" | Delay: ");
    Serial.println(delaySecuencia);
    
    // Activar la secuencia si se presiona el pulsador
    if (estado_Pulsador == HIGH) {
      Serial.println("Pulsador Presionado");
      secuenciaLeds(velocidad);
    }
    else {
      Serial.println("Pulsador NO Presionado");

      // Dejar apagados los cinco LED de la secuencia
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

  // Mostrar la lectura del sensor de sonido
  Serial.print("Sonido: ");
  Serial.print(valor_Sonido);
  Serial.println(" dB");

  // Esperar un segundo antes de comenzar el siguiente ciclo
  delay(1000);
}
