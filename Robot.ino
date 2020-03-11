const int EchoPin = 2;
const int TriggerPin = 3;

const int pinENAD = 10; // ENA RUEDA DERECHA
const int pinD1 = 9;  // ALANTE RUEDA DERECHA 
const int pinD2 = 8;  // ATRAS RUEDA DERECHA

const int pinENAI = 5; // ENA RUEDA IZQUIERDA
const int pinI1 = 6;  // ATRAS RUEDA IZQUIERDA
const int pinI2 = 7;  // ALANTE RUEDA IZQUIERDA
 
void setup()
   {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);

   pinMode(pinENAD, OUTPUT);
   pinMode(pinD1, OUTPUT);
   pinMode(pinD2, OUTPUT);
   pinMode(pinI1, OUTPUT);
   pinMode(pinI2, OUTPUT);
   pinMode(pinENAI, OUTPUT);
   }
 
void loop() {
   int distanceCm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(distanceCm);

   if ( distanceCm < 10)
   {
   moveStop();
   delay(1000); 
   moveAtras();
   delay(1000);
   turnLeft();

     if(distanceCm < 10)
     {
     moveStop();
     delay(1000);
     turnLeft();

       if(distanceCm < 10)
       {
       moveStop();
       delay(1000);
       turnLeft();
       }
       
       else{
       moveAdelante();
       }
     }
     
      else{
       moveAdelante();
       }
   }

    else{
       moveAdelante();
       }
  
  }
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
   }


  void moveStop()
  {
  digitalWrite(pinD1, LOW);
  digitalWrite(pinI2, LOW);
  digitalWrite(pinD2, LOW);
  digitalWrite(pinI1, LOW);
  }

void moveAdelante()
  {

  digitalWrite(pinI2, HIGH);
  digitalWrite(pinD1, HIGH);
  
  digitalWrite(pinI1, LOW);
  digitalWrite(pinD2, LOW); 
  
  }

void moveAtras()
  {
  
  digitalWrite(pinI1, HIGH);
  digitalWrite(pinD2, HIGH);
  
  digitalWrite(pinI2, LOW);
  digitalWrite(pinD1, LOW);
  
  }

void turnRight()
  {
  digitalWrite(pinI2, HIGH);
  digitalWrite(pinD2, HIGH);
  
  digitalWrite(pinI1, LOW);
  digitalWrite(pinD1, LOW);
  
  delay(500);
  
  digitalWrite(pinI2, HIGH);
  digitalWrite(pinD1, HIGH);
  
  digitalWrite(pinI1, LOW);
  digitalWrite(pinD2, LOW);
 
  }

void turnLeft()
  {
  digitalWrite(pinI1, HIGH);
  digitalWrite(pinD1,HIGH);
  
  digitalWrite(pinI2, LOW);
  digitalWrite(pinD2, LOW);

  delay(500);
  
  digitalWrite(pinI2, HIGH);
  digitalWrite(pinD1, HIGH);
  
  digitalWrite(pinI1, LOW);
  digitalWrite(pinD2, LOW);
  }
