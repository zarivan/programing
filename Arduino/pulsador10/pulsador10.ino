const int boton = 2;
const int led = 12;

void setup() {
  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(boton) == HIGH){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }

}
