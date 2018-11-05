/* Ejemplo de interrupciones por hardware realizado por @laescuelamaker

Pines que permiten interrupciones en diferentes Arduinos:
                            -Pines-----------------
                UNO	        2	3
                Nano	    2	3
                Mini Pro	2	3
                Mega	    2	3	21	20	19	18
                Leonardo	3	2	0	1	7
                Due	        En todos los pines
*/

int led = 13;
int pulsador = 2;

volatile int estado = LOW;  // Variable se almacena en RAM, en lugar de en el bloque de datos

void setup(){
    pinMode(led, OUTPUT);
    pinMode(pulsador, INPUT);
    /*  Dentro de las interrupciones de hardware, que son las que nos ocupan en esta entrada,
        Arduino es capaz de detectar los siguientes eventos.
            RISING, ocurre en el flanco de subida de LOW a HIGH.
            FALLING, ocurre en el flanco de bajada de HIGH a LOW.
            CHANGING, ocurre cuando el pin cambia de estado (rising + falling).
            LOW, se ejecuta continuamente mientras está en estado LOW.
    */
    attachInterrupt(digitalPinToInterrupt(2), manejadorPulsador, RISING);
    digitalWrite(led, estado)
}

void manejadorPulsador(){
    estado = !estado;
}

void loop(){
    digitalWrite(led, estado);
}
