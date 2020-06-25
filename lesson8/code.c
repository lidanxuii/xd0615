/*
  Pitch follower

  Plays a pitch that changes based on a changing
  analog input

  circuit:
  * 8-ohm speaker on digital pin 9
  * photoresistor on analog 0 to 5V
  * 4.7K resistor on analog 0 to ground

  created 21 Jan 2010
  modified 31 May 2012  by Tom Igoe, with
  suggestion from Michael Flynn

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone2
*/

int sensorReading = 0;//定义变量

void setup()
{
  pinMode(A0, INPUT);//A0的模式设置为输入
  Serial.begin(9600);//打开串口，波特率9600

  pinMode(9, OUTPUT);//9的模式设置为输出
}

void loop()
{
  //A0的值随光敏电阻阻值（光照）变化而变化

  sensorReading = analogRead(A0);//把A0口读到的值赋给变量sensorReading

  Serial.println(sensorReading);//把sensorReading的值通过串口打印出来

  tone(9, 440 * pow(2.0, (constrain(int(map(sensorReading, 0, 1023, 36, 84)), 35, 127) - 57) / 12.0), 1000);
  
  //constrain(int(map(sensorReading, 0, 1023, 36, 84)), 35, 127)把sensorReading的值映射到36——84之间，取整形，再将值限定到35-127之间
  //将上值-57再除以12得到x，求2的x次方得到y,由9引脚产生频率为y的声音，持续1000ms，光照越强，光敏电阻阻值越小，引脚A0电压越高，声音频率越高
  delay(10); // Delay a little bit to improve simulation performance
}