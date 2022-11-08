int sensorValue = 0;

int outputValue = 0;

int seuil = 0;
  
int luminosite = 0;

void setup()
{
Serial.begin(9600);
  
pinMode(A0, INPUT);

}

void loop()
{
  delay(10); // Delay a little bit to improve simulation performance
}
