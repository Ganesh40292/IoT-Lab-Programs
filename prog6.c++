//Define the pin where the sensor is connected

const int sensorPin=A0;

const int ledPin=13;

const int buzzPin=12;

//Define moisture Threshold value

const int dryThreshold=800;

const int wetThreshold=500;

void setup(){

  //Initialize the serial communication

  Serial.begin(9600);

  //Set the LED pin as output

  pinMode(ledPin,OUTPUT);

  pinMode(buzzPin,OUTPUT);

  Serial.println("Soil Moisture Sensor test Starting....");

}

void loop(){

  //Read the sensor value

  int sensorValue=analogRead(sensorPin);

  //Print the sensor value for debugging

  Serial.print("Soil Moisture Level:");

  Serial.println(sensorValue);

  //check soilMoisture levels and take action

  if(sensorValue>dryThreshold){

    Serial.println("Soil is DRY Watering required.");

    digitalWrite(ledPin,HIGH);//Turn on the LED as an alert

    digitalWrite(buzzPin,HIGH);

  }

  else{

    Serial.println("Soil is wet");

    digitalWrite(ledPin,LOW);//Turn off the LED

    digitalWrite(buzzPin,LOW);

  }

}
