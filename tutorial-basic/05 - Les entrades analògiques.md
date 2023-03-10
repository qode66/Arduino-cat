# 05 - Les entrades analògiques

[img1]: ./Imatges/ard_05_01.png "Esquema elèctric"
[img2]: ./Imatges/ard_05_02.png "Connexió d'un potenciòmetre"
[img3]: ./Imatges/ard_05_03.png "Conversió analògic-digital"
[img4]: ./Imatges/ard_05_04.png "Entrades analògiques"
[img5]: ./Imatges/ard_05_05.png "Esquema de muntatge"
[img6]: ./Imatges/ard_05_06.png "Eixida pel monitor sèrie"

## Objectius

- Conéixer els potenciòmetres.
- Comprendre la conversió analògica a digital.
- Aprendre a usar les portes analògiques de Arduino.

## Material requerit

- Arduino UNO o equivalent
- Protoboard
- Cables de connexió
- Un potenciòmetre
- Un díode led
- Una resistència de 330 Ohms

## Els potenciòmetres

Fins ara hem usat sempre resistències fixes, d'un valor donat. Però a vegades és convenient disposar d'un senyal variable per a controlar el circuit que ens interessa. Imagineu el volum d'un equip de música, o el dial que sintonitza una emissora en una ràdio FM.

Un potenciòmetre és, simplement, un mecanisme per a proporcionar una resistència variable.

Hi ha potenciòmetres de tantes grandàries, formes i acolorisca,s com pugueu imaginar, però al final són una resistència fixa d'un valor donat (10 kΩ en el nostre cas actual) i un mecanisme que permeta lliscar un dial conductor sobre aqueixa resistència, que ens permeta prendre una part d'aqueix valor.

Per això un potenciòmetre sempre té 3 pins en fila. Els de l'extrem es comporten com una resistència del valor de fons d'escala del potenciòmetre, i un pin central que va prenent valors de resistència en funció del moviment que fem amb l'ajust.

Muntarem un circuit com aquest (en el qual el potenciòmetre aquesta retolat Pot1):

![Esquema elèctric][img1]

La idea és connectar 5V i GND als extrems del Potenciòmetre (no importa com és l'un i l'altre) i després connectar el pin central al positiu de un LED i el negatiu a GND directe, passant per una resistència de limitació.

D'aquesta manera quan girem el potenciòmetre estarem modificant la tensió que apliquem a l'entrada del LED, que variara entre 0 i 5V (Encara que ara semble estrany és molt senzill) i haurem aconseguit un regulador d'intensitat del LED.

- _Amb una resistència de 10k la intensitat en el circuit serà de: 5V / 10.000Ω = 0,5 mA. Molt poc per a aconseguir il·luminar el LED que requereix uns 20 mA. Així que durant la major part del gir del potenciòmetre el LED estarà apagat._
- _Important: No oblides la resistència R1.Encara que el potenciòmetre limite la intensitat, hi ha un moment en què arribara a zero i ací i el teu LED morirà en acte de servei._

## Circuit per a protoboard

El muntatge en la protoboard seria similar a això ja que utilitzarem el Arduino simplement per a donar tensió al circuit i res més, Veureu que la intensitat de la llum vària de manera contínua en girar el potenciòmetre.

![Potenciòmetre mès led][img2]

- _Recorda que a causa de l'excés de resistència del potenciòmetre de prova, durant la major part del gir de l'ajust el LED estarà apagat._
- _Note's que en aquest cas utilitzem el nostre Arduino simplement com a font d'alimentació per a donar tensió al circuit._

## Arduino i les entrades analògiques

Amb Arduino hem vist que podem influir en el món exterior aplicant eixides tot / res en els pins digitals i també que usant PWM podem simular bastant satisfactòriament senyals analògics en alguns
d'aqueixos pins.

També hem vist com detectar pulsacions de botons, definint com a entrades els pins digitals. Però en moltes ocasions els sensors que usem per a supervisar el món exterior, ens entreguen un senyal analògic. És el cas dels sensors de temperatura o distància, de pressió, d'intensitat de corrent en un circuit o de cabal d'aigua en una canonada.

Per a llegir aquest tipus de senyals continus necessitem un convertidor analògic a digital (o ADC per les seues sigles en anglés) i que ens permet llegir el valor d'un senyal analògic en un moment donat.

Aquests convertidors prenen una mostra del valor actual del senyal i ens entreguen el seu _valor instantani_, mesurat en Volts.

Mitjançant la lectura repetida de mostres al llarg del temps podem reconstruir el senyal original amb major o menor precisió, depenent de l'exactitud de la nostra mesura i de la velocitat a la qual puga prendre aqueixes mostres.

![Conversió analógic-digital][img3]

Arduino UNO disposa de sis convertidors analògic a digital, nominats d'A0 fins a A5, retolades com ANALOG IN:

![Entrades analògiques][img4]

Vegem com usar les entrades analògiques amb un circuit com aquest, en el qual donem tensió als extrems d'un potenciòmetre i connectem el pin central (el variable) a l'entrada de la porta A5 de Arduino:

![Esquema de muntatge][img5]

- _Sembla bon moment per a destacar que els convertidors ADC lligen valors de tensió i no resistència, per tant, el que llegirem és **la caiguda de tensió** en el potenciòmetre a mesura que
  girem l'ajust._

La primera curiositat és que no necessitem declarar en el **setup()** que usarem una porta analògica. I la segona és que per a prendre una mostra (llegir) del pin A5, usarem la instrucció:

`int Val = analogRead(A5) ;`

- Els convertidors de Arduino UNO i Mega són de 10 bits de resolució pel que ens retornarà valors entre 0 i 2^10 = 1.024 per a tensions entre 0 i 5V. En canvi el Arduino DUE disposa de convertidors de 12 bits pel que el valor de les seues lectures estarà entre 0 i 2^12 o siga 4.096, és a dir té millor resolució (però només pot llegir fins a 3,3V).
- Assegura't de no usar sensors que puguen donar més de 5V màxim (amb Arduino UNO i Mega), ja que danyaries el xip principal de Arduino.

Escriurem un programa que llija el valor del pin A5 i l'envie a la consola perquè puguem visualitzar-lo.

## Usant les portes analògiques

Prova aquest programa:

```Arduino
//Codi: ARD_05_01

void setup()
{
    Serial.begin(9600); // Iniciem la porta serie
}

void loop()
{
    int Lectura = analogRead(A5) ;
    Serial.println( Lectura);
    delay(200) ;
}
```

Quan ho bolques, arranca la consola i voràs que a mesura que gires l'ajust les lectures varien de manera contínua reflectint la posició del potenciòmetre, les lectures reflecteixen la caiguda en volts.

![Monitor sèrie][img6]

No puc resistir-me a proposar-vos aquesta prova: Desconnecta el potenciòmetre de la porta A5 i observa els resultats que Arduino envia a la consola. Perquè ixen aqueixos valors?

- Al no estar l'A5 connectat a cap referència vàlida, està surant i els valors que captura són mostra d'aqueixa incoherència. En realitat el que està fent la teua Duino és captar soroll aleatori de radiofreqüència i intentar donar-li sentit, però ho té malament, com podeu veure.
- No obstant això en condicions normals els valors que llegirà seràn relativament baixos. Vols que les oscil·lacions cresquen en valor?. Fàcil. Posa-li una antena. Val un simple cable de protoboard connectat des de l'A5 a res (O si agafes l'altre extrem entre els dits, _tú mateix faràs d'antena_).

## Un últim comentari

Déiem en una lliçó anterior, que la fidelitat amb què podem mostrejar un senyal analògic depenia, bàsicament, de la resolució de la mostra i de la velocitat a la qual podíem mostrejar el senyal (Sample Rate en anglés).

Ja vam dir que la família Arduino, disposa de convertidors de 10 bits pel que la nostra resolució és de 2^10 = 1.024 i en el cas del DUE de 2^12 = 4.096. Però fins ara no hem vist a quina velocitat podem prendre mostres amb el nostre Arduino. Ho comprovarem, amb aquest mateix circuit.

Tenim una funció anomenada **millis()** que ens indica en mil·lisegons el temps transcorregut des que iniciem Arduino i la podem usar per a veure quantes mostres podem prendre per segon.

```Arduino
//Codi: ARD_05_02}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    unsigned long T ;
    int n = 0 ;
    T = millis();
    while (millis() \<= T + 1000) // Mentre no passe un Segon = 1000 ms
    {
        analogRead( A5) ;
        n++ ; // Comptem cada vegada que llegim
    }
    Serial.println(n);
}
```

- _Hem usat un unsigned long per a guardar millis perquè és el tipus que Arduino usa internament per al seu rellotge. Seria un error manejar millis amb un int perquè el seu valor màxim és 32.767 i
  mesurant mil·lisegons el comptador desbordaria en poca més de 32 segons._

Si correu aquest programa en un Arduino UNO us donarà, si fa no fa, un resultat de 8.940 mostres o lectures per segon. No està malament.

És adequat per a mostrejar senyals que no varien massa ràpid amb el temps, com són quasi tots els sensors habituals en la indústria, però que es quedarà curt si voleu mostrejar senyals d'àudio.

- _Per a jugar amb àudio és millor usar un Arduino DUE. Té una velocitat de rellotge 4 vegades més ràpida (us farà falta), capacitat de mostreig a velocitat d'àudio (40 Khz) i autèntics convertidors DAC (digital to analog converters)._
- De fet no és complicat augmentar la velocitat de mostreig fins a unes 20.000 mostres per segon amb un Arduino UNO, però per a això hem de pontejar Arduino i saltar a programar el xip interior Atmega 328. No és moment per a això, però hi ha formes.

## Resum de la lliçò

- Ja coneixem l'ús del potenciòmetre.
- Hem presentat els conceptes bàsics en la conversió analògica a digital.
- Vam aprendre a llegir les portes analògiques de Arduino.
- Sabem que podem llegir les portes analògiques unes 8.900 vegades per segon amb una resolució de 10 bits, és a dir entre 0 i 1.024.
- Hem conegut la funció **millis()**.
