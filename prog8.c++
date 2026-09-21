int Smoke_Sensor = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  Smoke_Sensor = analogRead(A0);

  Serial.print("Smoke Sensor Value = ");
  Serial.println(Smoke_Sensor);

  if (Smoke_Sensor >= 140)
  {
    digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(5, LOW);
  }

  if (Smoke_Sensor >= 150)
  {
    digitalWrite(7, HIGH);
  }
  else
  {
    digitalWrite(7, LOW);
  }

  delay(100);
}
