int hermanos = 3;
float calificacion = 8;
boolean gato = false; 
long distancia = 100000;
char letra = 3;
int mascotas = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("mascotas ");
  Serial.println(mascotas);
  mascotas++;
  
}
