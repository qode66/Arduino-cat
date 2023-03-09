/*  ----------------------------------------------------------------
  CartroTech (www.cartrocreatiu.es)
  ARD_02_01.ino
  17.03.2021
  03 Les entrades digitals de arduino

  --------------------------------------------------------------------
*/

int LED = 10 ;
int boto = 6;

void setup()
{
  pinMode( LED, OUTPUT) ;     // LED com a eixida
  pinMode( boto  , INPUT) ;    // botó com a entrada
}

void loop()
{
  int valor = digitalRead(boto) ;  // llegim el valor de boto en valor
  digitalWrite( LED, valor) ;
}
