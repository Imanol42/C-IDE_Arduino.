#include <SoftwareSerial.h>         //Insertamos la libreria para la comunicacion y configuracion bluetooth

SoftwareSerial hc06(10, 11); // RX, TX   // Definimos los comandos RX y TX de nuestro modulo bluetooth

int POTE1 = 0;      //declaramos nuestro pin a trabajar y asignamos un nombre
int valor_POTE1;    //declaramos nuestra variable

int POTE2 = 1;
int valor_POTE2;

int POTE3 = 2;
int valor_POTE3;

int POTE4 = 3;
int valor_POTE4;

int POTE5 = 4;
int valor_POTE5;

void setup() {
  
  Serial.begin(9600);     //Establecemos la comunicacion de nuestra arduino con el monitor serie
   hc06.begin(38400);      //Establecemos la velocidad de comunicacion de nuestro modulo 
}

void loop() {
  valor_POTE1=analogRead(POTE1);//inicio lectura y accion pote 1
  Serial.print("POTE 1: ");
  Serial.print(valor_POTE1);
  Serial.print("\t"); 
  if (valor_POTE1>=150){
    hc06.write('1');
    delay(100);
  }
  if (valor_POTE1<150){
    hc06.write('0');
    delay(100);
  }                             //fin lectura y accion pote 1

  delay(50);
  valor_POTE2=analogRead(POTE2);//inicio lectura y accion pote 2
  Serial.print("POTE 2: ");
  Serial.print(valor_POTE2);
  Serial.print("\t");
  if (valor_POTE2>=60){
    hc06.write('3');
    delay(100);
  }
  if (valor_POTE2<60){
    hc06.write('2');
    delay(100);
  }                             //fin lectura y accion pote 2

  delay(50);
  valor_POTE3=analogRead(POTE3);//inicio lectura y accion pote 3
  Serial.print("POTE 3: ");
  Serial.print(valor_POTE3);
  Serial.print("\t");
  if (valor_POTE3>=70){
    hc06.write('5');
    delay(100);
  }
  if (valor_POTE3<70){
    hc06.write('4');
    delay(100);
  }                             //fin lectura y accion pote 3

  delay(50);
  valor_POTE4=analogRead(POTE4);//inicio lectura y accion pote 4
  Serial.print("POTE 4: ");
  Serial.print(valor_POTE4);
  Serial.print("\t");
  if (valor_POTE4>=100){
    hc06.write('7');
    delay(100);
  }
  if (valor_POTE4<100){
    hc06.write('6');
    delay(100);
  }                             //fin lectura y accion pote 4

  delay(50);
  valor_POTE5=analogRead(POTE5);//inicio lectura y accion pote 5
  Serial.print("POTE 5: ");
  Serial.print(valor_POTE5);
  Serial.print("\n");
  if (valor_POTE5>=80){
    hc06.write('9');
    delay(100);
  }
  if (valor_POTE5<=80){
    hc06.write('8');
    delay(100);
  }                             //fin lectura y accion pote 5
  delay(50);
}
