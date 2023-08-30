
const int d4 = 10, d3 = 11, d2 = 12, d1 = 13;
int contar = 0, tiempo = 500;
int decimal = 0, unidades = 0, decenas = 0;
float temperatura = 21.5;

byte numero[11][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // Número 0
  {0, 1, 1, 0, 0, 0, 0},  // Número 1
  {1, 1, 0, 1, 1, 0, 1},  //número 2
  {1, 1, 1, 1, 0, 0, 1},  // Número 3
  {0, 1, 1, 0, 0, 1, 1},  // Número 4
  {1, 0, 1, 1, 0, 1, 1},  // Número 5
  {1, 0, 1, 1, 1, 1, 1},  // Número 6
  {1, 1, 1, 0, 0, 0, 0},  // Número 7
  {1, 1, 1, 1, 1, 1, 1},  // Número 8
  {1, 1, 1, 1, 0, 1, 1},   // Número 9
  {1, 0, 0, 1, 1, 1, 0}   // Letra C
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
  decenas = temperatura/10;
  unidades = temperatura-(decenas*10);
  decimal = temperatura*10-decenas*100-unidades*10;
  
  disp7(d4); // Que digito se enciende ***** unidades de segundos
  num(10);   // Número a mostrar (letra C)
            // han pasado 500 microsegundos.
  disp7(d3);
  num(decimal);

  disp7(d2);
  num(unidades);

  disp7(d1);
  num(decenas);
  
}



// ****************************************
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
