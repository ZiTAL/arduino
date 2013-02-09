/*
  Libreria LiquidCrystal - Hola Mundo
 
 Demostración del uso de una pantalla LCD de 16x2 caracteres.
 La libreria LiquidCrystal funciona con todas las pantallas LCD que
 sean compatibles con el driver "Hitachi HD44780".

 Existen muchas ahí fuera y normalmente podrás reconocerlas por su
 interfaz de 16 pines.
 
 Este sketch imprime "Hello World!" en la pantalla LCD
 y muestra el tiempo que lleva encendida.
 
  El circuito:
 1.- Pin (-) del LCD a tierra
 2.- Pin (+) del LCD a la alimentación (de 3.3V a 5V)
 3.- Pin V0 del LCD al pin de salida del potenciometro
 4.- Pin RS del LCD al pin digital 12 del Arduino
 5.- Pin Enable del LCD al pin digital 11 del Arduino
 6.- Pin D0 del LCD no es utilizado en modo 4 bit
 7.- Pin D1 del LCD no es utilizado en modo 4 bit
 8.- Pin D2 del LCD no es utilizado en modo 4 bit
 9.- Pin D3 del LCD no es utilizado en modo 4 bit
 10.- Pin D4 del LCD al pin digital 5 del Arduino
 11.- Pin D5 del LCD al pin digital 4 del Arduino
 12.- Pin D6 del LCD al pin digital 3 del Arduino
 13.- Pin D7 del LCD al pin digital 2 del Arduino
 14.- Pin R/W del LCD al pin GND (tierra)
 15.- Anodo (Pin +) de retroiluminación a 3.3V o 5V
 16.- Catodo (Pin -) a GND (tierra)
 
 Libreria añadida originalmente el 18 Abr 2008
 por David A. Mellis
 libreria modificada el 5 Jul 2009
 por Limor Fried (http://www.ladyada.net)
 ejemplo añadido el 9 Jul 2009
 por Tom Igoe
 modificado el 22 Nov 2010
 por Tom Igoe
 Traducido al espanol el 20 Jun 2012
 por Javier Collado (http://www.loleando.com)
 
 Este codigo de ejemplo es de dominio publico.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// Incluimos la libreria en el codigo:
#include <LiquidCrystal.h>

// iniciamos la libreria con los numeros de los pines de la interfaz
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // configuramos el numero de columnas y filas del LCD: 
  lcd.begin(16, 2);
  // Imprimimos un mensaje al LCD.
  lcd.print("hack.in#badakigu");
}

void loop() {
  // Colocamos el cursor en la columna 0, linea 1
  // (nota: linea 1 es la segunda fila, la cuenta comienza en el 0):
  lcd.setCursor(0, 1);
  // imprimimos el numero de segundos desde el reinicio:
  lcd.print(millis()/1000);
}
