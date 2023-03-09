/******************************************
  CartroTech (www.cartrocreatiu.es)
  ARD_xx.ino
  Tutorial ARduino - Lliço xx: Sensor de xoc
  25.02.2021

 ******************************************/
int Led = 13; //assigna a la variable Led el valor de 13
int buttonpin = 2; //assigna a la variable buttonpin el valor 3
; int  val; //defineix val com enter
void  setup()
{
  pinMode(Led, OUTPUT); //defineix el pin 13 com eixida
  pinMode(buttonpin, INPUT); //defineix el pin 2 com entrada digital
}
void  loop()
{
  val = digitalRead(buttonpin); //llig el valor de l'entrada 2 i l'assigna a la variable val
  if (val == HIGH)  //comproba si el sensor s'activat, recordeu que si detecta l'entrada 2 passara a estat baix
  {
    digitalWrite(Led, LOW);
  }
  else  //quan el sensor envia senyal, el led 13 s'encen durant 2 segons
  {
    digitalWrite(Led, HIGH);
    delay(2000);
  }
}
