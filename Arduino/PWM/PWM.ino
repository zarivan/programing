const int LED = 3;
int brillo;

void setup() {
  //pinMode(boton, INPUT);
  pinMode(LED, OUTPUT);
  
}

void loop() {
  for(brillo = 0; brillo < 256; brillo++){

    analogWrite(LED, brillo);
    delay(15);
    
  }
    for(brillo = 255; brillo >= 0; brillo--){

    analogWrite(LED, brillo);
    delay(15);
    
  }

}
