//#define SensorA   A0//
//#define SensorB   A1//
#define SensorC   A2
#define SensorD   A3
#define SensorE   A4
int SensorAReading;
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
float value1;


// initial speeds of left and right motors
/*int left = startSpeed, right = startSpeed;*/


// Sensor calibration routine

void calibrate() {
for (int x=0; x<10; x++) { // run this 10 times to obtain average
  SensorCReading    = analogRead(2);/* three main sensors. Arrangment:      A B
                                                                           C D E*/
  SensorDReading     = analogRead(3);
  SensorEReading = analogRead(4);
leftOffset = leftOffset +  SensorCReading; // add value of left sensor to total
centreOffset = centreOffset +  SensorCReading; // add value of centre sensor to total
rightOffset = rightOffset +  SensorCReading; // add value of right sensor to total

delay(100);
}
// obtain average for each sensor
leftOffset = leftOffset / 10;
rightOffset = rightOffset / 10;
centreOffset = centreOffset /10;
Serial.print(leftOffset);
delay(1000);
Serial.print(rightOffset);
delay(1000);
Serial.print(centreOffset);
delay(1000);

} 

void setup ()
{
  pinMode(pinLin1,OUTPUT);
  pinMode(pinLin2,OUTPUT);
  pinMode(pinRin1,OUTPUT);
  pinMode(pinRin2,OUTPUT);
 // pinMode(SensorA, INPUT);//
  //pinMode(SensorB, INPUT);//
  pinMode(SensorC, INPUT);
  pinMode(SensorD, INPUT);
  pinMode(SensorE, INPUT);
  
  Serial.begin(9600);
  calibrate();
  delay(1000);
}


void advance ()
{
  value1=analogRead(A0);
  if(value1>=512)
  {
  analogWrite(pinLin1,255);  //the left/right motor goes under high speed
  analogWrite(pinRin2,255*(1023-value1)/value1);
  }
else{
  analogWrite(pinLin1,255*(1023-value1)/value1);
analogWrite(pinRin2,255);
}  

  digitalWrite(pinLin2,LOW);  
  digitalWrite(pinRin1,LOW);
}

void turnleft ()
{
value1 =analogRead(A0);
value1 /=5;

  digitalWrite(pinLin1,value1/2);
  digitalWrite(pinLin2,LOW);
  //the left motor goes under low speed
  
  analogWrite(pinRin2,value1);
  digitalWrite(pinRin1,LOW);
  //the right motor goes under high speed
}

void turnright()
{
  value1=analogRead(A0);
  value1 /=5;
  

  analogWrite(pinLin1,value1);
  digitalWrite(pinLin2,LOW);
  //the left motor goes under high speed
 
  digitalWrite(pinRin2,value1/2);
  digitalWrite(pinRin1,LOW);
  //the right motor goes under low speed
}




void final()
{
 digitalWrite(pinLin1,LOW);
 digitalWrite(pinLin2,LOW);
 digitalWrite(pinRin1,LOW);
 digitalWrite(pinRin2,LOW);
}


void loop()
{
  float high;
  float low;
  high=1600;// set the high threshold of sensor(we  have not checked yet)
  low=500;//set the low threshold of sensor
 
 //SensorAReading  = analogRead(0);//
 // SensorBReading    = analogRead(1);//
  SensorCReading     = analogRead(2);
  SensorDReading = analogRead(3);
  SensorEReading   = analogRead(4);
  
  Serial.print("\nC:\t");
  Serial.print(SensorCReading);
  //delay(1000);
  Serial.print("\tD:\t");
  Serial.print(SensorDReading);
  //delay(1000);
  Serial.print("\tE:\t");
  Serial.print(SensorEReading);
  //delay(1000);
  Serial.print("\tpotvaule:\t");
  value1=analogRead(A0);
  Serial.print(value1);
  
  if ( SensorCReading<low 
  &&  SensorDReading<low &&   SensorEReading>high)
  {
    turnleft();
    //delay(2000);// time need checked
    Serial.print("\tleft");
  }
  
 
  else if (  
  SensorCReading>high &&  SensorDReading<low &&   SensorEReading<low)
  {
    turnright();
    //delay(2000);//time need checked
    Serial.print("\tright");
  }
   
  
  else if ( 
  SensorCReading>high &&  SensorDReading<low &&   SensorEReading>high)
  {
    advance();
    //delay(1000);
    Serial.print("\tadvance ");
  }
 
  
  else 
  {
    final();
    //delay(100);
    Serial.print("\tstop");
  }
  
  
  delay(300);

}
