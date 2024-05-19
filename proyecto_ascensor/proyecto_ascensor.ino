#define puls1 4//definimos pulsador de un piso
#define puls2 5//definimos pulsador del segundo piso

#define IN1 11 //se define pin para controlar direccion del motor
#define IN2 12 //se define pin para controlar direccion del motor
#define ENA 3  //se define el pin para habilitar motor 

#define fin1 6 //definimos pin de final de carrera uno
#define fin2 7 //definimos pin de final de carrera dos
#define led1 8 //definimos pin del led primer piso 
#define led2 9 //definimos pin del led segundo piso
#define ledpresencia 2//definimos led para aviso de presencia 
#define sensor 10//definimos pin donde estara conectado el sensor

int i=0;

void setup() {
  pinMode(puls1,INPUT);//declaramos la forma de trabajo de cada pin que vamos a utilizar, el primer bloque van a estar los objetos que nos entregaran informacion
  pinMode(puls2,INPUT);//pulsador, final de carrera y sensor, entonces los declaramos como entrada "INPUT" 
  pinMode(fin1, INPUT);
  pinMode(fin2, INPUT);
  pinMode(sensor,INPUT);

  pinMode(led1,OUTPUT);//en esta parte declaramos todos los objetos que necesitan que le demos informacion desde arduino, leds y motor, por lo tanto necesitamos  
  pinMode(led2,OUTPUT);//declarar como salida "OUTPUT"
  pinMode(ledpresencia, OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(sensor)==1){           //leemos la entrada digital del sensor para comprobar si hay gente en el ascensor
    digitalWrite(ledpresencia,HIGH);    //si hay gente se enciende el led de presencia
  }else{                                //caso contrario 
     digitalWrite(ledpresencia,LOW);    //se mantiene apagado
  }
  if(i==0){
    if(digitalRead(puls1)==1){            //ya en el loop lo primero que hacemos es leer el pin digita del pulsador uno, si esta presionado   
      digitalWrite(led2,LOW);             //cuando se presione el pulsador se apagara el led del piso contrario al que fue llamado
      while(digitalRead(fin1)==0){        //mientras el final de carrera este en bajo o sea no detecte que llego el ascensor, este mantendra encendido el motor en una direccion
        digitalWrite(ENA,HIGH);           //se habilita el motor 
        digitalWrite(IN1,HIGH);           //se le da un pulso alto al IN1
        digitalWrite(IN2,LOW);            //y un bajo al IN2 para que se logre girar en un sentido
        if(digitalRead(sensor)==1){       //leemos la entrada digital del sensor para comprobar si hay gente en el ascensor
          digitalWrite(ledpresencia,HIGH);//si hay gente se enciende el led de presencia
        }else{                            //caso contrario 
          digitalWrite(ledpresencia,LOW); //se mantiene apagado
        }
        delay(50);                        //dimos un pequeño delay de 50 milisegundo para que detecte bien el final de carrera
      }
      if(digitalRead(fin1)==1){           //en esta parte leemos la entrada del final de carrera si es alto
        digitalWrite(led1,HIGH);          //encendemos el led del piso donde llego
        digitalWrite(IN1,LOW);            //luego damos bajo a los dos pines de direccion del motor para que deje de girar
        digitalWrite(IN2,LOW);
      }
      i++;  
    }
  }
  if(i==1){
    if(digitalRead(puls2)==1){            //en esta parte hacemos lo mismo del bloque anterior cambiando direccion de giro y sensando los respectivos botones y fin2 
      digitalWrite(led1,LOW);             //apagamos el led del piso contrario al que fue llamado
      while(digitalRead(fin2)==0){        //leemos el segundo final de carrera
        digitalWrite(ENA,HIGH);
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,HIGH);           //le damos direccion de giro contraria al bloque anterior
        if(digitalRead(sensor)==1){
          digitalWrite(ledpresencia,HIGH);
        }else{
          digitalWrite(ledpresencia,LOW);
        }
       delay(50);                        //dimos un pequeño delay de 50 milisegundo para que detecte bien el final de carrera (UNICA MODIFICACION) 
      }
      if(digitalRead(fin2)==1){           //leemos el segundo final de carrera
        digitalWrite(led2,HIGH);          //si llego al piso llamado encendemos segundo led
        digitalWrite(IN1,LOW);            //y seguido a esto damos bajo a la direccion del motor para que pare
        digitalWrite(IN2,LOW);
      }
      i--;
    }
  }  
  delay(100);
}
