// C++ code
//************* Motor Izquierdo ************
const int motorIzq = 9, mi_g1 = 2, mi_g2 = 3;

//************* Motor Derecho **************
const int motorDer = 11, md_g1 = 12, md_g2 = 13;

// sensores
const int sensorIzq = 4;
const int sensorDer = 5;

void setup()
{
  // motor Izquierdo.
  pinMode(motorIzq, OUTPUT);
  pinMode(mi_g1, OUTPUT);
  pinMode(mi_g2, OUTPUT);
  
  // motor Derecho.
  pinMode(motorDer, OUTPUT);
  pinMode(md_g1, OUTPUT);
  pinMode(md_g2, OUTPUT);
  
  // sensores. 
  pinMode(sensorIzq, INPUT);
  pinMode(sensorDer, INPUT);
  
  
  // se determina el giro del motor. 
  digitalWrite(mi_g1, HIGH);
  digitalWrite(mi_g2, LOW);
  digitalWrite(md_g1, HIGH);
  digitalWrite(md_g2, LOW);

}

void loop()
{
  if(digitalRead(sensorIzq) == LOW){ 
    analogWrite(motorIzq, 255); // máximo 255.  
  }
  else{
    analogWrite(motorIzq, 0);   // apagado.
  }
  if(digitalRead(sensorDer) == LOW){
    analogWrite(motorDer, 255);
  }
  else{
    analogWrite(motorDer, 0);
  }
}
