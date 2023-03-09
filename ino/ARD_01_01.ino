/*  ----------------------------------------------------------------
CartroTech (www.cartrocreatiu.es)
ARD_01.ino
01 El nostre primer programa
Blinking LED
--------------------------------------------------------------------  
*/


void setup()
{
  pinMode( 13 , OUTPUT);                // Usarem el pin 13 com eixida
}

void loop()
{
  digitalWrite(13 , HIGH);                  // Encén el LED
  delay(1000);                              // Esperar un segon
  digitalWrite(13 , LOW);                   // Apague el LED
  delay(1000);                              // Esperar un segon
}
