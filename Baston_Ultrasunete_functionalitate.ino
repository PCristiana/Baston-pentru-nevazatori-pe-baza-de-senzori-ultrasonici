// Cod pentru baston inteligent pentru nevăzători
// Utilizează Arduino Uno, senzor HC-SR04, motor vibrator 3V, buzzer, rezistor, tranzistor NPN

// Definirea pinilor pentru senzorul HC-SR04
const int trigPin = 8;
const int echoPin = 9;

// Pinul pentru motorul vibrator și buzzer
const int motorPin = 10;
const int buzzerPin = 11;

// Definirea notelor muzicale în Hz
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494

void setup() {
  // Inițializare pini
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Pornire comunicare serială pentru debug
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Trimite un puls ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);


  distance = duration * 0.034 / 2;

  Serial.print("Distanta: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logica pentru intensitatea vibratiilor si melodiilor prietenoase
  if (distance > 75 && distance <= 100) {
    
    analogWrite(motorPin, 64); 
    playMelodyShort();
  } else if (distance > 50 && distance <= 75) {
 
    analogWrite(motorPin, 128); 
    playMelodyMedium();
  } else if (distance > 25 && distance <= 50) {

    analogWrite(motorPin, 192); 
  } else if (distance > 0 && distance <= 25) {
    
    analogWrite(motorPin, 255); 
    tone(buzzerPin, NOTE_A4);
  } else {
   
    digitalWrite(motorPin, LOW);
    noTone(buzzerPin);
  }


  delay(100);
}

void playMelodyShort() {
  tone(buzzerPin, NOTE_C4, 150);
  delay(200);
  tone(buzzerPin, NOTE_E4, 150);
  delay(200);
  tone(buzzerPin, NOTE_G4, 150);
  delay(200);
  noTone(buzzerPin);
}

void playMelodyMedium() {
  tone(buzzerPin, NOTE_C4, 150);
  delay(200);
  tone(buzzerPin, NOTE_D4, 150);
  delay(200);
  tone(buzzerPin, NOTE_E4, 150);
  delay(200);
  tone(buzzerPin, NOTE_F4, 150);
  delay(200);
  noTone(buzzerPin);
}

void playMelodyLong() {
  tone(buzzerPin, NOTE_C4, 150);
  delay(200);
  tone(buzzerPin, NOTE_E4, 150);
  delay(200);
  tone(buzzerPin, NOTE_G4, 150);
  delay(200);
  tone(buzzerPin, NOTE_A4, 150);
  delay(200);
  tone(buzzerPin, NOTE_B4, 150);
  delay(200);
  tone(buzzerPin, NOTE_C4, 150);
  delay(200);
  noTone(buzzerPin);
}
