#define LED 2
#define SENSOR A0

int lecturaSensor = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() 
{
  lecturaSensor = analogRead(SENSOR);
  Serial.println(lecturaSensor);
  if (lecturaSensor != 0)
    digitalWrite(LED,1);
  else
    digitalWrite(LED,0);
}
