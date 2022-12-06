// b1 liga tudo
// me1 e me2 liga
// s1 recebe sinal
// sc1 0-90
// bm1 mov A-n=1,2,3...(representado por um led laranja)
// 
#include <Servo.h>
#include <IRremote.h>

IRrecv receptor(8);
decode_results valorSaida;

Servo of1;
Servo of2;
Servo sc1;
Servo sc2;

#define me2 2
#define me1 3
#define s3 6
#define s2 7
#define s1 8
#define bot0 9
#define bot1 10

float valor_da_forca[] = {0,0};

void setup () {
  of1.attach(5);
  of2.attach(4);
  sc1.attach(11);
  sc2.attach(12);
  pinMode(me1, OUTPUT);
  pinMode(me2, OUTPUT);
  pinMode(bot1, INPUT);
  pinMode(bot0, INPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  Serial.begin(9600);
  receptor.enableIRIn();
}

void loop () {

  if ( digitalRead(bot1) == (HIGH)) {
      digitalWrite(me1, HIGH);
      digitalWrite(me2, HIGH);
      sc1.write(90);
      sc2.write(0);
      of1.write(90);
      of2.write(90);
      Serial.println("B1 ACIONADO");
      delay(3000);
  }

    if (receptor.decode(&valorSaida)) {
      receptor.resume();
      
	for (int i = 0; i <= 9; i++){
      if (valorSaida.value == 0xFD08F7){
          sc1.write(0);
          sc2.write(0);
          of2.write(90);
          of1.write(90);
          Serial.println("BM1 move para a posicao A");
          delay(5000);
          of1.write(0);
          Serial.println("BM1 move para a posicao 'n' ");
          delay(3000);
          of1.write(90);
          sc1.write(90);
      } 
      Serial.print("Qtd de potes: ");
      Serial.println(i);
    }
  } 
}

// comitando dnv