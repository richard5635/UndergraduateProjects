
#define SensorA A5;
#define SensorB A4;
#define SensorC A3;
#define SensorD A2;
#define SensorE A1;
#define POT     A0;

int SensorAReading;
int SensorBReading;
int SensorCReading;
int SensorDReading;
int SensorEReading;

int pinLin1 = 6; //in1 for left motor driver
int pinLin2 = 9; //in2 for left motor driver
int pinRin1 = 10; //in1 for Right motor driver
int pinRin2 = 11; //in2 for Right motor driver

int leftOffset = 250, rightOffset = 300;
int potValue;
int pwmValue;
int pwmValuel, pwmValuer;
double turningspeedL,turningspeedR;
int constantS=10;//change it if speed is not enough
double errorL,errorR;



void setup ()
{
 /* pinMode(pinLin1,OUTPUT);
  pinMode(pinLin2,OUTPUT);
  pinMode(pinRin1,OUTPUT);
  pinMode(pinRin2,OUTPUT);*/
  
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);
  pinMode(A0,INPUT);
  
  
  Serial.begin(9600);

  delay(100);
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
  
  potValue = analogRead(A0);  

if (potValue > 512) {
  pwmValue = map(potValue-512, 0, 511, 0, 255);
}
else {
  pwmValue = map(potValue-512, 0, -512, 0, 255); 
}
  delay(1);
  Serial.print("POTvalue is\t");
  Serial.println(pwmValue);
  
  pwmValuer=map(pwmValue,0,255,100,255);  
  pwmValuel=map(pwmValue+75,0,255,100,255); 
  delay(1);
  Serial.print("pwmValue r is\t");
  Serial.println(pwmValuer);
  Serial.print("pwmValue l is\t");
  Serial.println(pwmValuel);
  
  
  SensorAReading =0;
  SensorBReading =0;
  SensorCReading =0;
  SensorDReading =0;
  SensorEReading =0;

 
  //average//
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
  SensorCReading =  SensorCReading/5 ;
  SensorDReading =  SensorDReading/5;
  SensorEReading =  SensorEReading/5;
  
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

    if 
    (  SensorAReading<low &&  SensorBReading<low && SensorCReading>high  &&  SensorDReading>high &&   SensorEReading<low)
    {
      // left turn 
   /* digitalWrite(pinLin1,LOW);
    analogWrite(pinLin2, 120);
    digitalWrite(pinRin1,LOW);
    analogWrite(pinRin2, 100);
    delay(300);*/
      goLeft();
     
    } 
  
    else if 
    (  SensorAReading<low &&  SensorBReading<low && SensorCReading<low &&  SensorDReading>high &&   SensorEReading>high)
    {
      // right turn
    /*digitalWrite(pinLin1,LOW);
    analogWrite(pinLin2, 120);
    digitalWrite(pinRin1,LOW);
    analogWrite(pinRin2, 100);
    delay(300);*/
      goRight();
 
    }
  else if 
    (  SensorAReading<low &&  SensorBReading<low && SensorCReading>high &&  SensorDReading>high &&   SensorEReading>high)
    {
      // "T" cross(turn left according to left rule)

      goLeft();
      
    }
    
     else if 
    (  SensorAReading>high &&  SensorBReading<low && SensorCReading<low &&  SensorDReading>high &&   SensorEReading<low)
    {
      // straight line 

      advance();
   
    }
    
     else if 
    (  SensorAReading>high &&  SensorBReading<low && SensorCReading>high &&  SensorDReading>high &&   SensorEReading<low)
    {

     // left>straight ,then turn left
      goLeft();
     
    }
      else if 
    (  SensorAReading>high &&  SensorBReading<low && SensorCReading<low &&  SensorDReading>high &&   SensorEReading>high)
    {
      //straight>right, then advance

      advance();
   
     
    }  
    
    else  if 
    (SensorAReading>high && SensorBReading<low &&   SensorCReading>high &&  SensorDReading>high &&   SensorEReading>high)
    { 
      // "+" cross 
      //left>straight>right. then turn left
       goLeft();
    } 
  
    else if
    (SensorAReading>high  &&  SensorBReading>high  &&   SensorCReading>high &&  SensorDReading>high &&   SensorEReading>high)
    {
      Stop();

    }
    
    else 
    {
      
     if(SensorAReading<low &&  SensorBReading<low  &&   SensorCReading<low &&  SensorDReading<low &&   SensorEReading<low)
     {
    Serial.print("\t dead end turn around"); 
    digitalWrite(pinLin1,LOW);
    analogWrite(pinLin2, pwmValue);
    analogWrite(pinRin1, pwmValue-25);
    digitalWrite(pinRin2,LOW);
    delay(30000);
    
     }
      else 
    {
        Out();
     }
    
  } 
 
}

// The function to make the robot turn right
void goRight()
{
    digitalWrite(pinLin1,150);
    analogWrite(pinLin2,LOW);
    digitalWrite(pinRin1,LOW);
    analogWrite(pinRin2,155);
    
 

  //the right motor goes under low speed

    Serial.print("\t right\n\t");
    delay(900);
}

// The function to make the robot turn left
void goLeft()
{   
    digitalWrite(pinLin1,LOW);
    analogWrite(pinLin2,150);
    analogWrite(pinRin1,155);
    digitalWrite(pinRin2,LOW);
   
  //the right motor goes under high speed
    Serial.print("\t left\n\t");
    delay (900);
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
// The function to make the robot go forward
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
    
    Serial.print("\t >>>>>>>>>>>>>>>>>> oh oh!\n\t");   
    
    analogWrite(pinLin1,pwmValuel-turningspeedL);//left wheel stops
    digitalWrite(pinLin2,LOW);
    analogWrite(pinRin1,pwmValuer-turningspeedR);
    digitalWrite(pinRin2,LOW);
    
    /*if (SensorCReading > 500) //shift right 
    {
    Serial.print("\t >>>>>>>>>>>>>>>>>> shift right\n\t"); 
    analogWrite(pinLin1,LOW);//left wheel stops
    digitalWrite(pinLin2,LOW);
    analogWrite(pinRin1,100);
    digitalWrite(pinRin2,LOW);
    
    }
    
    else if (SensorEReading > 500)// shift left
    {
    Serial.print("\t >>>>>>>>>>>>>>>>>> shift left\n\t"); 
    analogWrite(pinLin1,100);// right wheel stops
    digitalWrite(pinLin2,LOW);
    digitalWrite(pinRin1,LOW);
    analogWrite(pinRin2,LOW);
    }
  else
   {
    Serial.print("\t >>>>>>>>>>>>>>>>>> spin\n\t"); 
    analogWrite(pinLin1,120);
    digitalWrite(pinLin2,LOW);
    digitalWrite(pinRin1,LOW);
    analogWrite(pinRin1,120);//spin
   }*/
}
 
 void advance()
{
    
    analogWrite(pinLin1, pwmValuel);
    digitalWrite(pinLin2,LOW);
    analogWrite(pinRin1, pwmValuer);
    digitalWrite(pinRin2,LOW);
    Serial.println ("advance");  
} 
