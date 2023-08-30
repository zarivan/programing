int led1 = 2, led2 =  3, led3 = 4;
const int brillo = 0;
const int trig = 11;
const int echo = 12;
// Inicializar el programa
void setup() {
  // Habilitar los pines de los LEDs como salidas
  for (int i = 2; i < 7; i++) 
  {
    pinMode(i, OUTPUT);
  }
  // Colocar los pines del sensor ultrasonico como entrada y salida
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);


  long tiempo  = pulseIn(echo, HIGH);
  float distancia = 0.0343 * tiempo / 2;

  Serial.print("la distancia es: ");
  Serial.println(distancia);
  delay(50);


  if(distancia < 20)
  {
    digitalWrite(led1, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
  }
  
  if(distancia < 30)
  {
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
  }

   // SI LA DISTANCIA ES MENOR A 255 el led debe encender con PWM
  if(distancia < 100)
  {
    analogWrite(led3, 255-distancia);
  }
  else
  {
    digitalWrite(led3, 0);
  }
  
}
