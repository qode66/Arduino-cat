# 07 - Comunicació amb l'exterior

[img1]: ./Imatges/ard*07*01.png "Monitor série"
[img2]: ./Imatges/ard*07*02.png "Velocitat de connexió"
[img3]: ./Imatges/ard*07*03.png "Final de línia"

## Objectius

L'objectiu de la lliçó és comprendre la comunicació via port serie, per
el que cal utilitzar la llibreria Serial. Veurem també operacions amb
enters, els tipus String i char. Entendrem com operar amb Strings i la
instrucció while.

## Material requerit

- PC
- Cable USB
- Arduino UNO o compatible

## Comunicació Sèrie amb el món exterior

Més abans que després, necessitarem comunicar el nostre Arduino amb el
nostre PC. Les raons són vàries, enviar-li ordres o rebre informació o
senyals per exemple.

Els PCs disposen de teclats, pantalles i adaptadors de xarxa, però amb
Arduino hem d'usar el port USB que establirà una **connexió en sèrie**
amb el nostre PC.

La comunicació en sèrie és molt senzilla, basten dos fils per a enviar
una diferència de tensió entre ells i poder marcar nivells alt (5V) i
baix(0V) i amb això podem transmetre informació digital. Ara només ens
falta pactar dues coses entre qui envia i qui rep:

- Un **codi comú** per a codificar els caràcters que enviem.
- Un **acord de velocitat** per a saber a quin ritme cal llegir les dades.

El codi comú que usarem amb Arduino es diu **codi ASCII** i és estàndard
en tots els PCs. És una manera de codificar les lletres mitjançant
números que representes aquests caràcters. Recordeu que només podem
transmetre uns i zeros.

Així per exemple la lletra A se representa pel numere 65, la B el 66, C
el 67... Pràcticament tots els PCs actuals utilitzen aquest codi i això
inclou a Windows, Mac i Linux (i per això podem llegir emails enviats
des de diferents plataformes), però és important comprendre que aquest
és un més entre diversos codis de caràcters possibles (EBCDIC per
exemple).

- Actualment, en realitat, se sol usar una extensió del **codi ASCII** (anomenada **Unicode**) que permet l'ús de caràcters no inclosos en la taula original, i que permeta representar caràcters com les Ñ, o accents per a l'espanyol, però també alfabets diferents com el Kanji xinés o l'alfabet ciríl·lic. I aquest és el motiu pel qual podeu llegir les lletres xineses o russes en les pàgines d'internet d'aquests països.

L'altre factor a pactar per a realitzar una comunicació serie és la
velocitat. Atés que només disposem de dos fils per a transmetre,
necessitem saber quan cal llegir la línia i això es fa establint un
acord de velocitat. Si la velocitat d'enviament és diferent de la
velocitat de lectura, el missatge final serà irrecognoscible.

Bona part dels errors de comunicació sèrie programant amb Arduino se
solen deure a una diferència de velocitat entre l'emissor i el
receptor.

Aquesta velocitat es mesura en bits per segon (bauds) i veurem que
Arduino suporta diferents velocitats de comunicació serie.

## Establint la comunicació Sèrie

Arduino disposa d'una llibreria serie inclosa anomenada Serial, que ens
permet envia informació al PC i per a usar-la simplement hem de
demanar-li en el nostre **setup()** que la incloga. La instrucció que
s'encarrega és:

```Arduino
Serial.begin( velocitat ) ;
```

- _Note's que Serial té la S majúscules i que C++ diferència entre majúscules i minúscules_

La velocitat és una valor entre 300 i 115.200 bits per segon. I sol ser
costum establir-la en 9600 (el valor per defecte) però no hi ha cap raó
per a això i aquesta no és una velocitat especialment alta.

Per a enviar un missatge des de Arduino al nostre PC podem usar les
funcions `Serial.print()` i `Serial.println()`.Vegem un exemple:

```Arduino
int LED = 10 ; int boton = 6 ;
bool estat = false ;

void setup()
{
    Serial.begin(9600) ; // Inicialitza el Port seriosa 9600 bits per segon
}

void loop()
{
    int i = 54 ;
    Serial.println( i );
}
```

El `Serial.println()` enviara el valor d'i al port serie de Arduino
(_repetidament_. Per a llegir-ho en el nostre PC necessitem un monitor
de port serie. El IDE de Arduino inclou un molt senzill, però suficient
que s'invoca amb el botó del monitor:

![Botó del monitor sèrie][img1]

Necessitem a més assegurar-nos que la velocitat de connexió és la
mateixa en tots dos extrems. Fixa't en la part inferior dreta del
monitor serie:

![Velocitat de connexió][img2]

Normalment la velocitat per defecte són els 9600 bits per segon o
**bauds** en els quals hem programat la nostra porta serie, i si ho
desplegau, veureu les diferents velocitats acceptables per a Arduino.

- _Estrictament parlant, bits per segon i bauds no són exactament el mateix excepte sota certes condicions particulars que en Arduino es compleixen, per la qual cosa ací podem usar-los com a sinònims._
- _En el món Arduino sembla haver-hi un acord d'usar velocitats baixes com 9600 en lloc de més altes com 115200, per a evitar problemes. Això és alguna cosa que fa anys estava justificat per problemes de transmissió, però amb la tecnologia actual no hi ha motiu per a això. És més, quan necessitem utilitzar dispositius de comunicacions com a adaptadors Ethernet o BlueTooth per a comunicar-nos, la velocitat haurà de pujar necessàriament._

Ara que sabem enviar informació i resultats al PC, veurem com podem
operar amb enters i mostrar el resultat a la porta serie. En C++ els
operadors numèrics són els normals en càlcul (i alguns menys freqüents):

- Addició: +
- Resta: --
- Multiplicació: \*
- Divisió sencera: / Quocient sense decimals (ja que operem amb enters)
- Resta: % Retorna la resta d'una divisió.

En C++ hem d'expressar les operacions matemàtiques en una sola línia i
utilitzar parèntesi per a garantir que s'opera com necessitem. Anem amb
alguns exemples:

| Operació           | Resultat     | Comentari                                                |
| ------------------ | ------------ | -------------------------------------------------------- |
| int i = 4 \* 2     | resultat = 8 |                                                          |
| int i = 4 \* 2 / 3 | resultat = 2 | Perquè menysprea els decimals en ser sencer              |
| int i = 14% 3      | resultat = 2 | La resta de 14 dividid entre 3                           |
| int i = 2 + 8 / 2  | resultat = 6 | Calcula primer la divisió.                               |
| int i = (2+8) / 2  | resultat = 5 | El parèntesi força al fet que es realitze primer la suma |

Donada una expressió, la precedència d'operadors indica que operacions
es realitzaren abans i quals després en funció del seu rang. Per als
quals s'inicien en C++ no és fàcil saber que operadors tenen
preferència, per la qual cosa és més segur que davant el dubte useu
parèntesi.

Els parèntesis forcen les operacions d'una forma clara i convé
utilitzar-los davant el dubte perquè d'una altra manera, detectar els
errors d'operació pot tornar-se molt difícil especialment quan un
comença a programar.

L'operadora resta és més útil del que sembla a primera vista perquè ens
permet saber si un numere és múltiple d'un altre. Suposem que volem
saber si un número donat és parell.

Podríem escriure un programa com aquest:

```Arduino
void setup()
{
    Serial.begin(9600) ; // Inicialitza el Port serie
}

void loop()
{
    int i = 27 ; //El número en qüestió
    if ( i % 2 == 0)
    {
        Serial.println(\"És parell.\") ;
    }
    else
    {
        Serial.println(\"És imparell\");
    }
}
```

Donant a i diferents valors podem comprovar com funciona l'operadora
resta %. Tornarem sobre això quan vegem alguns exemples de com calcular
nombres primers.

En aquest programa hem usat d'una manera diferent el
`Serial.println()` passant-li una **String** de text entre cometes.
`Serial.print()` envia el text ( entre cometes) que li posem però no
fa salt de línia quan acaba. En canvi `Serial.println()` fa el mateix
i inclou al final aqueix salt de línia.

```Arduino
void setup()
{
    Serial.begin(9600) ; // Inicialitza el Port serie
}

void loop()
{
    Serial.print("Bon ") ;
    Serial.print("Dia ") ;
    Serial.println("a tots.") ;
}
```

C++ disposa d'una mena de variables anomenades **Strings**, capaces de
contindre textos. Podem operar amb elles simplement definint-les com
qualsevol altra mena de C++:

```Arduino
void loop()
{
    int resultat = 25 ;
    String s = " El resultat és: " ; // Note's que la S de String és majúsc.
    Serial.print( s) ;
    Serial.println( resultat);
}
```

Un tipus **String** es defineix simplement posant entre cometes dobles
un text, i es pot operar amb elles d'una forma similar a com operem amb
enters. Prova:

```Arduino

void loop()
{
    String a = "hola " ;
    String b = "a tots." ;
    Serial.println( a + b);
}
```

I també podem construir un **String** sobre la marxa així:

```Arduino

void loop()
{
    int resultat = 25 ;
    String s = "El resultat és: ";
    Serial.println( s + String( resultat ));
}
```

On imprimim el resultat de concatenar s String, i la conversió d'un int
a String (L'operador + afig un String al final d'un altre).

## Rebent missatges a través del port Sèrie

Fins ara només hem enviat missatges des de Arduino cap al PC, Però com
rebem missatges en Arduino?

En primer lloc disposem d'una funció anomenada `Serial.parseInt()`
que ens entrega el que s'escriu en el monitor serie convertit a enter:

```Arduino

void loop()
{
    if (Serial.available() \> 0)
    {
        int x = Serial.parseInt();
        Serial.println ( x) ;
    }
}
```

Aquest programa simplement rep en x els números que ens teclegen en la
consola (quan premem intro) i si és un text, l'interpreta com a zero.

Hem utilitzat una altra funció `Serial.available()` que és un booleà.
Convé per costum comprovar que abans de llegir el port serie hi ha
alguna cosa que ens han enviat. Si n'hi ha, available() és True i en
cas contrari és False.

Per a llegir un **String** del port serie hem de complicar-nos una mica
més i parlar del tipus **char**.

Un dels majors maldecap en iniciar-se en C++ és comprendre la
diferència, antiintuïtiva, entre **char** i **String**. **Char** és un
tipus que representa un únic caràcter i es defineix amb cometes simples,
a diferència de String que necessita cometes dobles:

```Arduino
char c = 'a' ;

String s ="a" ;
```

Encara que semble el mateix per a C++ són molt diferents.

Per a llegir una cadena des del port sèrie necessitem llegir un caràcter
cada vegada i després muntar un String a partir d'ells, però abans,
assegura't de seleccionar tots dos NL & CR en la part inferior del
monitor serie, per a garantir que s'envia el caràcter de fi de línia:

![Final de línia][img3]

Un programa per a llegir la consola seria una cosa així:

```Arduino

void setup()
{
    Serial.begin(9600);
}

void loop ()
{
    char c = ' ' ;
    String missatge ="" ;
    if (Serial.available()) //Comprovem si hi ha alguna cosa esperant
    {
        while( c != '\\n') //Si n'hi ha, ho llegim fins a l'intro
        {
            missatge = missatge + c ; // Afegim el llegit al missatge
            c = Serial.read(); //Llegir 1 caràcter
            delay(25);
        }
        Serial.println( missatge); //En eixir imprimir el missatge
        missatge = \"\" ; //Esborra-ho per a la pròxima vegada
    }
}
```

Ací usem una altra instrucció de C++ anomenada **while**. És similar a
**if**, Executa repetidament el bloc que li segueix mentre es complisca
la condició que li passem entre parèntesi:

```Arduino
while ( condició)

{ ......... }
```

Quan llig l'intro final del que escrivim, La condició c != '\n' es
torna fals i ix del **while**.

D'altra banda, comprovem si hi ha una cosa disponible a la porta serie
i en aquest cas muntem el missatge llegint un **char** cada vegada i
sumant-li-ho a missatge per a construir un **String** que puguem
imprimir en eixir.

- _El motiu del delay(25) és que a una velocitat tan lenta, enviar un char de 8 bits per la porta serie, tarda molt més del que tarda Arduino a executar les instruccions del while i tornar a començar. Per això si se suprimeix el delay (i us recomane la prova) llegirà un caràcter bo (de la paraula escrita i com 10 caràcters fem per a un Arduino UNO o Mega)._
- _Si pugem la velocitat de comunicació a 115200 bits per segon, comprovàreu que no hi ha aquest problema ja que en multiplicar la velocitat d'enviament per més de 10 Arduino ja no té temps de tornar per més caràcters abans que arriben._

## Resum de la sessió

- Hem vist com establir la comunicació amb el PC extern, tant per a enviar com per a rebre missatges sencers i de text.
- Hem presentat els tipus String i char.
- Hem vist les regles bàsiques per a operar amb enters i amb Strings.
- Presentem una nova instrucció: while.
