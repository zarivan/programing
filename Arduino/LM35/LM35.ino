float voltaje = 10, temperatura = 0, valorSensor = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 
  valorSensor = analogRead(A0);
  voltaje = valorSensor*5/1023;
  temperatura = voltaje/0.01;
  
  
  Serial.print("Sensor: ");
  Serial.print(valorSensor);
  
  Serial.print(" Voltaje: ");
  Serial.print(voltaje);
  
  Serial.print(" Temperatura: ");
  Serial.println(temperatura);
  
  delay(1000);

  
}
