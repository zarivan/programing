const int boton = 2;
const int LED = 12;
boolean ESTADO = 0;

void setup() {
  pinMode(boton, INPUT);
  pinMode(LED, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(boton) == LOW){
    
  }
  ESTADO = digitalRead(LED);
  digitalWrite(LED, !ESTADO);
  while(digitalRead(boton) == HIGH){
    
  }

}
