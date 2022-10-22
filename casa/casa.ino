#define botonContenedorPrimLluvias 3
#define bombaPrimLluvias 2
#define bombaCisterna 9
#define sensorGas 4
#define verde 5
#define rojo 6
#define echo 7
#define trig 8

int contenedorPrimLluvias = 0;
int sensorLluvia = 0;
long t;
long d;

void setup()
{
  Serial.begin(9600);
  pinMode(botonContenedorPrimLluvias, INPUT);
  pinMode(bombaPrimLluvias, OUTPUT);
  pinMode(sensorGas, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW);
  Serial.println("El sensor de gas se esta pre-calentando");
  delay(10000);
}

void loop()
{
  sensorLluvia = analogRead(A1);
  Serial.println("sensor Lluvia");
  Serial.println(sensorLluvia);
  contenedorPrimLluvias = digitalRead(botonContenedorPrimLluvias);
  Serial.println(contenedorPrimLluvias);

  if ((sensorLluvia < 80) && (contenedorPrimLluvias == 0))
  {
    //no está lloviendo y hay agua
    digitalWrite(bombaPrimLluvias, HIGH);
    Serial.println("Vaciando");
  }
  else
  {
    digitalWrite(bombaPrimLluvias, LOW);
    Serial.println("No vaciando");
  }
  delay(250);

  boolean MQ_estado = digitalRead(sensorGas);
  if (MQ_estado)
  {
    Serial.println("Sin presencia de gases en el ambiente");
    analogWrite(verde, 255);
    analogWrite(rojo, 0);
  }
  else
  {
    Serial.println("Gases detectados en el ambiente");
    analogWrite(rojo, 255);
    analogWrite(verde, 0);
  }
  delay(250);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  d = t / 59;
  Serial.println("Distancia: ");
  Serial.println(d);
  if(d<10)
  {
    digitalWrite(bombaCisterna,HIGH);
  }
  else
  {
    digitalWrite(bombaCisterna,LOW);
  }
  delay(250);
}
