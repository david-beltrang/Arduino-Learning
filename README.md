# Arduino Learning

Repositorio con los ejercicios, laboratorios y proyectos que voy desarrollando mientras aprendo Arduino, electrónica y sistemas embebidos.

## Contenido

### Laboratorios (`labs/`)

| Laboratorio | Descripción |
|---|---|
| `LM35-temperature-sensor` | Lectura de temperatura con el sensor LM35 |
| `led-with-photoresistor` | Control de un LED según la luz ambiente (LDR) |
| `push-button-test` | Prueba de lectura de pulsador |
| `microfono-basics` | Lectura básica de un micrófono/amplificador de sonido |
| `led-with-push-button` | Encendido de LED con pulsador |
| `sensor_Temperatura_Pro` | Cálculo de temperatura con termistor (ecuación de Steinhart-Hart) |

### Proyectos (`projects/`)

| Proyecto | Descripción |
|---|---|
| `first-project` | Sistema de monitoreo con sensor de temperatura, micrófono, potenciómetro, pulsador, LED RGB y secuencia de LEDs. Incluye lógica de alarma y efectos de fade |

## Requisitos

- Arduino IDE 2.x (o VSCode con la extensión de Arduino)
- Placa Arduino (Uno, Nano o compatible)
- Componentes electrónicos según cada ejercicio (LEDs, resistencias, sensores, pulsadores, potenciómetro, protoboard)

## Cómo usar

1. Clona el repositorio:
   ```bash
   git clone https://github.com/tu-usuario/Arduino-Learning.git
   ```
2. Abre la carpeta del laboratorio o proyecto que te interese
3. Abre el archivo `.ino` con Arduino IDE (o VSCode)
4. Conecta tu placa, selecciona el puerto y sube el código

## Estructura del repositorio

```
Arduino-Learning/
├── labs/
│   ├── LM35-temperature-sensor/
│   ├── led-with-photoresistor/
│   ├── push-button-test/
│   ├── microfono-basics/
│   ├── led-with-push-button/
│   └── sensor_Temperatura_Pro/
├── projects/
│   └── first-project/
└── README.md
```

## Notas

- Cada sketch es autocontenido y no requiere librerías externas
- Los pines están comentados en cada archivo para facilitar el montaje
- El repositorio se actualiza a medida que avanzo en el aprendizaje
