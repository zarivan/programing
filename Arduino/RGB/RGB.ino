const int r = 3, g = 5, b = 6;
int br = 255;
int bg = 255;
int bb = 255;
void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    for (int i = 0; i < 255; i++)
    {
      
      analogWrite(r, 255);
      analogWrite(g, 0);
      analogWrite(b, 100);
      delay(10);
    }
}
