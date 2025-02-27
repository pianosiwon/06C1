#define PIN_LED 7

void setup() {
  pinMode(PIN_LED, OUTPUT);
}
int set_period(int period){
    return period;
}
void set_duty(int duty, int k){
    digitalWrite(PIN_LED, HIGH);
    delayMicroseconds(k/100*duty);
    digitalWrite(PIN_LED, LOW);
    delayMicroseconds(k/100*(100-duty));
  }
  
void loop() {
  int i;
  int j;
  int t = set_period(100);
  if (t==10000){
     unsigned long time1 = millis();
    for(i=0;i<=100;i++)set_duty(i,t);
    
    for(i=100;i>=1;i--) set_duty(i,t);
    unsigned long time2 = millis();
  }
  else if(t==1000){
    unsigned long time1 = millis();
     for(i=0;i<=100;i++)
      for(j=1;j<=5;j++) set_duty(i,t);
    for(i=100;i>=1;i--)
      for(j=1;j<=5;j++) set_duty(i,t);
    unsigned long time2 = millis();
              
  }
    else if(t==100){
    unsigned long time1 = millis();
     for(i=0;i<=100;i++)
      for(j=1;j<=50;j++)set_duty(i,t);
    for(i=100;i>=1;i--)
      for(j=1;j<=50;j++) set_duty(i,t);
    unsigned long time2 = millis();
              
  }
}
