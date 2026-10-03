int speakerSensor = 2;
int duracionNota = 100;
int sensorPin = 5; //Pin analogo donde se conecta el sensor
int valorSensor = 0; //Declara variable para guardar valor del sensor
int valorNota = 0; //Declara variable para guardar la nota

// Declaración de la frecuencia de las notas musicales (Hz)
int note_DO = 262;
int note_RE = 294;
int note_MI = 330;
int note_FA = 349;
int note_SOL = 392;
int note_LA = 440;
int note_SI = 494;
int note_DO2 = 523;

void setup(){
  pinMode(speakerSensor, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  valorSensor = analogRead(sensorPin) + 200;

//
    if(valorSensor<200) {
        valorNota=note_DO;
    }
    else if(valorSensor>200 && valorSensor<230) {
        valorNota=note_RE;
    }
    else if(valorSensor>230 && valorSensor<260) {
        valorNota=note_MI;
    }
    else if(valorSensor>260 && valorSensor<290) {
        valorNota=note_FA;
    }
    else if(valorSensor>290 && valorSensor<320) {
        valorNota=note_SOL;
    }
    else if(valorSensor>320 && valorSensor<350) {
        valorNota=note_LA;
    }
    else if(valorSensor>350 && valorSensor<380) {
        valorNota=note_SI;
    }
    else if(valorSensor>410){
        valorNota=note_DO2;
    }

    // Muestra el valor del sensor en el monitor serial
    Serial.println(valorSensor);
    // Hace sonar la nota correspondiente en el buzzer
    tone(speakerSensor, valorNota, duracionNota);
    delay(10);
}