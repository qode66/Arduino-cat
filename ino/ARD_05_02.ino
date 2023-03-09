/* ----------------------------------------------------------------
CartroTECH	www.cartrocreatiu.es
Codi: ARD_05_02.ino
Lliçó: 05 - Les entrades analogiques
Data: 21/03/2021
---------------------------------------------------------------- */

void setup()
   {
     Serial.begin(9600); 
   }

void loop()
   {
     unsigned long T ;
         int n = 0 ;
         T = millis();

         while (millis() <= T + 1000)      // Mentre no passe un Segon = 1000 ms
             {
               analogRead( A5) ;
               n++ ;                       // Comptem cada vegada que llegim
             }
         Serial.println(n);
   }
