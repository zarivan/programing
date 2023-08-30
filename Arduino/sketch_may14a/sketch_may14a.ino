const int v=10, a=11, r=12;
int tiempo = 1000;
bool cat = true;
String nombre;
void setup() {
  // put your setup code here, to run once:
  pinMode(v, OUTPUT); // Creación de comentarios
  Serial.begin(9600);
  Serial.println(" Hola ");
  Serial.println(" Cómo te llamas? ");

  while(Serial.available() == 0){
    
  }
  Serial.print("hola");
  Serial.println(nombre);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
