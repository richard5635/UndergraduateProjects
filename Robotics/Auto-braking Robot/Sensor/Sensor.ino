//Brakepoints
//With 9V Battery and USB Cable 307 (White)
//With just 9V Battery

#define Brakepoint 307

int Sensor;
int MotorPin0 = 3;
int MotorPin1 = 5;
int Counter = 0;


void setup()
{
  pinMode(MotorPin0, OUTPUT);
  pinMode(MotorPin1, OUTPUT);
  Serial.begin(9600);
  delay(100);
}

/* ==================================================================================*/
/* This is the main command of the robot */
/* ==================================================================================*/

//15cm value = 348

void loop()
{
  Sensor=analogRead(1);
  
  Serial.print("Sensor value is :");
  Serial.print(Sensor);
  Serial.print("\n");
  
  delay(500);
}

/*=============================================*/
/*These are the functions                      */
/*=============================================*/
void Advance()
{
  digitalWrite(MotorPin0,LOW);
  analogWrite(MotorPin1,200);
  
  Serial.print("Advance\t");
  Serial.print(Sensor);
  Serial.print("\n");
  Counter = 1;
  
  delay(100);
  
}
void Stop()
{
  if(Counter==1)
  {
    analogWrite(MotorPin0,100);
    digitalWrite(MotorPin1,LOW);
    delay(300);
  }
  digitalWrite(MotorPin0,HIGH);
  digitalWrite(MotorPin1,HIGH);
  
  Serial.print("Stop\t");
  Serial.print(Sensor);
  Serial.print("\n");
  Counter=0;
  
  delay(100);

}

