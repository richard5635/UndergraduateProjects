/* simpleMotor using th L293
* —————- 
*/

//the H bridge takes two outputs from the Arduino to control the motor.
/*int motorPin0 = 3; 
int motorPin1 = 5; 
int motorPin2 = 9; 
int motorPin3 = 6; 
*/
/* SOUMYA 
int motorPin0 = 5; 
int motorPin1 = 6; 
int motorPin2 = 9; 
int motorPin3 = 10; 

*/ 
int motorPin0 = 5; 
int motorPin1 = 6; 
int motorPin2 = 9; 
int motorPin3 = 10; 



// there is one switch 
int switchPin = 7;
//declare the state variable
int state = 0;



int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int pwmValue = 0; 
int pwmtest=0;

void setup() {
//the motor control wires are outputs

pinMode(motorPin0, OUTPUT);
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
//the switch is an input
pinMode(switchPin, INPUT);
Serial.begin(9600); 
}

void loop() {
//read the switch
state = digitalRead(switchPin);
sensorValue = analogRead(sensorPin);  

//based on the state of the switch alternate the control pins to change he direction of the motor.
//switch (state){
//case 0:

if (sensorValue > 512) {
  pwmValue = map(sensorValue-512, 0, 511, 0, 255); 
  
  analogWrite(motorPin0, HIGH);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorPin3, HIGH);
  Serial.print("\none\n");
  delay(100);
}
else {
  pwmValue = map(sensorValue-512, 0, -512, 0, 255); 
 
  analogWrite(motorPin0, LOW);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  analogWrite(motorPin3, LOW);
  Serial.print("\ntwo\n");
  delay(100);
}


/*
  pwmValue = 100; 
  analogWrite(motorPin0, pwmValue);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorPin3, 150);
  delay(2000);

  analogWrite(motorPin0, LOW );
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  analogWrite(motorPin3, LOW);
  delay(2000);
  
  analogWrite(motorPin0, HIGH);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  analogWrite(motorPin3, LOW);
  delay(2000);

  analogWrite(motorPin0, LOW);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorPin3, HIGH);
  delay(2000);


  analogWrite(motorPin0, LOW);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorPin3, LOW);
 
Serial.println(pwmValue);
delay(10000);

*/


//break;
//case 1:
//digitalWrite(motorPin0, LOW);
//digitalWrite(motorPin1, HIGH);
//digitalWrite(motorPin2, HIGH);
//digitalWrite(motorPin3, LOW);
//break;
delay(100);
}

