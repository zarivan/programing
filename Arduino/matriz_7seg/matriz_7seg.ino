
const int d4 = 9, d3 = 10, d2 = 11, d1 = 12;
int contar = 0, tiempo = 500;
int dmin = 2, umin = 3, dseg = 5, useg = 0  ;

byte numero[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // Número 0
  {0, 1, 1, 0, 0, 0, 0},  // Número 1
  {1, 1, 0, 1, 1, 0, 1},  //número 2
  {1, 1, 1, 1, 0, 0, 1},  // Número 3
  {0, 1, 1, 0, 0, 1, 1},  // Número 4
  {1, 0, 1, 1, 0, 1, 1},  // Número 5
  {1, 0, 1, 1, 1, 1, 1},  // Número 6
  {1, 1, 1, 0, 0, 0, 0},  // Número 7
  {1, 1, 1, 1, 1, 1, 1},  // Número 8
  {1, 1, 1, 1, 0, 1, 1}   // Número 9
};

void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= 12; i++){
    pinMode(i, OUTPUT); 
    digitalWrite(i, LOW);
  }
}
// ********Código principal***********************


void loop() {
  disp7(d4); // Que digito se enciende ***** unidades de segundos
  num(useg);   // Número a mostrar
            // han pasado 500 microsegundos.
  disp7(d3);
  num(dseg);

  disp7(d2);
  num(umin);

  disp7(d1);
  num(dmin);
  
          // han pasado 2000 microsegundos o 2 milisegundos
  contar++;
  if(contar > 499){ // cada 500 en valor, es un segundo.
    contar = 0;
    useg++;
  }
  if(useg > 9){
    useg = 0;
    dseg++;
  }
  if(dseg > 5){
    dseg = 0;
    umin++;
  }
  if(umin>9){
    umin=0;
    dmin++;
  }
  if(dmin == 2 && umin == 4){
    umin=0;
    dmin=0;
  }

}



// ****************************************
void contador(){
  for(int j = 0; j <= 9; j++){
    
    for(int e = 0; e <= 6; e++){
      digitalWrite(e+2, numero[j][e]);
    }
    delay(500);  
  }
}
int num(int N){
  for(int e = 0; e <= 6; e++){
      digitalWrite(e+2, numero[N][e]);
  }
}


int disp7(int dig){
  delayMicroseconds(tiempo);
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
  
  digitalWrite(dig, LOW);
}
