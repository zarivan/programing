
char dato;
void setup() {
  // put your setup code here, to run once:
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    dato = Serial.read();
    
    
  }

}
