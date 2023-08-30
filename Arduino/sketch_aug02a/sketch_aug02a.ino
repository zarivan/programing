const int  ___
char ____

void setup() {
  // put your setup code here, to run once:
  pinMode(___, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    dato = Serial.read();
    if(dato == '1')
    {
      digitalWrite(led, HIGH);
    }
    if(dato == '0')
    {
      digitalWrite(led, LOW);
    }
  }

}
