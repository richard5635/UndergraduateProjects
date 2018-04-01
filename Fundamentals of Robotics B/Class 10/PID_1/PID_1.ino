/* define variables */
unsigned long lastTime;
double Input, Output,Setpoint;
double Iterm,lastInput;
double kp,ki,kd;
int SampleTime=1000; /* 1 second */
double outMin,outMax;
double error;
void compute()
{
  unsigned long now= millis();
  int timeChange=(now-lastTime);
  if(timeChange>=SampleTime)
  {
    error=Setpoint-Input;
    Iterm+=(ki*error);
    if(Item>outMax)
    Iterm=outMax;
    else if(Item<outMin)
    Iterm=outMin;/* compute all error varibles */
 
    double dInput=(Input-lastInput);
    
    Output=kp*error+Item-kd*dInput;
    if(Output>outMax)
    Output=outMax;
    else if(Output<outMin)
    Output=outMin; /* compute PID output */
   
   lastInput=Input;
   lastTime=now;  /* store some varibles for next round */
  }
}
 
 void Setoutlimits(double Min,double Max)
 { /* set the out alaways with some specific values */
   if(Min>Max)
   return;
   outMin=Min;
   outMax=Max;
   
   if(Output>outMax)
   Output=outMax;
   else if(Output<outMin)
   Output=outMin;
   
     if(Item>outMax)
   Iterm=outMax;
   else if(Item<outMin)
   Iterm=outMin;
 }
   
    

