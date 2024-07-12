const int LED = 3;
const int POT = A0;
int brillo = 0;

void setup() {
  //pinMode(boton, INPUT);
  pinMode(LED, OUTPUT);
  
}

void loop() {
  
  brillo = analogRead(pot)/4;
  analogWrite(LED, brillo);

}
