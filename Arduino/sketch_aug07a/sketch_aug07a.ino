const int led1 = 2, led2 = 3;
char dato;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available() > 0)
  {
    dato = Serial.read();
    int valor = dato - 48;
     int brillo = valor*255/10;
    // Serial.println(valor);
    if(valor > 0)
    {
 
      for(int i = 0; i <= 5; i++)
      {
        digitalWrite(led1, HIGH);
        delay(valor*100);
          digitalWrite(led1, LOW);
        delay(valor*100);
      }
      analogWrite(led2, brillo);
    }
    else
    {
      digitalWrite(led1, LOW);
    }
  }
}
