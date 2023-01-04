int pin_sensor = 4;
int valor = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pin_sensor, INPUT); 
}

void loop()
{
  valor = digitalRead(pin_sensor);
  Serial.println(valor);
}
