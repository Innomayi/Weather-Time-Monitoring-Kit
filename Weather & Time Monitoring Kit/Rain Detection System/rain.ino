int rainPin = 2;     
int ledPin = 8;      
int buzzerPin = 9;   

void setup() {
  pinMode(rainPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  int rainState = digitalRead(rainPin);

  // Rain detected
  if (rainState == LOW) {

    digitalWrite(ledPin, HIGH);

    // Higher tone buzzer sound
    tone(buzzerPin, 3000);   // Frequency in Hz

  } 
  else {

    digitalWrite(ledPin, LOW);

    noTone(buzzerPin);       // Stop buzzer
  }

  delay(100);
}