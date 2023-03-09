# 03 - Les entrades digitals

[img1]: ./Imatges/ard_03_01.jpg "Esquema elèctric"
[img2]: ./Imatges/ard_03_02.jpg "Muntatge"

## Objectius

La finalitat de la lliçó és conèixer les entrades digitals i aprofitarem per llegir un polsador. Presentarem els valors booleans i un operador: Negació.

## Material requerit

- Arduino UNO o equivalent
- Protoboard
- Cables connexió
- Un díode led
- Dos resistències 330 Ohms
- Un polsador

## Entrades digitals

Amb freqüència en electrònica necessitem saber si una llum està encesa o apagada, si algú ha premut un botó o si una porta ha quedat oberta o està tancada.

A aquesta mena de senyals tot/res, SI/NO, TRUE/FALSE, 0/1 se'n diu digitals, i podem manejar-les amb els pins de 0 al 13 de Arduino i per això parlem de pins digitals.

Molts dels sensors i actuadors que veiem en el món real són digitals:

- _Com a actuadors digitals, tenim llums, alarmes, sirenes, desbloqueig de portes, etc._
- _Com a sensors digitals podem esmentar botons i polsadors, Finals de carrera, desbordament de nivell, sensors de flames, fum o gasos tòxics._

Hem vist que Arduino poden usar els **pins digitals** com a eixides tot o res per a encendre un LED. De la mateixa manera podem llegir valors, tot o res, del món exterior.

En aquesta lliçó veurem que els **pins digitals** de Arduino poden ser usats tant d'entrada com d'eixida. Llegirem un botó o polsador extern i encendrem o apagarem un LED en funció que el botó es prema o no.

## Esquema electrònic del circuit

Muntarem un circuit amb un díode LED i resistència connectat al pin digital 10 de Arduino, tal com vam veure en les lliçons prèvies i a més un segon circuit amb un polsador S1 connectat al pin 6 amb una resistència com es mostra en el diagrama següent.

!["Esquema elèctric"][img1]

Observe's que mentre no premem S1 el pin 6 de Arduino està connectat a 5V a través de la resistència R3 forçant una lectura de tensió alta (HIGH). En canvi quan premem S1 tancarem el circuit del pin 6 a negatiu amb el que llegirà tensió baixa, LOW. En tots dos casos tenim un valor de tensió definit.

Si no posàrem la resistència R3, en prémer S1 llegiríem correctament LOW en el pin 6. Però en deixar de prémer S1 el pin 6 estaria en un estat flotant, que és ni HIGH ni LOW sinó indeterminat. Com això és inacceptable en circuits digitals forcem una lectura alta amb R3.

- _A aquesta resistència que força el valor alt en buit se'l coneix com **pullup.** Si la connectàrem a massa per a forçar una lectura a negatiu se'n diria **pulldown**._
- _Aquesta resistència és clau perquè les lectures del polsador siguen consistents. El circuit, simplement, no funcionarà bé si s'omet (tornarem sobre això)._

I ací tenim l'esquema per a protoboard del circuit.

![Muntatge][img2]

- _En aquest esquema hem seguit la pràctica habitual d'usar cables negres per a connectar a massa i cables rojos per a connectar a tensió (5V)._
- _Observe's que el polsador S1 té quatre pins (el que està sobre la resistència horitzontal). Això és perquè cada entrada de l'interruptor té dos pins connectats. En el nostre circuit simplement ignorem els pins secundaris._

## Llegint els polsadors

Comencem fent un programa que faça que el LED s'encenga quan premem el botó i s'apague quan el soltem. Per a això demanarem a Arduino que configure el pin digital 10 (D10) com a eixida per a manejar el LED, i el pin digital 6 (D6) com a entrada per a llegir el botó.

Normalment en programes senzills n'hi ha prou amb posar el número de pin en les instruccions. Però a mesura que el programa es complica això tendeix a provocar errors difícils de detectar.

Per això és costum definir **variables** amb els números de pin que usem, de manera que puguem modificar-los tocant en un sol lloc (i no havent de buscar al llarg del programa). Escriurem això una mica més elegantment:

```Arduino
int LED = 10 ;
int boto = 6;

void setup()
{
pinMode( LED, OUTPUT) ; // LED com a eixida
pinMode( boto , INPUT) ;// botó com a entrada
}
```

- _Atenció: C++ diferència entre majúscules i minúscules i per tant LED, Led i led no són el mateix en absolut. De la mateixa manera, pinMode és correcte i en canvi pinmode generarà un error de compilador fulminant._
- _He usat la variable boto sense accent perquè no és recomanable usar-los ni la ñ en els noms de variables, perquè poden passar coses estranyes._

Vam veure que per a encendre el LED bastava usar `digitalWrite(LED, HIGH)`. Per a llegir un botó es pot fer una cosa similar: `digitalRead(boto)`. Vegem com podria ser nostre **loop**:

```Arduino
void loop()
{
int valor = digitalRead(boto) ; // llegim el valor de boto en valor
digitalWrite( LED, valor) ;
}
```

Fàcil no? Encara que el LED està encés fins que premem el botó i s'apaga en prémer.

Com podríem fer el contrari, que el LED s'encenga en prémer i s'apague si no? Bastaria amb escriure en LED el contrari del que llegim en el botó.

Existeix un operador que fa això exactament l'operador **negació** **" ! "** . Si un valor donat **x** és HIGH, llavors **!x** és LOW i viceversa.

- _Un operador és un símbol que relaciona diversos valors entre si, o que modifica el valor d'una variable d'una manera previsible._
- _Exemples d'operadors en C++ són els matemàtics com +,-,\* , / ; i hi ha uns altres com la negació ! o el canvi de signe d'una variable : -- x. Anirem veient més._

De fet aquest tipus d'operacions són tan freqüents que C++ incorpora un tipus anomenat **bool** o **booleà** que només accepta dos valors TRUE (cert) i FALSE (fals) i són completament equivalents a l'1/0, i al HIGH/LOW.

Aquest nou programa seria una cosa així:

```Arduino
void loop()
{
bool valor = digitalRead(boto) ; // llegim el valor de boto en valor
digitalWrite( LED, !valor) ; // Escrivim valor contrari en LED
}
```

Hem definit valor com bool, perquè podem usar el valor de tensió alt com TRUE i el valor baix com FALSE. SI el botó no està premut el D6 llegirà TRUE i per tant posarà LED a FALSE. En cas contrari encendrà el LED.

```Arduino
void loop()
{
bool valor = digitalRead (LED) ;
digitalWrite( LED, !valor) ;
delay ( 1000) ;
}
```

De fet podríem escriure una variant curiosa del blinking LED usant l'operador negació, en només dues línies:

- _Podem llegir la situació actual d'un pin (ens retorna el seu estat actual), encara quan l'hàgem definit com a eixida, En canvi no podem escriure en un pin definit com a entrada._

```Arduino
void loop()
{
digitalWrite( LED , ! digitalRead( LED)) ;
delay ( 1000) ;
}
```

- La primera línia llig la situació del LED i la inverteix, després escriu això en LED.
- _Les instruccions dins dels parèntesis s'executen abans que les que estan fora d'ells. Per això el digitalRead s'executa abans que el digitalWrite._

## Resum de la lliçó

- Hem vist una manera de llegir senyals digitals en Arduino del món exterior a més de poder enviar-les:
  - digitalRead( pin)
  - digitalWrite( pin , valor)
- Hem conegut un nou component: el polsador.
- Coneixem un nou tipus en C++, el booleà i un nou operador de negació.
