#define SensorB   A1
#define SensorC   A2
#define SensorD   A3
#define SensorE   A4
#define Switch    A5

int N=100;
int SensorBReading;
int SensorCReading;
int SensorDReading;
int SensorEReading;
int SwitchReading = 0;

int pinLin1 = 6; //in1 for left motor driver
int pinLin2 = 9; //in2 for left motor driver
int pinRin1 = 10; //in1 for Right motor driver
int pinRin2 = 11; //in2 for Right motor driver

int leftOffset = 0, rightOffset = 0, centreOffset = 0;
int pot1=A0;


int pwmTest = 150; 


int turningspeedL,turningspeedR;
int constantS=5;//change it if speed is not enough
int errorL,errorR;

// Sensor calibration routine
void calibrate() {
  //average//
for (int x=0; x<N; x++)
{ 
    SensorCReading =  analogRead(2);
    SensorDReading =  analogRead(3);
    SensorEReading =  analogRead(4);
    
    leftOffset    +=  SensorCReading; // add value of left sensor to total
    centreOffset  +=  SensorDReading; // add value of centre sensor to total
    rightOffset   +=  SensorEReading; // add value of right sensor to total
  
  delay(100);
}

// obtain average for each sensor
leftOffset    = leftOffset / N;
rightOffset   = rightOffset / N;
centreOffset  = centreOffset /N;

if (leftOffset<0)
{
   leftOffset=-leftOffset;// some time it gives me minus something
}

Serial.print("lOff\t");
Serial.print(leftOffset );
Serial.print("\t rOff\t");
Serial.print(rightOffset);
Serial.print("\t cOff\t");
Serial.print(centreOffset);
Serial.println("\t -- ");

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
  pinMode(Switch, INPUT);
  
  Serial.begin(9600);
  calibrate();
  delay(100);
}

// The function to make the robot go forward

void goForward() 
{
    errorL=SensorCReading-leftOffset;
    Serial.print("\terrorL origin:");
    Serial.print(errorL);
    errorL=errorL/leftOffset;
    Serial.print("\terrorL:");
    Serial.print(errorL);
    turningspeedL=constantS*errorL;
    Serial.print("\tspeedL:");
    Serial.print(turningspeedL);
    
    errorR=SensorEReading-rightOffset;
    Serial.print("\terrorR origin:");
    Serial.print(errorR);
    errorR=errorR/rightOffset;
    Serial.print("\terrorR:");
    Serial.print(errorR);
    turningspeedR=constantS*errorR;
    Serial.print("\tspeedR:");
    Serial.print(turningspeedR);
    
    analogWrite(pinLin1,pwmTest-turningspeedL);//if error >0(detecting some black ) shift a little to left ,(motor speed goes a bit down);if error<0 ()shoft a little to right side.(motor speed goes up a bit;)
   digitalWrite(pinLin2,LOW);
   analogWrite(pinRin2,pwmTest-turningspeedR);//? direction unknown
   digitalWrite(pinRin1,LOW);//? direction unknown
  
    Serial.print("\t advance\n\t");
    
    // do it for 0.2s
    delay(200);
}

// The function to make the robot turn right
void goRight()
{
  // turn right 
   /* errorR=SensorEReading-rightOffset;
    Serial.print("\terrorR origin:");
    Serial.print(errorR);
    errorR=errorR/rightOffset;
    Serial.print("\terrorR:");
    Serial.print(errorR);
    turningspeedR=constantS*errorR;
    Serial.print("\tspeedR:");
    Serial.print(turningspeedR);*/
    
    
    digitalWrite(pinLin1,pwmTest);
    analogWrite(pinLin2,LOW);// right side motor goes backward
 
    analogWrite(pinRin1,pwmTest);//? direction is not determined
    //?direction is not determined
    digitalWrite(pinRin2,LOW);
 

  //the right motor goes under low speed

    Serial.print("\t right\n\t");
    delay(980);
}

// The function to make the robot turn left
void goLeft()
{
    /*errorL=SensorCReading-leftOffset;
    Serial.print("\terrorL origin:");
    Serial.print(errorL);
    errorL=errorL/leftOffset;
    Serial.print("\terrorL:");
    Serial.print(errorL);
    turningspeedL=constantS*errorL;
    Serial.print("\tspeedL:");
    Serial.print(turningspeedL);*/
    
    digitalWrite(pinLin1,LOW);
    analogWrite(pinLin2,pwmTest);// right side motor goes forward
    //? direction is not determined
    digitalWrite(pinRin1,LOW);//?direction is not determined  
    analogWrite(pinRin2,pwmTest);
  //the right motor goes under high speed
    Serial.print("\t left\n\t");
    delay(980);
}

// The function to make the robot stop
void Stop()
{
  // stop
    digitalWrite(pinLin1,HIGH);
    digitalWrite(pinLin2,HIGH);
    digitalWrite(pinRin1,HIGH);
    digitalWrite(pinRin2,HIGH);
    
    Serial.print("\t stop\n\t");   
    delay(1000);
}

// The function is to show the robot is beyond range
void Out()
{
    goForward();
    Serial.print("\t >>>>>>>>>>>>>>>>>> oh oh!\n\t");   
}


// The function to turn motor OFF
void SwitchOFF()
{
    digitalWrite(pinLin1,LOW);
    digitalWrite(pinLin2,LOW);
    digitalWrite(pinRin1,LOW);
    digitalWrite(pinRin2,LOW);
    
    Serial.print("Switched OFF\n");
    
}
/* ==================================================================================*/
/* This is the main command of the robot */
/* ==================================================================================*/

void loop()
{
  int high;
  int low;
  high=750;// set the high threshold of sensor
  low=500;//set the low threshold of sensor
 
  // intialize values
  SensorBReading =0;
  SensorCReading =0;
  SensorDReading =0;
  SensorEReading =0;
 
  //average//
  for (int x=0; x<5; x++)
  {   
    SensorBReading += analogRead(1);
    SensorCReading += analogRead(2);
    SensorDReading += analogRead(3);
    SensorEReading += analogRead(4);
  }

  SensorBReading =  SensorBReading/5;
  SensorCReading =  SensorCReading/5 ;
  SensorDReading =  SensorDReading/5;
  SensorEReading =  SensorEReading/5;
  
  SwitchReading  =  analogRead(5);
  
  Serial.print("\n\tB: ");
  Serial.print(SensorBReading);
  Serial.print("\tC: ");
  Serial.print(SensorCReading);
  Serial.print("\tD: ");
  Serial.print(SensorDReading);
  Serial.print("\tE: ");
  Serial.print(SensorEReading);
  
 /* value1=analogRead(A0);
  value1=map(value1,0,1023,0,255);
  value1 = pwmTest; */
 
  
    if 
    (   SensorCReading>high  &&  SensorDReading>high &&   SensorEReading<low)
    {
      goLeft();
      Stop();
    } 
  
    else if 
    (  SensorCReading<low &&  SensorDReading>high &&   SensorEReading>high)
    {
      goRight();
      Stop();
    }
  
    else  if 
    (SensorBReading<low &&   SensorCReading<low &&  SensorDReading>high &&   SensorEReading<low)
    { 
    analogWrite(pinLin1,110);// right side motor goes forward
    digitalWrite(pinLin2,LOW);
    //? direction is not determined
    digitalWrite(pinRin1,LOW);//?direction is not determined  
    analogWrite(pinRin2,100);
    delay(1000);
    Serial.println ("advance");
    
    } 
  
    else if
    (SensorBReading>high &&   SensorCReading>high &&  SensorDReading>high &&   SensorEReading>high)
    {
      Stop();
    }
    else 
    {
      Out();
    } 
 
}
