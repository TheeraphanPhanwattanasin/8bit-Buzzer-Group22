#define Buzz 19
#define Button_Pin 18
hw_timer_t *My_timer = NULL;
bool check = true;
int lv = 1;
double acc = 1;
// This is the Timer ISR. It is automatically called
// on a timer alarm event.
void IRAM_ATTR onTimer(){
  if(check) digitalWrite(Buzz, !digitalRead(Buzz));
  else digitalWrite(Buzz, LOW);
}

void IRAM_ATTR IO_INT_ISR(){
lv++;
}


void setup() {
  pinMode(Buzz, OUTPUT);
  pinMode(Button_Pin, INPUT);
 My_timer = timerBegin(0, 80, true);  // use tiemr 0 and set prescale to 80 so 1 tick is 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true); // point to the ISR  // set alarm every 1 sec
  timerAlarmWrite(My_timer, 1000000, true);
  timerAlarmEnable(My_timer);  // enable the alarm
  pinMode(Button_Pin, INPUT);
  attachInterrupt(Button_Pin, IO_INT_ISR, FALLING);
}

void loop() {
  if(lv%5 == 1) acc = 1;
  else if(lv%5 == 2) acc = 2;
  else if(lv%5 == 3) acc = 2.5;
  else if(lv%5 == 4) acc = 0.125;
  else if(lv%5 == 0) acc = 0.5;
check = true;
timerAlarmWrite(My_timer, 1000000/(880*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(784*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(880*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(932.3*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(1047*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(932.3*2), true);
delay(500*acc);
timerAlarmWrite(My_timer, 1000000/(880*2), true);
delay(500*acc);
timerAlarmWrite(My_timer, 1000000/(784*2), true);
delay(500*acc);
timerAlarmWrite(My_timer, 1000000/(698.5*2), true);
delay(1000*acc);
check = false;
delay(500*acc);
check = true;
timerAlarmWrite(My_timer, 1000000/(784*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(698.5*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(784*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(880*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(698.5*2), true);
delay(250*acc);
timerAlarmWrite(My_timer, 1000000/(587.3*2), true);
delay(500*acc);
timerAlarmWrite(My_timer, 1000000/(698.5*2), true);
delay(500*acc);
timerAlarmWrite(My_timer, 1000000/(880*2), true);
delay(1000*acc);
check = false;
delay(1500);
}