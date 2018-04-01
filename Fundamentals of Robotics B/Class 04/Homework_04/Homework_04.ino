int ledPin=9;
int pressensorPin=A0;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int value=0;
  
  for (int i=0;i<5;i++)
{
  value=value+analogRead(pressensorPin);
}
  value=value/10;
  
if (value<=20)
{
   digitalWrite(ledPin,HIGH);
}
else{
    digitalWrite(ledPin,HIGH);
    delay(value);
    digitalWrite(ledPin,LOW);
    delay(value);
  };

}
