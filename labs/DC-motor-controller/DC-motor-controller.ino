int motorPin =3; // Pin digital donde se conecta el motor
int velocidad;

void setup(){
  Serial.begin(9600);
  while(!Serial); //Verifica si el puerto serial esta bien configurado
  Serial.println("Digite una velocidad entre 0 y 255");
}

void loop(){
  //Verifica si el puerto serial esta listo para leerse
  if(Serial.available()){
    velocidad=Serial.parseInt(); //Lee la velocidad enviada por la entrada serial

    // Velocidad del motor entre 0 y 255
    if(velocidad>=0 && velocidad<=255){
      analogWrite(motorPin, velocidad); //Gira el motor con la velocidad de entrada
      // Imprime la velocidad en el monitor serial
      Serial.print("Velocidad:");
      Serial.println(velocidad);
      delay(1000);
    }
  }
}