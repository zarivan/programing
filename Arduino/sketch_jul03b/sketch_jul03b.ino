const int trig = 12, echo = 13, vcc = 11;
const int buzN = 5, buzP = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(vcc, OUTPUT);
  pinMode(buzN, OUTPUT);
  pinMode(buzP, OUTPUT);
  digitalWrite(vcc, HIGH);
  digitalWrite(buzN, LOW);
  digitalWrite(buzP, LOW);
  Serial.begin(9600);
}

void loop() {
  // Código para mandar el pulso del "disparador".
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  // código para el echo
  float tiempo = pulseIn(echo, HIGH)/2;
  float distancia = 0.0343*tiempo;

  Serial.print("la distancia es: ");
  Serial.println(distancia);
  delay(100);

  if(distancia < 50){
    digitalWrite(buzP, HIGH);
    delay(distancia);
    digitalWrite(buzP, LOW);
  }
  else{
    digitalWrite(buzP, LOW);
  }
  
  
}
