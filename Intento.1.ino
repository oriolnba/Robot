const int EchoPin = 2;
const int TriggerPin = 3;
 
void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
  
}
 
void loop() {
   int distanceCm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(distanceCm);

   if ( distanceCm < 20) {
   digitalWrite(2,LOW);
   }
   
   else{
   digitalWrite(2,HIGH);
   }
   delay(100);  
   }

   
 **********************************************************// ARRIBA CODIGOS
 **********************************************************// ABAJO COMANDOS









 
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
