
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

//Left is C, Right is E

int leftOffset = 300, rightOffset = 300;
int potValue;
int pwmValue;
int pwmValuel, pwmValuer;
double turningspeedL,turningspeedR;
int Kp=20;//change it if speed is not enough
double errorL,errorR;
int x=1;
unsigned long time;
int Error;
//==============new===============
int Kd=40;
//================================


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
  time = millis();
  
  Serial.begin(9600);

  delay(100);
}

/* ==================================================================================*/
/* This is the main command of the robot */
/* ==================================================================================*/



void loop()
{
  int high;
  int mid;
  int low;
  high=800;// set the high threshold of sensor
  mid=700;
  low=400;//set the low threshold of sensor
  
  potValue = analogRead(A0);  
  
  //Makes the speed changeable with the POT, gonna disable this to get a constant value
  /*
  pwmValue = map(potValue, 0, 1023, 0, 255);
  */
  //Half powered battery = 110, full = 90
  pwmValue = 110;
  pwmValuel= pwmValue;
  pwmValuer= pwmValue;
  
  delay(1);
  Serial.print("POTvalue is\t");
  Serial.println(pwmValue);
  
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
  SensorCReading =  map((SensorCReading/5), 300, 1023, 0, 1023);
  SensorDReading =  map((SensorDReading/5), 400, 1023, 0, 1023);
  SensorEReading =  map((SensorEReading/5), 0, 1023, 0, 1023);
  SensorCReading = constrain(SensorCReading, 0, 1023);
  SensorDReading = constrain(SensorDReading, 0, 1023);
  SensorEReading = constrain(SensorEReading, 0, 1023);
  
  
  //constrain
  //combine PID
  //set jumpstart
  //Tune Kp and Kd
  
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
      
   /* digitalWrite(pinLin1,LOW);
    analogWrite(pinLin2, 120);
    digitalWrite(pinRin1,LOW);
    analogWrite(pinRin2, 100);
    delay(300);*/
    Pause();
    goLeft();
    Pause();
    JumpStart();
    x=1;
  
    } 
  
    else if 
    (  SensorAReading<low &&  SensorBReading<low && SensorCReading<low &&  SensorDReading>high &&   SensorEReading>high)
    {
      
   
    /*digitalWrite(pinLin1,LOW);
    analogWrite(pinLin2, 120);
    digitalWrite(pinRin1,LOW);
    analogWrite(pinRin2, 100);
    delay(300);*/
    Pause();
    goRight();
    Pause();
    JumpStart();
    x=1;
    }
  
    else  if 
    (SensorAReading>high && SensorBReading<low &&   SensorCReading<low+100 &&  SensorDReading>high &&   SensorEReading<low)
    { 
  
      
   if (x==1)
   {
     JumpStart();
   }
   
   Advance();
   x=0;
    
    } 
  
    else if
    (SensorAReading>high  &&  SensorBReading>high  &&   SensorCReading>high &&  SensorDReading>high &&   SensorEReading>high)
    {
      Stop();

    }
    else if
    (SensorCReading>high && SensorAReading>high && SensorDReading<mid && SensorEReading<low)
    {
      SlightRight();
    }
    else if
    (SensorCReading<low && SensorAReading>high && SensorDReading<mid && SensorEReading>high)
    {
      SlightLeft();
    }
    else if
   ((SensorCReading>high && SensorDReading<low && SensorEReading<low)||(SensorCReading<low && SensorDReading<low && SensorEReading>high))
    {
      SlightOut();
    } 
    else
   /*((SensorCReading>mid && SensorDReading<low && SensorEReading<low)||(SensorCReading<low && SensorDReading<low && SensorEReading>mid))*/
    {
      SlightOut();
    } 
}
/*=============================================*/
/*These are the functions                      */
/*=============================================*/

void Advance()
{
   //Half Powered = 1 and 0.695
   analogWrite(pinLin1, pwmValuel*1);
   digitalWrite(pinLin2,LOW);
   analogWrite(pinRin1, pwmValuer*0.73);
   digitalWrite(pinRin2,LOW);
   
   Serial.println ("advance");
   Serial.print("\tL speed\t");
   Serial.print(pwmValuel*1);
   Serial.print("\tR speed\t");
   Serial.print(pwmValuer*0.65);
   delay(20);
}

void Pause()
{
   analogWrite(pinLin1, LOW);
   digitalWrite(pinLin2,LOW);
   analogWrite(pinRin1, LOW);
   digitalWrite(pinRin2,LOW);
   delay(500);
}

// The function to make the robot turn right
void JumpStart()
{
   analogWrite(pinLin1, 255);
   digitalWrite(pinLin2,LOW);
   analogWrite(pinRin1, 255);
   digitalWrite(pinRin2,LOW);
   delay(25);
}

void SlightLeft()
{
    digitalWrite(pinLin1,LOW);
    analogWrite(pinLin2,LOW);
    digitalWrite(pinRin1,35);
    analogWrite(pinRin2,LOW);

    Serial.print("\t slight left\n\t");
    delay(100);
}

void SlightRight()
{
    digitalWrite(pinLin1,35);
    analogWrite(pinLin2,LOW);
    digitalWrite(pinRin1,LOW);
    analogWrite(pinRin2,LOW);
    
    Serial.print("\t slight right\n\t");
    delay(100);
}

void goRight()
{
    digitalWrite(pinLin1,60);
    analogWrite(pinLin2,LOW);
    digitalWrite(pinRin1,LOW);
    analogWrite(pinRin2,205);
    
 

  //the right motor goes under low speed

    Serial.print("\t right\n\t");
    delay(500);
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
    delay (850);
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
    delay(100);
}



// The function is to show the robot is beyond range
void SlightOut()
{
// The function to make the robot go forward
    /*
    errorL=SensorCReading-leftOffset;
    Serial.print("\terrorL origin:");
    Serial.print(errorL);
    errorL=errorL/leftOffset;
    Serial.print("\terrorL:");
    Serial.print(errorL);
    turningspeedL=Kp*errorL;
    Serial.print("\tspeedL:");
    Serial.print(turningspeedL);
    
    errorR=SensorEReading-rightOffset;
    Serial.print("\terrorR origin:");
    Serial.print(errorR);
    errorR=errorR/rightOffset;
    Serial.print("\terrorR:");
    Serial.print(errorR);
    turningspeedR=Kp*errorR;
    Serial.print("\tspeedR:");
    Serial.print(turningspeedR);
    */
    //Derivative Error Correction
    
    int DerivativeL;
    int DerivativeR;
    
    Serial.print("\t >>>>>>>>>>>>>>>>>> oh oh!\n\t");   
    
    int t = 1;
    DerivativeL= Kd*(Error/t);
    DerivativeR= Kd*(Error/t);
    
    /*
    int PIDL = (pwmValuel-pow((turningspeedL/11),2)+(turningspeedR*2)-pow((DerivativeR/15),2))*0.8;
    int PIDR = (pwmValuer-pow((turningspeedR/11),2)+(turningspeedL/6)-pow((DerivativeL/19),2))*0.8;
    */
    
    Error=SensorCReading-SensorEReading;
    Error=map(Error, -1023, 1023, -255, 255);
    Error=constrain(Error, -80, 80);
    
    
    int PIDL = (pwmValuel-(0.5*Error)+20)*0.8;
    int PIDR = (pwmValuer+(0.5*Error))*0.8;
    
    analogWrite(pinLin1,PIDL);//left wheel stops
    digitalWrite(pinLin2,LOW);
    analogWrite(pinRin1,PIDR);
    digitalWrite(pinRin2,LOW);
    
    Serial.print("Left Value : ");
    Serial.print(PIDL);
    Serial.print("\tRight Value : ");
    Serial.print(PIDR);
    Serial.print("\n");
    
    delay(10);
    t+=2;
    x=0;
   
    
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

void Out()
{
// The function to make the robot go forward
    /*errorL=SensorCReading-leftOffset;
    Serial.print("\terrorL origin:");
    Serial.print(errorL);
    errorL=errorL/leftOffset;
    Serial.print("\terrorL:");
    Serial.print(errorL);
    turningspeedL=Kp*errorL;
    Serial.print("\tspeedL:");
    Serial.print(turningspeedL);
    
    errorR=SensorEReading-rightOffset;
    Serial.print("\terrorR origin:");
    Serial.print(errorR);
    errorR=errorR/rightOffset;
    Serial.print("\terrorR:");
    Serial.print(errorR);
    turningspeedR=Kp*errorR;
    Serial.print("\tspeedR:");
    Serial.print(turningspeedR);
    */
    
    
    
    
    //Derivative Error Correction
    
    int DerivativeL;
    int DerivativeR;
    
    Serial.print("\t >>>>>>>>>>>>>>>>>> oh oh!\n\t");   
    
    int t = 1;
    DerivativeL= Kd*(errorL/t);
    DerivativeR= Kd*(errorR/t);
    
    analogWrite(pinLin1,pwmValuel-(turningspeedL/2)+(turningspeedR*2));//left wheel stops
    digitalWrite(pinLin2,LOW);
    analogWrite(pinRin1,pwmValuer-(turningspeedR*2.5));
    digitalWrite(pinRin2,LOW);
    delay(10);
    t+=1;
    x=0;
}
