#define pot A0  // Entrada del potenciometro
#define motorVelocidad 9  // Salida para control de velocidad del Motor
#define s1 2 // Control de giro
#define s2 3 // Control de giro
#define izq 6
float voltaje = 0;
int pwm = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorVelocidad, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltaje = analogRead(pot)*5.00/1023.00;
  int x = analogRead(pot);
  pwm = map(x, 0, 1023, 0, 255);
  int porcentaje = map(pwm, 0, 255, 0, 100);
  Serial.print("Voltaje: ");
  Serial.print(x);
  Serial.print(" PWM: ");  
  Serial.print(pwm);
  Serial.print(" porcentaje: ");
  Serial.println(porcentaje);
  if(digitalRead(izq) == 1){
    digitalWrite(s1, HIGH);
    digitalWrite(s2, LOW);
  }
  else{
    digitalWrite(s1, LOW);
    digitalWrite(s2, HIGH);
  }
  
  analogWrite(motorVelocidad, pwm);
}
