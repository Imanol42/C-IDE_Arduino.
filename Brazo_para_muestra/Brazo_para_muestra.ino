#include<Servo.h>         //SE INCLUYE LA LIBRERIA DE MOTOR SERVO 
Servo mano;               //SE LE ASIGNA UN NOMBRE AL SERVO

#include <Wire.h>
#include<LiquidCrystal_I2C.h>    //SE INCLUYE LA LIBRERIA PARA EL LCD DE 16x2 
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define X_STEP_PIN      54//SE DEFINE PIN DE MOTORES PaP "X"  
#define X_DIR_PIN       55
#define X_ENABLE_PIN    38
#define X_MIN_PIN       3
#define X_MAX_PIN       2 //SE DEFINE PIN DE MOTORES PaP "X"

#define Y_STEP_PIN      60//SE DEFINE PIN DE MOTORES PaP "Y"
#define Y_DIR_PIN       61
#define Y_ENABLE_PIN    56
#define Y_MIN_PIN       14
#define Y_MAX_PIN       15//SE DEFINE PIN DE MOTORES PaP "Y"

#define Z_STEP_PIN      46//SE DEFINE PIN DE MOTORES PaP "Z"
#define Z_DIR_PIN       48
#define Z_ENABLE_PIN    62
#define Z_MIN_PIN       18
#define Z_MAX_PIN       19//SE DEFINE PIN DE MOTORES PaP "Z"

#define E_STEP_PIN      26//SE DEFINE PIN DE MOTORES PaP "E"
#define E_DIR_PIN       28
#define E_ENABLE_PIN    24//SE DEFINE PIN DE MOTORES PaP "E"

#define Q_STEP_PIN      36//SE DEFINE PIN DE MOTORES PaP "E1"
#define Q_DIR_PIN       34
#define Q_ENABLE_PIN    30//SE DEFINE PIN DE MOTORES PaP "E1"

#include <Keypad.h>       //SE INCLUYE LA LIBRERIA DEL TECLADO MATRICIAL 
const byte FILAS = 4;     //DECLARAMOS LA CANTIDAD DE FILAS
const byte COLUMNAS = 4;  //DECLARAMOS LA CANTIDAD DE COLUMNAS
char teclas[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},   //ASIGNAMOS UN DETERMINADO CARACTER A LOS BOTONES CORRESSPONCIENTES AL CRUCE DE LAS FILAS Y COLUMNAS
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte filasPins[FILAS] = { 41, 39, 37, 35}; //SE DECLARAN LOS PINES DE LAS FILAS
byte columnasPins[COLUMNAS] = {43, 45, 47, 32};//SE DECLARAN LOS PINES DE LAS COLUMNAS
Keypad teclado1 = Keypad(makeKeymap(teclas), filasPins, columnasPins, FILAS, COLUMNAS);//SE HACE EL MAPEO O RECORRIDO POR LOS CARACTERES AGREGADOS

#define contra "444*"   //DEFINIMOS UNA CONTRASEÑA PARA INGRESAR AL MENÚ DEL BRAZO

String numeros = "";   //VARIABLE DE CADENA DE CARACTERES PARA GUARDAR LOS DATOS
String M = "";
char s = ' ' , p = 'n';
int m = 1, f = 0;

void setup() {
  // put your setup code here, to run once:
  mano.attach(11);          //PIN DEL SERVO
  mano.write(180);          //SE LE DA UNA POSICION INICIAL DE 180 GRADOS AL SERVO

  pinMode(X_STEP_PIN  , OUTPUT);//SE DEFINEN LOS PINES COMO SALIDA PARA LOS PaP
  pinMode(X_DIR_PIN    , OUTPUT);
  pinMode(X_ENABLE_PIN    , OUTPUT);

  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN    , OUTPUT);

  pinMode(Z_STEP_PIN  , OUTPUT);
  pinMode(Z_DIR_PIN    , OUTPUT);
  pinMode(Z_ENABLE_PIN    , OUTPUT);

  pinMode(E_STEP_PIN  , OUTPUT);
  pinMode(E_DIR_PIN    , OUTPUT);
  pinMode(E_ENABLE_PIN    , OUTPUT);

  pinMode(Q_STEP_PIN  , OUTPUT);
  pinMode(Q_DIR_PIN    , OUTPUT);
  pinMode(Q_ENABLE_PIN    , OUTPUT);//SE DEFINEN LOS PINES COMO SALIDA PARA LOS PaP

  digitalWrite(X_ENABLE_PIN    , LOW);//SE HABILITAN LOS PINES DE CADA MOTOR PARA EMPEZAR A FUNCONAR
  digitalWrite(Y_ENABLE_PIN    , LOW);
  digitalWrite(Z_ENABLE_PIN    , LOW);
  digitalWrite(E_ENABLE_PIN    , LOW);
  digitalWrite(Q_ENABLE_PIN    , LOW);//SE HABILITAN LOS PINES DE CADA MOTOR PARA EMPEZAR A FUNCONAR
  
  //Inicializacion de pantalla LCD con comunicacion I2C. Se establece la velocidad de comunicacion y limpieza de datos guardados en pantalla 
  Serial2.begin(9600);     
  Serial.begin(9600);      
  lcd.init();              
  lcd.backlight();         
  lcd.clear();             
  lcd.setCursor(0, 0);     //POSICIONAMOS EL CURSOR DEL DISPLAY EN LA COLUMNA 0 Y FILA 0 PARA ESCRIBIR
  lcd.print(" PROYECTO 2019 ");//MANDAMOS EL MENSAJE
  lcd.setCursor(0, 1);     //POSICIONAMOS EL CURSOR DEL DISPLAY EN LA COLUMNA 0 Y FILA 1 PARA ESCRIBIR
  lcd.print(" BRAZO ROBOTICO ");//MANDAMOS EL MENSAJE
  delay(5000);             
  lcd.clear();             
}

void loop() {

  contrasena();              //LLAMAMOS A LA FUNCION CONTRASEÑA

}

void contrasena() {
  for (int v = 1; v < 1; v--) {     //SE IGUALA UNA VARIABLE TIPO ENTERA A 1 SE COMPARA SI V ES MENOR QUE 1 SE DECREMENTA EN 1
    lcd.clear();
    numeros = "";
  }
  char teclas = teclado1.getKey();     // CUANDO SE PRESIONE UNA TECLA SE ALMACENA EN LA VARIABLE TIPO char 'teclas

  if (numeros == "") {
    for (int v = 1; v < 1; v--) {  //SE IGUALA UNA VARIABLE TIPO ENTERA A 1 SE COMPARA SI V ES MENOR QUE 1 SE DECREMENTA EN 1
      lcd.clear();
    }
    lcd.setCursor(0, 0);
    lcd.print("   INGRESE ");
    lcd.setCursor(0, 1);
    lcd.print("   CONTRASENA");
  }

  if (teclas != NO_KEY) {           //CUANDO TECLAS SEA DISTINTO DE NO ESTAR PRESIONADA ENTRA EN EL CONDICIONAL
    lcd.clear();
    numeros = numeros + teclas;
    lcd.setCursor(0, 0);
    lcd.print(numeros);
    if (teclas == '*') {              //ENTRA A COMPARARA LA CONTRASEÑA INGRESADA CON LA CONTRRASEÑA DEFINIDA
      while (numeros == contra) {     //MIENTRAS QUE CONTRA SEA IGUAL A NUMEROS SE LLAMARÁ A LA FUNCION MENÚ
        menu();
      }
      if (numeros != contra) {        //SI LA CONTRASEÑA INGRESADA ES DISTINTA A LA CONTRASEÑA DEFINIDA MANDARA EL SIGUIENTE MENSAJE
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("LA CONTRASENA");
        lcd.setCursor(0, 1);
        lcd.print("INGRESADA ES");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("INCORRECTA");
        delay(2000);
        numeros = "";                  //Y TAMBIEN IGUALARA LA VARIABLE NUMEROS A NADA LO QUE NOS LLEVARÁ A INGRESAR NUEVAMENTE LA CONTRASEÑA
      }
    }
  }
}


void menu() {
  for (int v = 1; v < 1; v--) {        //SE ESCRIBIRA EL MENSAJE QUE SE MANDA EN ESTE CONDICIONAL
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SELECCIONE MODO");
    lcd.setCursor(0, 1);
    lcd.print(" DE OPERACION");
    delay(1500);
    lcd.clear();                        //SE BORRA UNA SOLA VEZ
  }
  lcd.setCursor(0, 0);
  lcd.print("MANUAL: A       ");        //MANDA EL MENSAJE DE MODO DE OPERACIÓN AL LCD
  lcd.setCursor(0, 1);
  lcd.print("AUTOMATICO: B   ");

  char teclas = teclado1.getKey();      //SI SE PRESIONA UNA TECLA DEL KEYPAD Y SE ALMACENA EN LA VARIABLE TECLAS

  while (teclas == 'B') {
    teclas = 'W';
    movimiento_automatico();
  }
  if (teclas == 'A') {
    for (int v = 1; v < 1; v--) {
      lcd.clear();
    }
    p = 'n';
    lcd.setCursor(0, 0);
    lcd.print("  PUEDE OPERAR  ");
    lcd.setCursor(0, 1);
    lcd.print("    EL BRAZO    ");
  }
  while (teclas == 'A') {
    movimiento_manual();
  }
}

void movimiento_manual() {
  for (int v = 1; v < 1; v--) {
    lcd.clear();
  }
  Serial.println("adentro de manual");

  if (Serial2.available() || (p != '0' && p != 'n')) { //PREGUNA SI HAY BYTES POR LEER EN EL SERIAL 2(BLUETOOTH) O SI 'p' ES DISTINTO DE '0' Y DISTINTO DE 'n'
    char s = Serial2.read();                           //IGUALA LOS DATOS TIPOS CARACTERES EN LA VARIABLE char "s"
    p = s;
    Serial.println(s);

    if (p != '0') {
      Serial.println("adentro de manual");
      lcd.setCursor(0, 0);
      lcd.print("CUIDADO BRAZO   ");
      lcd.setCursor(0, 1);
      lcd.print("EN MOVIMIENTO   ");
    }

    while (s == '1' && f <= 180) {                     //MOVIMIENTOS DE LA GARRA CON SERVO
      if (f == 180) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("MAXIMO ANGULO   ");
        lcd.setCursor(0, 1);
        lcd.print("PERMITIDO       ");
        s = '0';
        delay(1000);
      }
      f++;
      mano.write(f);
      delay(20);
      if (Serial2.available()) {
        s = Serial2.read();
      }
    }
    while (s == '2' && f >= 0) {
      if (f == 0) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("MAXIMO ANGULO   ");
        lcd.setCursor(0, 1);
        lcd.print("PERMITIDO       ");
        s = '0';
        delay(1000);
      }
      f--;
      mano.write(f);
      delay(20);
      if (Serial2.available()) {
        s = Serial2.read();
      }                                     //MOVIMIENTOS DE LA GARRA CON SERVO
    }

    while (s == '3') {                        //MOVIMIENTOS DE MUÑECA
      digitalWrite(Z_DIR_PIN, HIGH);
      delayMicroseconds(1);
      digitalWrite(Z_STEP_PIN, HIGH);
      delay(10);
      digitalWrite(Z_STEP_PIN, LOW);
      delay(10);
      if (Serial2.available()) {
        s = Serial2.read();
      }
    }
    while (s == '4') {
      digitalWrite(Z_DIR_PIN, LOW);
      delayMicroseconds(1);
      digitalWrite(Z_STEP_PIN, HIGH);
      delay(10);
      digitalWrite(Z_STEP_PIN, LOW);         //MOVIMIENTOS DE MUÑECA
      delay(10);
      if (Serial2.available()) {
        s = Serial2.read();
      }
    }

    while (s == '6') {                          //MOVIMIENTO DE CODO
      digitalWrite(X_DIR_PIN, HIGH);
      delay(1);
      digitalWrite(X_STEP_PIN, HIGH);
      delay(2);
      digitalWrite(X_STEP_PIN, LOW);
      delay(2);
      if (Serial2.available()) {
        s = Serial2.read();
      }
    }
    while (s == '5') {
      digitalWrite(X_DIR_PIN, LOW);
      delay(1);
      digitalWrite(X_STEP_PIN, HIGH);
      delay(2);
      digitalWrite(X_STEP_PIN, LOW);         //MOVIMIENTOS DE CODO
      delay(2);
      if (Serial2.available()) {
        s = Serial2.read();
      }
    }

    while (s == '8') {                          //MOVIMIENTOS DE HOMBRO
      digitalWrite(E_DIR_PIN, HIGH);
      delay(1);
      digitalWrite(E_STEP_PIN, HIGH);
      delay(2);
      digitalWrite(E_STEP_PIN, LOW);
      delay(2);
      if (Serial2.available()) {
        s = Serial2.read();
      }
    }

    while (s == '7') {
      digitalWrite(E_DIR_PIN, LOW);
      delay(1);
      digitalWrite(E_STEP_PIN, HIGH);
      delay(2);
      digitalWrite(E_STEP_PIN, LOW);         //MOVIMIENTOS DE HOMBRO
      delay(2);
      if (Serial2.available()) {
        s = Serial2.read();
      }
    }

    while (s == 'B') {                          //MOVIMIENTOS DE BASE
      digitalWrite(Y_DIR_PIN, HIGH);
      delayMicroseconds(0.1);
      digitalWrite(Y_STEP_PIN, HIGH);
      delay(20);
      digitalWrite(Y_STEP_PIN, LOW);
      delay(20);
      if (Serial2.available()) {
        s = Serial2.read();
      }
    }
    while (s == 'A') {
      digitalWrite(Y_DIR_PIN, LOW);
      delayMicroseconds(0.1);
      digitalWrite(Y_STEP_PIN, HIGH);
      delay(20);
      digitalWrite(Y_STEP_PIN, LOW);
      delay(20);                          //MOVIMIENTOS DE BASE
      if (Serial2.available()) {
        s = Serial2.read();
      }
    }

    if (s == '0') {
      digitalWrite(X_ENABLE_PIN , LOW);
      digitalWrite(Y_ENABLE_PIN , LOW);
      digitalWrite(Z_ENABLE_PIN , LOW);
      digitalWrite(E_ENABLE_PIN , LOW);
      digitalWrite(Q_ENABLE_PIN , LOW);
      m = 0;
      while (m != 1) {
        char i = teclado1.getKey();     // CUANDO SE PRESIONE UNA TECLA SE ALMACENA EN LA VARIABLE TIPO char 'teclas
        Serial.println("entro while de modo");
        lcd.setCursor(0, 0);
        lcd.print(" PARA VOLVER AL ");
        lcd.setCursor(0, 1);
        lcd.print("MENU PRESIONE: 1");
        while (i == '1') {
          menu();
        }
        if (Serial2.available()) {
          p = s;
          m = 1;
        }
      }
    }
  }
}
//Etapa en desarrollo 
/*void movimiento_automatico() {
  digitalWrite(E_DIR_PIN, HIGH);
  for (int i = 0; i <= 20; i++) {
    digitalWrite(E_STEP_PIN, HIGH);
    delay(5);
    digitalWrite(E_STEP_PIN, LOW);
  }
  delay(1000);
  digitalWrite(E_DIR_PIN, LOW);
  for (int i = 0; i <= 20; i++) {
    digitalWrite(E_STEP_PIN, HIGH);
    delay(5);
    digitalWrite(E_STEP_PIN, LOW);
  }
  delay(1000);

  digitalWrite(Z_DIR_PIN, HIGH);
  for (int i = 0; i <= 20; i++) {
    digitalWrite(Z_STEP_PIN, HIGH);
    delay(2);
    digitalWrite(Z_STEP_PIN, LOW);
  }
  delay(1000);

  digitalWrite(Z_DIR_PIN, LOW);
  for (int i = 0; i <= 20; i++) {
    digitalWrite(Z_STEP_PIN, HIGH);
    delay(2);
    digitalWrite(Z_STEP_PIN, LOW);
  }
  delay(1000);
}*/
