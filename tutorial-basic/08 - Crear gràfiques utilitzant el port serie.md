08 - Crear gràfiques utilitzant el port serie
=============================================

Objectius
---------

Aprendre a usar el **Traçador Sèrie** per a fer **gràfiques** amb el IDE
de Arduino i incloure **diverses variables** en la gràfica.

Material requerit
-----------------

  ----------------------------------------------------------------------------------------- -----------------------------
  ![](Pictures/10000001000001DA000001DA312BD30D5C0BA9D6.png){width="2cm" height="2cm"}      Un cable serial per arduino
  ![](Pictures/10000001000001DA0000024CB1AC425E60A252E0.png){width="1.61cm" height="2cm"}   Un arduino uno o equivalent
  ----------------------------------------------------------------------------------------- -----------------------------

Dibuixar una gràfica utilitzant el serial traçador
--------------------------------------------------

Ja hem utilitzat moltes vegades el monitor serie del IDE per a mostrar
valors de les variables del nostre programa. Però en certes ocasions pot
ser útil veure-ho en forma **de gràfica** en comptes d\'en dades
numèriques, per exemple, per a veure la tendència de les dades d\'una
forma senzilla i clara.

Perquè resulta que el IDE de Arduino incorpora des de la versió 1.6.6
una eina anomenada **Serial Traçador** que ens permet precisament crear
gràfiques a partir de les variables que li indiquem. És molt senzilla
d\'usar i de moment no ofereix moltes opcions, però segurament vagen
afegint característiques noves amb noves versions.

Per a utilitzar-la no hem d\'aprendre res nou quant a la programació.
Simplement farem un programa que mostre un valor pel port serie. Podeu
utilitzar aquest programeta que genera números aleatoris cada cert
temps:

void setup()

{

Serial.begin(9600);

}

void loop()

{

int valor;

valor = random(0,100);

Serial.println(valor);

delay(250);

}

Ara en comptes d\'obrir el Monitor Sèrie, obrirem el Serial Traçador,
que està en la barra d\'eines, just davall.

![](Pictures/100000010000012C000000AE8266AD89E2A91BE0.png "graficas-ide"){width="6.89cm"
height="4.001cm"}

I quan carreguem el programa en la placa, veurem com es va generant una
**gràfica** a partir dels valors aleatoris que va agafant la variable.

#### ![](Pictures/100000010000012C000000826C9C2B59ED23B0BA.png "traçador-serie-una-variable"){width="9.179cm" height="4.001cm"}

#### COM INCLOURE MÉS VARIABLES

L\'eina també ens dona l\'opció de mostrar diverses variables alhora en
la mateixa gràfica. La manera de fer-ho és també molt senzilla,
simplement haurem de treure les dues variables pel port serie però
utilitzant un separador *","* entre ells, i automàticament els dibuixarà
en la mateixa gràfica amb un color diferent.

Si afegim una altra variable que prenga també valors aleatoris al
programa anterior, el programa quedaria de la següent forma

void setup()

{

Serial.begin(9600);

}

void loop()

{

int valor1;

int valor2;

valor1 = random(0,100);

valor2 = random(0,100);

Serial.print(valor1);

Serial.print(\",\");

Serial.println(valor2);

delay(250);

}

![](Pictures/100000010000012C00000082D5E2023E563A0375.png "gràfica-amb-dues-variables"){width="11.231cm"
height="5.001cm"}

Resum de la sessió
------------------

Hem descobert una nova eina que ens permet fer **gràfiques** fàcilment
des del mateix IDE de Arduino.

-   -   Sabem incorporar **diverses variables** a la gràfica.
    -   Ara que sabem que existeix aquesta eina i com s\'utilitza, podeu
        incorporar-la als vostres projectes per a realitzar gràfiques de
        les mesures de sensors , la velocitat d\'un motor, o el que se
        us passe pel cap.
