// motor 1
const int motor1 = 9, mi_g1 = 2, mi_g2 = 3;  // motor 1
const int motor2 = 11, md_g1 = 12, md_g2 = 13; // motor 2
const int outputs = 3;


int salidas[outputs] = {motor1, giroDer, giroIzq};


void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < outputs; i++){
    pinMode(salidas[i], OUTPUT);   
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor1, HIGH);

  digitalWrite(giroDer, HIGH);
  digitalWrite(giroIzq, LOW);
  delay(1000);
  
  digitalWrite(motor1, LOW);
  delay(1000);
  
  digitalWrite(motor1, HIGH);

  digitalWrite(giroDer, LOW);
  digitalWrite(giroIzq, HIGH);
  delay(1000);
  digitalWrite(motor1, LOW);
  delay(1000);
  
}



int avanzar(){
  if(
}
