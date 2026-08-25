#define PIEZO_PIN 9

const int trigger = 6;
const int echo = 7;
const int soundPin = A0;

const float DIST_THRESHOLD = 5.0;
const int SOUND_THRESHOLD = 520;

void setup() {
  Serial.begin(9600);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigger, LOW);

  // Read echo
  unsigned long duration = pulseIn(echo, HIGH, 30000);

  // Calculate distance in inches
  float dist_inches = duration / 148.0;

  // Read sound sensor
  int soundValue = analogRead(soundPin);

  // Check for valid ultrasonic reading
  bool objectDetected = (duration > 0 && dist_inches < DIST_THRESHOLD);
  bool soundDetected = (soundValue > SOUND_THRESHOLD);

  if (objectDetected && soundDetected) {

    tone(PIEZO_PIN, 1500);
    delay(100);
    noTone(PIEZO_PIN);

    Serial.print("Intrusion Detected! Object with sound at distance: ");
    Serial.print(dist_inches);
    Serial.println(" in");

  } else if (objectDetected) {

    Serial.print("Object detected at distance: ");
    Serial.print(dist_inches);
    Serial.println(" in");

  } else if (soundDetected) {

    Serial.println("Sound detected!");

  } else {

    Serial.println("No intrusion detected.");
  }

  delay(100);
}
