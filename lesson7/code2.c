#include <MsTimer2.h>     //定时器库的头文件
 #define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define S1 7
#define LT 8
#define BT 9
int pinInterrupt = 2; //接中断信号的脚

volatile int tick = 0; //计数值

void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode( pinInterrupt, INPUT);//设置管脚为输入
  pinMode(S1, OUTPUT);
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);//按下按键触发中断
}
 
//定时器中断服务程序
void onTimer()
{
   if(tick==10)
{
   tick=0;
}
    tick=tick-'0';
    digitalWrite(IN1,tick&0x1);
    digitalWrite(IN2,(tick>>1)&0x1);
    digitalWrite(IN3,(tick>>2)&0x1);
    digitalWrite(IN4,(tick>>3)&0x1);
   tick++;
}

//外部中断服务程序
void onChange()
{
   if ( digitalRead(pinInterrupt) == LOW )
      tick=0;
}
 
void loop()
{
    for (int i = 0; i < 100; i++)
  {
    // 什么都不做，等待10毫秒
    delay(10); 
  }
}