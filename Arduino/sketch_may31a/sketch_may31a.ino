const int verde = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(verde, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(verde, HIGH);
  delay(3000);
  digitalWrite(verde, LOW);
  
}
