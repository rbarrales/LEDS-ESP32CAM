/*Fecha:        14.10.21
 * Autor:       Raymundo Barrales.
 * Título:      TAREA: Secuencia no bloqueante de 3 LEDs.
 * Descripción: Este programa hace parpadear 3 LEDs utilizando
 *              secuencias no bloqueantes.
 *              LED1 cada 5 seg.
 *              LED2 cada 3 seg.
 *              LED3 cada 1 seg.
 *            
 *  LEDs     GPIO ESP32CAM
 *  
 *  LED1    13
 *  LED2    14
 *  LED3    15
 */

// Bibliotecas

// Constantes globales
const int LED1=13;
const int LED2=14;
const int LED3=15;

// Tiempos de espera
const int wait5 = 5000;
const int wait3 = 3000;
const int wait1 = 1000;

//Variables globales
unsigned long timeLast5, timeLast3, timeLast1, timeNow;
bool datoLed1 = 0;
bool datoLed2 = 0;
bool datoLed3 = 0;

//Condiciones iniciales
void setup() {
  // Inicialización de la comunicación serie
  Serial.begin(115200);
  Serial.print("Programa iniciado");

  // Terminales ESP32CAM en modo salida para los LEDs
  pinMode (LED1,OUTPUT);
  pinMode (LED2,OUTPUT);
  pinMode (LED3,OUTPUT);

  // Los LEDs inician apagados
  digitalWrite (LED1, HIGH);
  digitalWrite (LED2, HIGH);
  digitalWrite (LED3, HIGH);

  // Secuencias de tiempo
  timeLast5 = millis();
  timeLast3 = timeLast5;
  timeLast1 = timeLast5;
} // Cierra el setup

void loop() {
  // Cuerpo del programa
  timeNow = millis();

  // Conteo cada 5 seg
  if (timeNow - timeLast5 > wait5){
  // Método para cambiar el estado del LED
    toggleLED(LED1, datoLed1);
    datoLed1 != datoLed1;
    timeLast5 = millis();
  } // Se cierra if conteo 5 seg

  // Conteo cada 3 seg
  if (timeNow - timeLast3 > wait3){
  // Método para cambiar el estado del LED
    toggleLED(LED2, datoLed2);
    datoLed2 != datoLed2;
    timeLast3 = millis();
  } // Se cierra if conteo 3 seg

  // Conteo cada 1 seg
  if (timeNow - timeLast1 > wait1){
  // Método para cambiar el estado del LED
    toggleLED(LED3, datoLed3);
    datoLed3 != datoLed3;
    timeLast1 = millis();
  } // Se cierra if conteo 1 seg
}

// Funciones del usuario
  void toggleLED(int pinLed, bool estado){
    // Cuerpo de la función
    digitalWrite(pinLed, estado);
  } // Se cierra la función
