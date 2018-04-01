//Sensor Value Checking Program for Line Following Robot

#define SensorA A5;
#define SensorB A4;
#define SensorC A3;
#define SensorD A2;
#define SensorE A1;

int SensorAReading;
int SensorBReading;
int SensorCReading;
int SensorDReading;
int SensorEReading;

void setup ()
{
 
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);
  pinMode(A0,INPUT);
  
  Serial.begin(9600);

  delay(100);
}

void loop()
{
  for (int x=0; x<5; x++)
  {   
    SensorAReading += analogRead(5);
    SensorBReading += analogRead(4);
    SensorCReading += analogRead(3);
    SensorDReading += analogRead(2);
    SensorEReading += analogRead(1);
  }
  
  SensorAReading =  SensorAReading/5;
  SensorBReading =  SensorBReading/5;
  SensorCReading =  map((SensorCReading/5), 300, 1023, 0, 1023);
  SensorDReading =  map((SensorDReading/5), 400, 1023, 0, 1023);
  SensorEReading =  map((SensorEReading/5), 0, 1023, 0, 1023);
  
  Serial.print("\n\tA: ");
  Serial.print(SensorAReading);
  Serial.print("\tB: ");
  Serial.print(SensorBReading);
  Serial.print("\tC: ");
  Serial.print(SensorCReading);
  Serial.print("\tD: ");
  Serial.print(SensorDReading);
  Serial.print("\tE: ");
  Serial.print(SensorEReading);
  
  delay(1000);
}

