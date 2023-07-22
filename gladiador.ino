#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'
#define CIRCLE 'c'
#define CROSS 'x'
#define TRIANGLE 't'
#define SQUARE 's'
#define START 'S'
#define PAUSE 'P'

#define M1 12 // Pino_Velocidade 1º Motor ( 0 a 255)_ Porta IN2 ponte H
#define M2 10 //Pino_Velocidade 2º Motor ( 0 a 255) _ Porta IN4 ponte H
#define dir1 13 //Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H
#define dir2 11 //Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H

int velocidade = 255;

void setup() {
  Serial.begin(9600);

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
}

void loop() {
  while (Serial.available() != 0) {
    char dadoBluetooth = Serial.read();
    if(dadoBluetooth > 0) {
      executeCommand(dadoBluetooth);
    }
  }
}

void executeCommand(char dadoBluetooth) {
  switch (dadoBluetooth) {
    case UP:
      //Serial.println("UP");
      break;
    case DOWN:
      //Serial.println("DOWN");
      break;
    case LEFT:
      TurnLeft();
      break;
    case RIGHT:
      TurnRight();
      break;
    case CIRCLE:
      GoBackward();
      break;
    case CROSS:
      GoForward();
      break;
    case SQUARE:
      Stop();
      break;
    case TRIANGLE:
      //Serial.println("TRIANGLE");
      break;
    case START:
      //Serial.println("START");
      break;
    case PAUSE:
      //Serial.println("PAUSE");
      break;
    default:
      break;
  }
}

void GoForward() {
  //Ir para frente
  Serial.println("Estou indo para frente");

  digitalWrite(dir1, HIGH);  // Define a direção do motor 1 para frente (HIGH)
  digitalWrite(dir2, HIGH);  // Define a direção do motor 2 para frente (HIGH)
  analogWrite(M1, velocidade); // Ambos motores ligam na mesma velocidade
  analogWrite(M2, velocidade);
}

void GoBackward() {
  //Ir para trás
  Serial.println("Estou indo para trás");

  digitalWrite(dir1, LOW);  // Define a direção do motor 1 para trás (LOW)
  digitalWrite(dir2, LOW);  // Define a direção do motor 2 para trás (LOW)
  analogWrite(M1, velocidade);
  analogWrite(M2, velocidade);
}

void TurnLeft() {
  //Girar para a esquerda
  Serial.println("Estou virando para a esquerda");
  digitalWrite(dir1, LOW);  // Define a direção do motor 1 para trás (LOW)
  digitalWrite(dir2, HIGH); // Define a direção do motor 2 para frente (HIGH)
  analogWrite(M1, velocidade); // O motor 1 desliga
  analogWrite(M2, velocidade); // O motor 2 fica ligado, fazendo assim o carrinho virar
}

void TurnRight() {
  //Girar para a direita
  Serial.println("Estou virando para a direita");
  digitalWrite(dir1, HIGH);  // Define a direção do motor 1 para frente (HIGH)
  digitalWrite(dir2, LOW);   // Define a direção do motor 2 para trás (LOW)
  analogWrite(M1, velocidade); // O motor 1 fica ligado
  analogWrite(M2, velocidade); // O motor 2 desliga, fazendo assim o carrinho virar no outro sentido
}

void Stop(){
  //Parar
  Serial.println("Parei");
  analogWrite(M1, LOW); // Ambos motores desligam, fazendo o carrinho parar
  analogWrite(M2, LOW);
}
