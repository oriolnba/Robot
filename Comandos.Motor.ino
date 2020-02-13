const int pinENAD = 10; // ENA RUEDA DERECHA
const int pinD1 = 9;  // ALANTE RUEDA DERECHA 
const int pinD2 = 8;  // ATRAS RUEDA DERECHA

const int pinENAI = 5; // ENA RUEDA IZQUIERDA
const int pinI1 = 6;  // ATRAS RUEDA IZQUIERDA
const int pinI2 = 7;  // ALANTE RUEDA IZQUIERDA
 
const int speed = 200;      //velocidad de giro 80% (200/255)

void setup()
{
   pinMode(pinENAD, OUTPUT);
   pinMode(pinD1, OUTPUT);
   pinMode(pinD2, OUTPUT);
   pinMode(pinI1, OUTPUT);
   pinMode(pinI2, OUTPUT);
   pinMode(pinENAI, OUTPUT);
}
 
void loop()
{ 
  
}

void Adelante
    digitalWrite(pinD1,HIGH);
    digitalWrite(pinI2,HIGH);
   
    
