/* ----------------------------------------------------------------
CartroTECH	www.cartrocreatiu.es
Codi: ARD_05_01.ino
Lliçó: 05 - Les entrades analogiques
Data: 21/03/2021
---------------------------------------------------------------- */

void setup()
    {
       Serial.begin(9600);    // Iniciem la porta serie
    }
void loop()
    {
       int Lectura = analogRead(A5) ;
       Serial.println( Lectura);
       delay(200) ;
    }
