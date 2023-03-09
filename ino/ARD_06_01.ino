/* ---------------------------------------------
  CartroTECH  www.cartrocreatiu.es
  Codi: ARD_06_01.ino
  Lliçó: 06 - Les eixides analogiques
  Data: 26/03/2021
  ------------------------------------------- */


void setup()
{
  pinMode( 9, OUTPUT) ;
}
void loop()
{
  for ( int i = 0 ; i < 255 ; i++)
  {
    analogWrite (9, i) ;
    delay( 10);
  }
}
