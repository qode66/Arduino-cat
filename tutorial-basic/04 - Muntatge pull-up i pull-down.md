# 04 - Muntatge pull-up i pull-down

[img1]: ./Imatges/ard_04_01.png "Pull-up"
[img2]: ./Imatges/ard_04_02.png "Pull-down"

Pull-up i pull-down és un muntatge pel qual assegurem un valor alt o baix (HIGH o LOW) a la eixida del circuit. S'utilitza necessàriament amb els interruptors i contactes per no deixar mai una entrada sense connectar a cap lloc.

## Pull-up

![Pull-up][img1]

Les resistències pull-up són resistències que s'utilitzen en circuits lògics per garantir un nivell lògic ben definit en un pin en totes les condicions. Com a recordatori, els circuits
lògics digitals tenen tres estats lògics: alt, baix i flotant (o alta impedància). L'estat d'alta impedància es produeix quan el pin no s'arrossega a un nivell lògic alt o baix, sinó que es deixa "flotant". Una bona il·lustració d'això és un pin d'entrada no connectat d'un microcontrolador. No es troba ni en un estat lògic alt ni baix, i un microcontrolador podria interpretar de manera imprevisible el valor d'entrada com a màxim lògic o baix lògic. Si no hi haguera la resistència de tracció, l'entrada flotaria quan l'interruptor estiga obert i baixaria només quan l'interruptor estiga tancat.

## Pull-down

![Pull-down][img2]

Les resistències pull-down funcionen de la mateixa manera que les resistències pull-up, tret que porten el pin fins a un valor lògic baix. Es connecten entre terra i el pin corresponent d'un
dispositiu. A la figura es pot veure un exemple de resistència desplegable en un circuit digital. Un interruptor de polsador està connectat entre la tensió d'alimentació i un pin del microcontrolador. En aquest circuit, quan l'interruptor està tancat, l'entrada del microcontrolador té un valor lògic elevat, però quan l'interruptor està obert, la resistència desplegable fa baixar la tensió d'entrada a terra (valor zero lògic), evitant estat indefinit a l'entrada. La resistència desplegable ha de tindre una resistència més gran que la impedància del circuit lògic, o bé podria ser capaç de baixar massa la tensió i la senyal d'entrada al pin es mantindria a un valor lògic constant, independentment de la posició del commutador.

## Conclusió

Les resistències pull-up no són un tipus especial de resistències; són simples resistències de valor fix connectades entre l'alimentació de tensió (generalment + 5V) i el pin adequat, cosa que resulta en definir la tensió d'entrada o sortida en absència d'un senyal de conducció.
