int contar = 10;
const int bocina = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bocina, HIGH);
}

void loop() {
  
  if (contar < 1)
  {
    contar = 10;
    digitalWrite(bocina, HIGH);
    delay(50);
    digitalWrite(bocina, LOW);
  }
  else
  {
    contar = contar - 1;
  }
  Serial.println(contar);
  delay(1000);
}
