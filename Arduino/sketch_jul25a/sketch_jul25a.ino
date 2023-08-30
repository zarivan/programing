const int pin = A5;
int valor;
const int led = 9;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  valor = analogRead(pin);
  Serial.println(valor);
  delay(100);
  
  if(valor < 300)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
