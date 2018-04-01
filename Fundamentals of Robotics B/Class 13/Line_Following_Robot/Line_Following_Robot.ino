#define SensorA   1
#define SensorB   2
#define SensorC   3
#define SensorD   4
#define SensorE   5
#define SensorF   0
#define SensorG   7

int SensorAReading;
int SensorBReading;
int SensorCReading;
int SensorDReading;
int SensorEReading;
int SensorFReading;
int SensorGReading;

#define leftMotor1  8
#define rightMotor1 10



void setup()
{
  
  pinMode(SensorA, INPUT);
  pinMode(SensorB, INPUT);
  pinMode(SensorC, INPUT);
  pinMode(SensorD, INPUT);
  pinMode(SensorE, INPUT);
  pinMode(SensorF, INPUT);
  pinMode(SensorF, INPUT);
    
  pinMode(leftMotor1, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  
  //pinMode(led, OUTPUT);
  Serial.begin(115200);
  //digitalWrite(led, HIGH);
  delay(1000);
}

void loop()
{
  readSensors(); 
  camparision();
 
    //Moves straight for 2.5 seconds
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(rightMotor1, HIGH);
    
    delay(2500);
    
    
    //STOPS for 1 second
    digitalWrite(leftMotor1, LOW);
    digitalWrite(rightMotor1, LOW);
    delay(10000);
    
    
    //Turns right(1.075 seconds)
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(rightMotor1, LOW)
    delay(1075);
    

    
    //Turns left(1.075 seconds)
    digitalWrite(leftMotor1, LOW);
    digitalWrite(rightMotor1, HIGH);
    delay(1075);
    

    //Turns around 180 degrees
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(900);
    
}

void readSensors()
{
  
 SensorAReading  = analogRead(1);
  SensorBReading    = analogRead(2);
  SensorCReading     = analogRead(3);
  SensorDReading = analogRead(4);
  SensorEReading   = analogRead(5);
  SensorFReading    = analogRead(0);  
  SensorGReading  = analogRead(7); 
}


void comparison()
{
                                                                                     
 
 if(SensorAReading>200){ 
    digitalWrite(1, 1);                                                                         
  }
  else{                                                                                              
    digitalWrite(1, 0);                                                       
  }
 if(SensorBReading>200){ 
    digitalWrite(2, 1);                                                                         
  }
  else{                                                                                              
    digitalWrite(2, 0);                                                       
  }
   if(SensorCReading>200){ 
    digitalWrite(3, 1);                                                                         
  }
  else{                                                                                              
    digitalWrite(3, 0);                                                       
  }
   if(SensorDReading>200){ 
    digitalWrite(4, 1);                                                                         
  }
  else{                                                                                              
    digitalWrite(4, 0);                                                       
  }
   if(SensorEReading>200){ 
    digitalWrite(5, 1);                                                                         
  }
  else{                                                                                              
    digitalWrite(5, 0);                                                       
  }
   if(SensorFReading>200){ 
    digitalWrite(0, 1);                                                                         
  }
  else{                                                                                              
    digitalWrite(0, 0);                                                       
  }
    if(SensorGReading>200){ 
    digitalWrite(7, 1);                                                                         
  }
  else{                                                                                              
    digitalWrite(7, 0);                                                       
  }
}



