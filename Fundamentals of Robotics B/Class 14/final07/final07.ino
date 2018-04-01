#define SensorB   A1
#define SensorC   A2
#define SensorD   A3
#define SensorE   A4

int N=100;
int SensorBReading;
int SensorCReading;
int SensorDReading;
int SensorEReading;


int pinLin1 = 3; //in1 for left motor driver
int pinLin2 = 5; //in2 for left motor driver
int pinRin1 = 6; //in1 for Right motor driver
int pinRin2 = 9; //in2 for Right motor driver

int leftOffset = 0, rightOffset = 0, centreOffset = 0;
int pot1=A0;

int value1;//basespeed;


int turningspeedL,turningspeedR;
int constantS=30;//change it if speed is not enough
int errorL,errorR;

// Sensor calibration routine
void calibrate() {
  //average//
for (int x=0; x<N; x++)
{ 
  SensorCReading    = analogRead(2);
  SensorDReading     = analogRead(3);
  SensorEReading = analogRead(4);
leftOffset = leftOffset +  SensorCReading; // add value of left sensor to total
centreOffset = centreOffset +  SensorCReading; // add value of centre sensor to total
rightOffset = rightOffset +  SensorCReading; // add value of right sensor to total

delay(100);
}
// obtain average for each sensor
leftOffset = leftOffset / N;
rightOffset = rightOffset / N;
centreOffset = centreOffset /N;

Serial.println("\t leftOffset\t");
Serial.println(leftOffset );
Serial.println("\t rightOffset\t");
Serial.println(rightOffset);
Serial.println("\t centreOffset\t");
Serial.println(centreOffset);


}

void setup ()
{
  pinMode(pinLin1,OUTPUT);
  pinMode(pinLin2,OUTPUT);
  pinMode(pinRin1,OUTPUT);
  pinMode(pinRin2,OUTPUT);
 
  pinMode(SensorB, INPUT);
  pinMode(SensorC, INPUT);
  pinMode(SensorD, INPUT);
  pinMode(SensorE, INPUT);
  
  Serial.begin(9600);
  calibrate();
  delay(100);
}




void loop()
{
  int high;
  int low;
  high=850;// set the high threshold of sensor(we  have not checked yet)
  low=700;//set the low threshold of sensor
 
 
  SensorBReading  = analogRead(1);
  SensorCReading   = analogRead(2);
  SensorDReading = analogRead(3);
  SensorEReading   = analogRead(4);
 
  
    if (  SensorBReading<low &&   SensorCReading>high  &&  SensorDReading>high &&   SensorEReading>low)
  {
   value1=analogRead(A0);
   value1=map(value1,0,1023,0,255);
   errorL=SensorCReading-leftOffset;
   errorL=map(errorL,0,1023,0,63);
   turningspeedL=constantS*errorL;
   
  digitalWrite(pinLin1,LOW);
  digitalWrite(pinLin2,value1-turningspeedL);
  //the left motor goes under low speed
  digitalWrite(pinRin1,LOW);
  analogWrite(pinRin2,value1+turningspeedL);
  
  //the right motor goes under high speed
   Serial.print("\t left\n\t");
   delay(2000);
 
  }
  
 
  else if (  SensorBReading<low &&  SensorCReading<low &&  SensorDReading>high &&   SensorEReading>high)
  {
  value1=analogRead(A0);
  value1=map(value1,0,1023,0,255);
   errorR=SensorEReading-rightOffset;
   errorR=map(errorR,0,1023,0,1);
   turningspeedR=constantS*errorR;
  analogWrite(pinLin1,value1+turningspeedR);
  digitalWrite(pinLin2,LOW);
  //the left motor goes under high speed
    analogWrite(pinRin1,value1-turningspeedR);
   digitalWrite(pinRin2,LOW);
 

  //the right motor goes under low speed

    Serial.print("\t right\n\t");
    delay(2000);
 
  }
   
  
  else if (  SensorBReading<low &&   SensorCReading<low &&  SensorDReading>high &&   SensorEReading<low)
  {
    value1=analogRead(A0); 
    value1=map(value1-512, 0, 511, 0, 255);
    
   errorL=SensorCReading-leftOffset;
   errorL=map(errorL,-1023,1023,1,-1);
   turningspeedL=constantS*errorL;
   
   errorR=SensorEReading-rightOffset;
   errorR=map(errorR,-1023,1023,1,-1);
   turningspeedR=constantS*errorR;
    
    
    analogWrite(pinLin1,value1+turningspeedL);
    digitalWrite(pinLin2,LOW);
     digitalWrite(pinRin1,LOW);
    analogWrite(pinRin2,value1+turningspeedR);
 

    
 
    Serial.print("\t advance\n\t");

  
  }
 
  
  else 
  {
 digitalWrite(pinLin1,LOW);
 digitalWrite(pinLin2,LOW);
 digitalWrite(pinRin1,LOW);
 digitalWrite(pinRin2,LOW);
   Serial.print("\t stop\n\t");   
   delay(10000);
  }


}
