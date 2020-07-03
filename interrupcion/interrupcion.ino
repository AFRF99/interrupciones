/*
Se define el pin digital 10 como salida,
para emular una onda cuadrada de periodo 300ms (150ms ON y 150ms OFF).
Para visualizar el funcionamiento de la interrupción,
en cada flanco activo del pulso simulado,
se enciende/apaga el LED integrado en la placa.
No se encendiendo el LED con una salida digital,
si no que es la interrupción que salta la que enciende y apaga el LED (el pin digital solo emula una señal externa).
*/
//se define las variables 
const int salidaPin = 10;
const int LEDPin = 13;
const int intPin = 2;
volatile int state = LOW;
//se produce la interrupcion  
void setup() {
    pinMode(salidaPin, OUTPUT);
    pinMode(LEDPin, OUTPUT);
    pinMode(intPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(intPin), blink, RISING);
}
  
void loop() {
    //esta parte es para emular la salida
    digitalWrite(salidaPin, HIGH);
    delay(150);
    digitalWrite(salidaPin, LOW);
    delay(150);
}
//se cambia el estado del led 
void blink() {
    state = !state;
    digitalWrite(LEDPin, state);
}
