int num1 = 3;
int num2 = 2;
int resultado = 0;
void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 baudios
  Serial.flush();
}

void loop() {
  num1 = random(0,9);
  num2 = random(0,9);
  Serial.print("¿Cuál es el resultado de?: ");
  Serial.print(num1);
  Serial.print("x");
  Serial.print(num2);
  Serial.println(" ");
  resultado = num1 * num2;
  while (!Serial.available()) { // Espera hasta que se presione una tecla
    // No hace nada
  }
  if (Serial.available()) { // Si hay datos disponibles en el puerto serie
    int valor = Serial.parseInt();// Lee el valor numérico
    if(valor == resultado){
      Serial.println("respuesta correcta");
    }
    else{
      Serial.println("Respuesta incorrecta");
    }
    Serial.print("resultado: ");
    Serial.println(resultado); // Imprime el valor en el monitor serie
    
  }
  delay(500);
  Serial.flush();
}
