const int boton = 2;
const int LED = 12;
boolean ESTADO = 0;

void setup() {
  pinMode(boton, INPUT);
  pinMode(LED, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(boton) == LOW){ //ESPERA A QUE EL BOTÓN SEA PRECIONADO.
    
  }

  digitalWrite(LED, HIGH);
  delay(5000);
  digitalWrite(LED, LOW);

  
  while(digitalRead(boton) == HIGH){ // ESPERA A QUE SE SUELTE EL BOTON
    
  }

}
