#define trigpin 6
#define echopin 7

void setup()
{
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(11,OUTPUT);

}

void loop()
{
  int duration,distance;
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(500);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=(duration/2)/29.1;
  if(distance<100)
  {
    Serial.print(distance);
    digitalWrite(11,HIGH);
  }
  else if(distance>100 || distance<30)
  {
    digitalWrite(11,LOW);
  }
}
  