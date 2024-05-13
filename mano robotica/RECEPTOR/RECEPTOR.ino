#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial HC05(7,8); // RX, TX

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int h=0;  //Declaramos las variables auxiliares para la repeticion de los for     
int i=0;  //
int j=0;  //
int k=0;  //
int l=0;  //

int tiempo=5;  //

char s;   //Variable de tipo caracter donde almacenamos los datos enviados por bluetooth

void setup(){
  HC05.begin(38400); // comunicación directa al Modulo.
  Serial.begin(9600);// comunicación directa al Monitor.
  
  servo1.attach(3);  // 
  servo1.write(0);   //
  
  servo2.attach(5);  // 
  servo2.write(0);   //
  
  servo3.attach(6);  // 
  servo3.write(0);   //
  
  servo4.attach(9);  // 
  servo4.write(0);   //
  
  servo5.attach(10); // 
  servo5.write(0);   //
}
  
void loop(){
  s=HC05.read();
  Serial.print(char(HC05.read()));
  if(s=='1'){                   //empieza servo uno
    if(h==0){
      for(int a=0;a<=150;a++){
        servo1.write(a);
        delay(20);
        s=HC05.read();
      }
      h++;
    }
    delay(tiempo);
    s=HC05.read();
  }
  delay(tiempo);
  if(s=='0'){
    if(h==1){
      for(int a=150;a>=0;a--){
        servo1.write(a);
        delay(20);
        s=HC05.read();
      }
      h--;
    }   
    delay(tiempo);
    s=HC05.read();              //termina servo uno
  }
  
  delay(tiempo);                              //
  
  if(s=='3'){                   //empieza servo dos
    if(i==0){
      for(int a=0;a<=150;a++){
        servo2.write(a);
        delay(20);
        s=HC05.read();
      }
      i++;
    }
    delay(tiempo);
    s=HC05.read();
  }
  delay(tiempo);
  if(s=='2'){
    if(i==1){
      for(int a=150;a>=0;a--){
        servo2.write(a);
        delay(20);
        s=HC05.read();
      }
      i--;
    }   
    delay(tiempo);
    s=HC05.read();              //termina servo dos
  }

  delay(tiempo);                              //

  if(s=='5'){                   //empieza servo tres
    if(j==0){
      Serial.println("a");
      for(int a=0;a<=150;a++){
        servo3.write(a);
        delay(20);
        s=HC05.read();
      }
      j++;
    }
    delay(tiempo);
    s=HC05.read();
  }
  delay(tiempo);
  if(s=='4'){
    if(j==1){
      for(int a=150;a>=0;a--){
        servo3.write(a);
        delay(20);
        s=HC05.read();
      }
      j--;
    }   
    delay(tiempo);
    s=HC05.read();              //termina servo tres
  }

  delay(tiempo);                              //

  if(s=='7'){                   //empieza servo cuatro
    if(k==0){
      for(int a=0;a<=180;a++){
        servo4.write(a);
        delay(20);
        s=HC05.read();
      }
      k++;
    }
    delay(tiempo);
    s=HC05.read();
  }
  delay(tiempo);
  if(s=='6'){
    if(k==1){ 
      for(int a=180;a>=0;a--){
        servo4.write(a);
        delay(20);
        s=HC05.read();
      }
      k--;
    }   
    delay(tiempo);
    s=HC05.read();              //termina servo cuatro
  }

  delay(tiempo);                              //                                  
  
  if(s=='9'){                   //empieza servo cinco
    if(l==0){
      for(int a=0;a<=180;a++){
        servo5.write(a);
        delay(20);
        s=HC05.read();
      }
      l++;
    }
    delay(tiempo);
    s=HC05.read();
  }
  delay(tiempo);
  if(s=='8'){
    if(l==1){
      for(int a=180;a>=0;a--){
        servo5.write(a);
        delay(20);
        s=HC05.read();
      }
      l--;
    }   
    delay(tiempo);
    s=HC05.read();              //termina servo cinco
  }
  delay(tiempo);
}
