# 08 - Crear gràfiques utilitzant el port serie

[img1]: ./Imatges/ard_08_01.png "Traçador"
[img2]: ./Imatges/ard_08_02.png "Gràfica una variable"
[img3]: ./Imatges/ard_08_03.png "Gràfica dos variables"

## Objectius

Aprendre a usar el **Traçador Sèrie** per a fer **gràfiques** amb el IDE
de Arduino i incloure **diverses variables** en la gràfica.

## Material requerit

- Un PC
- Un cable USB
- Arduino UNO o equivalent

## Dibuixar una gràfica utilitzant el Traçador Sèrie

Ja hem utilitzat moltes vegades el monitor serie del IDE per a mostrar
valors de les variables del nostre programa. Però en certes ocasions pot
ser útil veure-ho en forma **de gràfica** en comptes d'en dades
numèriques, per exemple, per a veure la tendència de les dades d'una
forma senzilla i clara.

Perquè resulta que el IDE de Arduino incorpora des de la versió 1.6.6
una eina anomenada **Traçador Sèrie** que ens permet precisament crear
gràfiques a partir de les variables que li indiquem. És molt senzilla
d'usar i de moment no ofereix moltes opcions, però segurament vagen
afegint característiques noves amb noves versions.

Per a utilitzar-la no hem d'aprendre res nou quant a la programació.
Simplement farem un programa que mostre un valor pel port serie. Podeu
utilitzar aquest programeta que genera números aleatoris cada cert
temps:

```Arduino

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
```

Ara en comptes d'obrir el Monitor Sèrie, obrirem el Traçador Sèrie,
que està en la barra d'eines, just davall.

![Traçador][img1]

I quan carreguem el programa en la placa, veurem com es va generant una
**gràfica** a partir dels valors aleatoris que va agafant la variable.

![Gràfica una variable][img2]

## COM INCLOURE MÉS VARIABLES

L'eina també ens dona l'opció de mostrar diverses variables alhora en
la mateixa gràfica. La manera de fer-ho és també molt senzilla,
simplement haurem de treure les dues variables pel port serie però
utilitzant un separador "," entre ells, i automàticament els dibuixarà
en la mateixa gràfica amb un color diferent.

Si afegim una altra variable que prenga també valors aleatoris al
programa anterior, el programa quedaria de la següent forma

```Arduino

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
  Serial.print(",");
  Serial.println(valor2);
  delay(250);
}
```

![Gràfica dos variables][img3]

## Resum de la sessió

Hem descobert una nova eina que ens permet fer **gràfiques** fàcilment
des del mateix IDE de Arduino.

- Sabem incorporar **diverses variables** a la gràfica.
- Ara que sabem que existeix aquesta eina i com s'utilitza, podeu incorporar-la als vostres projectes per a realitzar gràfiques de les mesures de sensors , la velocitat d'un motor, o el que se us passe pel cap.
