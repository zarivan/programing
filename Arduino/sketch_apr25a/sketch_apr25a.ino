int edad;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Dime tu edad: ");
  delay(1000);

  while( !Serial.available() ){
    
  }
  
  if (Serial.available() ){
    edad = Serial.parseInt();
  }
  Serial.println(edad);



  while( !Serial.available() ){
    
  }
  
  if (Serial.available() ){
    edad = Serial.parseInt();
  }
  
}
