long time = 0;
const int trig = 12, echo = 13;

const int led1 = 2;


void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(led1, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  time = pulseIn(echo, HIGH)/2;
  float distance = time*0.0343;
  
  Serial.println(distance);
  delay(100);


  if(distance > 40){

    digitalWrite(led1, HIGH);
    
  }
  else{
    digitalWrite(led1, LOW);
  }
  
}