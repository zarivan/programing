const int CENTRAL_LED = 7;
const int PLAYER1_LEDS[] = {3, 4, 5};
const int PLAYER2_LEDS[] = {10, 9, 8};
const int PLAYER1_BUTTON = 2;
const int PLAYER2_BUTTON = 11;

int player1Score = 0;
int player2Score = 0;
bool gameActive = false;
unsigned long lastActivationTime = 0;
const unsigned long activationInterval = 2000; // 2 segundos

void setup() {
  pinMode(CENTRAL_LED, OUTPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(PLAYER1_LEDS[i], OUTPUT);
    pinMode(PLAYER2_LEDS[i], OUTPUT);
  }
  pinMode(PLAYER1_BUTTON, INPUT_PULLUP);
  pinMode(PLAYER2_BUTTON, INPUT_PULLUP);
  randomSeed(analogRead(0));
  inicio();
  delay(5000);
}

void loop() {
  if (!gameActive && millis() - lastActivationTime > activationInterval) {
    activateCentralLED();
  }

  if (gameActive) {
    if (digitalRead(PLAYER1_BUTTON) == LOW) {
      scorePoint(1);
    } else if (digitalRead(PLAYER2_BUTTON) == LOW) {
      scorePoint(2);
    }
  }
}

void activateCentralLED() {
  digitalWrite(CENTRAL_LED, HIGH);
  gameActive = true;
  lastActivationTime = millis();
}

void scorePoint(int player) {
  gameActive = false;
  digitalWrite(CENTRAL_LED, LOW);

  if (player == 1) {
    digitalWrite(PLAYER1_LEDS[player1Score], HIGH);
    player1Score++;
  } else {
    digitalWrite(PLAYER2_LEDS[player2Score], HIGH);
    player2Score++;
  }

  if (player1Score == 3 || player2Score == 3) {
    endGame(player);
  }

  delay(1000); // Pequeña pausa para evitar rebotes
}

void endGame(int winner) {
  // Secuencia de triunfo
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      digitalWrite(winner == 1 ? PLAYER1_LEDS[j] : PLAYER2_LEDS[j], HIGH);
    }
    delay(200);
    for (int j = 0; j < 3; j++) {
      digitalWrite(winner == 1 ? PLAYER1_LEDS[j] : PLAYER2_LEDS[j], LOW);
    }
    delay(200);
  }

  // Reiniciar el juego
  player1Score = 0;
  player2Score = 0;
  for (int i = 0; i < 3; i++) {
    digitalWrite(PLAYER1_LEDS[i], LOW);
    digitalWrite(PLAYER2_LEDS[i], LOW);
  }
}


void inicio()
{
  for (int j=0; j<5; j++)
  {
    for(int i=3; i<=10; i++)
    {
      digitalWrite(i, HIGH);
      delay(50);
      digitalWrite(i, LOW);
    }
  }
}
