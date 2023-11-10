const int trigPin = 12;
const int echoPin = 11; 
const int relayPin = 10; 

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() { 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  long duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia en centímetros
  int distance = duration * 0.034 / 2;

  // Imprimir la distancia en el Monitor Serie
  Serial.print("Distancia: ");
  Serial.println(distance);


  if (distance < 30) {
  
    digitalWrite(relayPin, HIGH);
  } else {
 
    digitalWrite(relayPin, LOW);
  }

  delay(500); 
}

