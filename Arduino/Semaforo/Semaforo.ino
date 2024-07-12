const int verde = 12, amarillo = 11, rojo = 10;
const int tiempoV = 5000, tiempoA = 2000, tiempoR = 7000;



void setup() {
  // put your setup code here, to run once:
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(verde, HIGH);
  digitalWrite(rojo, LOW);
  delay(tiempoV);
  
  digitalWrite(amarillo, HIGH);
  digitalWrite(verde, LOW);
  delay(tiempoA);
  
  digitalWrite(amarillo, LOW);
  digitalWrite(rojo, HIGH);
  delay(tiempoR);
}
