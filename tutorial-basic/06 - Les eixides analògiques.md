# 06 - Les eixides analògiques

[img1]: ./Imatges/ard_06_01.png "Senyal digital"
[img2]: ./Imatges/ard_06_02.png "Senyal analògica"
[img3]: ./Imatges/ard_06_03.png "PWM"
[img4]: ./Imatges/ard_06_04.png "Eixides amb PWM"
[img5]: ./Imatges/ard_06_05.png "Esquema de muntatge"

## Finalitat

Comprendre les diferències entre analògic i digital. Conèixer les eixides quasi analògiques de Arduino i què és la modulació per polsos (PWM).

## Material requerit

- Arduino UNO o complatible
- Protoboard
- Cables connexió
- Un díode led
- Una resistència de 330 Ohms

## Analògic i digital

Totes les senyals que hem treballat fins ara amb el nostre Arduino, de
entrada o de eixida, tenen una característica comú: són digitals, es a
dir que poden prendre un valor ALT o BAIX, però no valor intermedis.

Si representem el valor d'un **senyal digital** al llarg del temps,
veuríem alguna cosa així:

![Senyal digital][img1]

En la vida moltes coses son així, aproves o suspens, encens la llum o
l'apagues, però moltes altres son variables mesurables contínues i poden
tenir qualsevol valor que imaginem, com l'angle de les agulles del
rellotge o la temperatura, que dins de valors finits poden prendre tants
valors intermedis com puguem imaginar.

A aquesta classe de variables les diem **analògiques** i una
representació per contraposició al **digital**, seria una mica com això:

![Senyal analògica][img2]

No és rar que vulguem controlar alguna cosa del món exterior amb un
senyal analògic de manera que el comportament del sistema seguisca
aqueix senyal. Podem per exemple voler variar la lluminositat d'un
díode LED i no simplement apagar-lo o encendre'l.

En aquesta lliçó aprendrem a enviar senyals analògics als pins d'eixida
de Arduino.

## Eixides quasi analògiques

Fins ara hem vist com activar les eixides digitals de Arduino, per a
encendre i apagar un LED per exemple. Però no hem vist com modificar la
intensitat de la lluentor d'aqueix LED. Per a això, hem de modificar la
tensió d'eixida del nostre Arduino, o en altres paraules hem de poder
presentar un valor analògic d'eixida.

Per a començar hem de deixar clar que els Arduino manquen d'eixides
analògiques pures que puguen fer això (amb la notable excepció del
Arduino DUE).

Però com els xics de Arduino són llestos, van decidir emprar un truc,
perquè amb una eixida digital puguem aconseguir que quasi semble una
eixida analògica.

A aquest truc se'n diu **PWM**, sigles de Pulse Width Modulation, o
**modulació d'ample de polsos**. La idea bàsica és posar eixides
digitals que varien de forma molt ràpida de manera que el valor eficaç
del senyal d'eixida siga equivalent a un senyal analògic de menor
voltatge.

![PWM][img3]

El sorprenent és que el truc funciona.

Fixar-vos en l'amplària del pols quadrat de dalt. Quant mes ample és,
mes tensió mitjana hi ha present entre els pins, i això en el món
exterior és equivalent a un valor analògic de tensió comprés entre 0 i
5V. Al 50% és equivalent a un senyal analògic del 50% de 5V, és a dir
2,5. Si mantenim els 5V un 75% del temps, serà l'equivalent a un senyal
analògic de 75% de 5V = 3,75 V.

Per a poder usar un pin digital de Arduino com a eixida analògica, el
declarem en el **Setup()** igual que si fóra digital:

```Arduino
pinMode( 9, OUTPUT) ;
```

La diferència ve a l'hora d'escriure en el pin:

```Arduino
digitalWrite(9, HIGH);//Fica 5V en la eixida
digitalWrite(9, LOW);//Fica 0V en la eixida
analogWrite( 9, V) ;//analogWrite escriu en el pin de eixida un valor entre 0 i 5V, depenent de V (que deu estar entre 0 y 255).
```

D'aquesta manera si connectem un LED a una d'aquestes eixides PWM
podem modificar la seua lluentor sense més que variar el valor que
escrivim en el pin.

Però hi ha una restricció. No tots els pins digitals de Arduino accepten
posar valors PWM en l'eixida. Solament aquells que tenen un símbol \~
davant del número. Fixar-vos en la numeració dels pins de la imatge:

![Pins amb PWM][img4]

- Solament els pins 3, 5, 6, 9, 10 i 11 poden fer PWM i simular un valor analògic en la seua eixida.
- Si intentes fer això amb un pin diferent, Arduino accepta l'ordre tranquil·lament, sense error, però per a valors de 0 a 127 entén que és _BAIX_ i per a la resta posa _ALT_ i segueix amb la seua vida satisfet amb el deure compliment.

## Modificant la lluentor d'un LED

Farem el típic muntatge d'una resistència i un díode LED, similar al de
la lliçó 2, però assegurant-nos d'usar un dels pins digitals que poden
donar senyals PWM. En la imatge he usat el pin 9.

![Muntatge][img5]

Podem escriure un programa semblant a això:

```Arduino
\\Codi: ARD_06_01

void setup()
{
    pinMode( 9, OUTPUT) ;
}

void loop()
{
    for ( int i= 0 ; i\<255 ; i++)
    {
        analogWrite (9, i) ;
        delay( 10);
    }
}
```

El LED va augmentant la lluentor fins a un màxim i torna a començar
bruscament. Podem modificar una mica el programa perquè la transició
siga menys violenta:

```Arduino
//Codi: ARD_06_02

void setup()
{
    pinMode( 9, OUTPUT) ;
}

void loop()
{
    for ( int i= -255 ; i\<255 ; i++)
    {
        analogWrite (9, abs(i)) ;
        delay( 10);
    }
}
```

Hem fet el cicle de pujar i baixar la lluentor del LED amb un únic
bucle. La funció **abs(num)**, retorna el valor absolut o sense signe
d'un número **num**, i per això mentre que i viatja de -255 a 255,
**abs(i)** va de 255 a 0 i volta a pujar a 255.

## Conceptes importants

- Descrivim a grans trets la diferencia ens valors digitals i valors
  analògics.
- Hem vist com simular valors analògics en una eixida digital de
  Arduino.
  - Només amb les eixides que ho accepten: pins 3, 5, 6, 9, 10 i 1.
  - Podem assignar valors entre 0 i 255.
