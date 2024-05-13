#define b1 2//definimos lo pines donde estaran conectados los pulsadores referido a cada posicion 
#define b2 3// 
#define b3 4// 
#define b4 5//definimos lo pines donde estaran conectados los pulsadores referido a cada posicion 
#define b5 6// 
#define b6 7//definimos lo pines donde estaran conectados los pulsadores referido a cada posicion 
#define enter 8//definimos el pin del pulsador para ingresar letra y/o espacio
#define res 9//definimos el pin del pulsador referido al salto de linea 

#define led1 A0//definimos los pines para los leds referido a cada posicion 
#define led2 A1//
#define led3 A2//
#define led4 A3//definimos los pines para los leds referido a cada posicion
#define led5 A4//
#define led6 A5//definimos los pines para los leds referido a cada posicion


int bot1=0;//establecemos las variables contadores referidos a los botones para llevar la cuenta de que boton ha sido presionado  
int bot2=0;
int bot3=0;//establecemos las variables contadores referidos a los botones para llevar la cuenta de que boton ha sido presionado
int bot4=0;
int bot5=0;
int bot6=0;//establecemos las variables contadores referidos a los botones para llevar la cuenta de que boton ha sido presionado

void setup() {
  Serial.begin(9600);//iniciamos el puerto serie para visualizar las letras(el 9600 es la cantidad de informacion en baudios a la que se comunica el arduino con el monitor)
  
  pinMode(b1,INPUT);//damos el modo de trabajo de cada pin donde estaran conectado los pulsadores, los declaramos como entrada ya que estos nos daran la info de cuando estan presionados
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);//damos el modo de trabajo de cada pin donde estaran conectado los pulsadores, los declaramos como entrada ya que estos nos daran la info de cuando estan presionados
  pinMode(b5,INPUT);
  pinMode(b6,INPUT);
  pinMode(enter,INPUT);
  pinMode(res,INPUT);//damos el modo de trabajo de cada pin donde estaran conectado los pulsadores, los declaramos como entrada ya que estos nos daran la info de cuando estan presionados

  pinMode(led1,OUTPUT);//damos el modo de trabajo de los pines donde estan los leds como salida
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);//damos el modo de trabajo de los pines donde estan los leds como salida
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);//damos el modo de trabajo de los pines donde estan los leds como salida
  
}

void loop() {
  do{//usamos un do while para hacer por lo menos una vez, y se siga ejecutando mientras se cumpla una condicion 
    if(digitalRead(b1)==1){   //leemos cada pin digital referido a cada boton que representa la matriz 
      bot1++;                 //si esta presionado aumentamos en uno la variable referida a ese pulsador
      digitalWrite(led1,HIGH);//y luego encendemos el led indicando el lugar que ocupa en la matriz dicho pulsador
    }
    
    if(digitalRead(b2)==1){   //hacemos lo mmismo para cada uno de los 6 pulsadores que representan la matriz de puntos 
      bot2++;
      digitalWrite(led2,HIGH);
    }
    
    if(digitalRead(b3)==1){
      bot3++;
      digitalWrite(led3,HIGH);
    }
    
    if(digitalRead(b4)==1){
      bot4++;
      digitalWrite(led4,HIGH);
    }
    
    if(digitalRead(b5)==1){
      bot5++;
      digitalWrite(led5,HIGH);
    }
    
    if(digitalRead(b6)==1){
      bot6++;
      digitalWrite(led6,HIGH);
    }
    
    if(digitalRead(enter)==1){//cuando presionamos el pulsador enter vamos a analizar las variables para ver a que letra queremos representar
      if(bot1 >= 1 && bot2==0 && bot3==0 && bot4==0 && bot5==0 && bot6==0){//si todas las condiciones se cumplen en simultaneo
        Serial.print("A");                                                 //imprimimos en puerto serie la letra "A"
      }
      if(bot1>=1 && bot2>=1 && bot3==0 && bot4==0 && bot5==0 && bot6==0){  //y asi para cada letra del alfabeto se tendra que cumplir una cierta condicion en las variables 
        Serial.print("B");
      }
      if(bot1>=1 && bot2==0 && bot3==0 && bot4>=1 && bot5==0 && bot6==0){
        Serial.print("C");
      }
      if(bot1>=1 && bot2==0 && bot3==0 && bot4>=1 && bot5>=1 && bot6==0){
        Serial.print("D");
      }
      if(bot1>=1 && bot2==0 && bot3==0 && bot4==0 && bot5>=1 && bot6==0){
        Serial.print("E");
      }
      if(bot1>=1 && bot2>=1 && bot3==0 && bot4>=1 && bot5==0 && bot6==0){
        Serial.print("F");
      }
      if(bot1>=1 && bot2>=1 && bot3==0 && bot4>=1 && bot5>=1 && bot6==0){
        Serial.print("G");
      }
      if(bot1>=1 && bot2>=1 && bot3==0 && bot4==0 && bot5>=1 && bot6==0){
        Serial.print("H");
      }
      if(bot1==0 && bot2>=1 && bot3==0 && bot4>=1 && bot5==0 && bot6==0){
        Serial.print("I");
      }
      if(bot1==0 && bot2>=1 && bot3==0 && bot4>=1 && bot5>=1 && bot6==0){
        Serial.print("J");
      }
      if(bot1>=1 && bot2==0 && bot3>=1 && bot4==0 && bot5==0 && bot6==0){
        Serial.print("K");
      }
      if(bot1>=1 && bot2>=1 && bot3>=1 && bot4==0 && bot5==0 && bot6==0){
        Serial.print("L");
      }
      if(bot1>=1 && bot2==0 && bot3>=1 && bot4>=1 && bot5==0 && bot6==0){
        Serial.print("M");
      }
      if(bot1>=1 && bot2==0 && bot3>=1 && bot4>=1 && bot5>=1 && bot6==0){
        Serial.print("N");
      }
      if(bot1>=1 && bot2==0 && bot3>=1 && bot4==0 && bot5>=1 && bot6==0){
        Serial.print("O");
      }
      if(bot1>=1 && bot2>=1 && bot3>=1 && bot4>=1 && bot5==0 && bot6==0){
        Serial.print("P");
      }
      if(bot1>=1 && bot2>=1 && bot3>=1 && bot4>=1 && bot5>=1 && bot6==0){
        Serial.print("Q");
      }
      if(bot1>=1 && bot2>=1 && bot3>=1 && bot4==0 && bot5>=1 && bot6==0){
        Serial.print("R");
      }
      if(bot1==0 && bot2>=1 && bot3>=1 && bot4>=1 && bot5==0 && bot6==0){
        Serial.print("S");
      }
      if(bot1==0 && bot2>=1 && bot3>=1 && bot4>=1 && bot5>=1 && bot6==0){
        Serial.print("T");
      }
      if(bot1>=1 && bot2==0 && bot3>=1 && bot4==0 && bot5==0 && bot6>=1){
        Serial.print("U");
      }
      if(bot1>=1 && bot2>=1 && bot3>=1 && bot4==0 && bot5==0 && bot6>=1){
        Serial.print("V");
      }
      if(bot1==0 && bot2>=1 && bot3==0 && bot4>=1 && bot5>=1 && bot6>=1){
        Serial.print("W");
      }
      if(bot1>=1 && bot2==0 && bot3>=1 && bot4>=1 && bot5==0 && bot6>=1){
        Serial.print("X");
      }
      if(bot1>=1 && bot2==0 && bot3>=1 && bot4>=1 && bot5>=1 && bot6>=1){
        Serial.print("Y");
      }
      if(bot1>=1 && bot2==0 && bot3>=1 && bot4==0 && bot5>=1 && bot6>=1){//la condicion de cada variable es mayor o igual por que puede ser que se llegue a aumentar 
        Serial.print("Z");                                               //en mas de uno las variables por lo tanto no seria tan preciso poner que sea igual a 1(uno)
      }
      if(bot1==0 && bot2==0 && bot3==0 && bot4==0 && bot5==0 && bot6==0){//establecemos una ultima condicion que nos dice que si nungun pulsador ah sido presionado 
        Serial.print(" ");                                               //de dara un espacio en la escritura de la pantalla
      }
      bot1=0;bot2=0;bot3=0;bot4=0;bot5=0;bot6=0;//luego de haber ingresado la letra correspondiente volvemos a 0 todos los contadores para volver a inicializarlos
      digitalWrite(led1,LOW);//tambien apagaremos todos los leds para volver a ingresar una nueva letra
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);//tambien apagaremos todos los leds para volver a ingresar una nueva letra
      //cabe destacar que solo se podra ingresar una letra o espacio por cada vez que presionemos enter
    }
    delay(300);//damos un delay de 300 milisegundos 
  }while(digitalRead(res) == 0);//y nos preguntamos si esta condicion es verdadera, si lo es sigue leyendo los pulsadores, si no damos un salto de linea  
  
  Serial.println(" siguiente linea");//aca damos el mensaje que se dio el salto de linea y luego volvemos a leer todos los pulsadores
}
