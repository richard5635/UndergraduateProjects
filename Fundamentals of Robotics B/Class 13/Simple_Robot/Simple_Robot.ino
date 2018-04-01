/* simpleMotor using th L293
* —————- 
*/

//the H bridge takes two outputs from the Arduino to control the motor.
int motorPin0 = 3; 
int motorPin1 = 5; 
// there is one switch 
int switchPin = 4;
//declare the state variable
int state = 0;

void setup() {
//the motor control wires are outputs
pinMode(motorPin0, OUTPUT);
pinMode(motorPin1, OUTPUT);
//the switch is an input
pinMode(switchPin, INPUT);
}

void loop() {
//read the switch
state = digitalRead(switchPin);
//based on the state of the switch alternate the control pins to change he direction of the motor.
switch (state){
case 0:
digitalWrite(motorPin0, HIGH);
digitalWrite(motorPin1, LOW);
break;
case 1:
digitalWrite(motorPin0, LOW);
digitalWrite(motorPin1, HIGH);
break;
}
}
