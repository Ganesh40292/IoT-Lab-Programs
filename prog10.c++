void setup()
{
    pinMode(8, INPUT_PULLUP);
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    Serial.begin(9600);
}
void loop()
{
    // Receive serial data
    if (Serial.available() > 0)
    {
        char data_rcvd = Serial.read();
        if (data_rcvd == ' ')
        {
            digitalWrite(13, HIGH);
        }
        else if (data_rcvd == '0')
        {
            digitalWrite(13, LOW);
        }
    }
    // Read input pin and transmit its state
    if (digitalRead(8) == HIGH)
    {
        Serial.write('0');
    }
    else
    {
        Serial.write('1');
    }
    delay(100);  // Prevent sending data too rapidly
}
