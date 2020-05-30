
#include <Arduino.h>
#include "a_car.h"

int   g_count = 0;
int   g_array[3];
int   g_flag = 0;
float g_SF[3];

int value[3] = {0};
int choose;
int number;

void TSC_Init()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(VCC, OUTPUT);
  pinMode(GND, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(OUT, INPUT);

  pinMode(RGB, OUTPUT);
  pinMode(Black,OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(Speak, OUTPUT);

  digitalWrite(RGB, LOW);
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
  digitalWrite(Speak, HIGH);
  digitalWrite(Black,HIGH);

  digitalWrite(VCC, HIGH);
  digitalWrite(GND, LOW);
  digitalWrite(LED, LOW);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  
  g_SF[0] = Balance_R;
  g_SF[1] = Balance_G;
  g_SF[2] = Balance_B;
}

void TSC_FilterColor(int Level01, int Level02)
{
  if (Level01 != 0)              // 如果Level01不等于0
    Level01 = HIGH;              //则Level01为高电平
  if (Level02 != 0)              // 如果Level02不等于0
    Level02 = HIGH;              //则Level02为高电平
  digitalWrite(S2, Level01);     // 将Level01值送给S2
  digitalWrite(S3, Level02);     // 将Level02值送给S3
}

void TSC_Count()
{
  g_count ++ ;
}

void TSC_Callback()
{
  switch (g_flag)
  {
    case 0:
      Serial.println("->WB Start");// 串口打印字符串"->WB Start"
      TSC_WB(LOW, LOW);// 选择让红色光线通过滤波器的模式
      break;
    case 1:
      // Serial.print("->Frequency R=");  // 串口打印字符串"->Frequency R="
      //Serial.println(g_count);// 串口打印 0.5s 内的红光通过滤波器时，TCS3200 输出的脉冲个数
      g_array[0] = g_count;//储存 0.5s 内的红光通过滤波器时，TCS3200 输出的脉冲个数
      TSC_WB(HIGH, HIGH);// 选择让绿色光线通过滤波器的模式
      break;
    case 2:
      //Serial.print("->Frequency G=");  // 串口打印字符串"->Frequency G="
      // Serial.println(g_count);// 串口打印 0.5s 内的绿光通过滤波器时，TCS3200 输出的脉冲个数
      g_array[1] = g_count;//储存 0.5s 内的绿光通过滤波器时，TCS3200 输出的脉冲个数
      TSC_WB(LOW, HIGH);//选择让蓝色光线通过滤波器的模式
      break;
    case 3:
      //Serial.print("->Frequency B=");  // 串口打印字符串"->Frequency B="
      //Serial.println(g_count);// 串口打印 0.5s 内的蓝光通过滤波器时，TCS3200 输出的脉冲个数
      //Serial.println("->WB End");     // 串口打印字符串"->WB End"
      g_array[2] = g_count;//储存 0.5s 内的蓝光通过滤波器时，TCS3200 输出的脉冲个数
      TSC_WB(HIGH, LOW); // 选择无滤波器模式
      break;
    default:
      g_count = 0;//计数器清零
      break;
  }
}

void TSC_WB(int Level0, int Level1)
{
  g_count = 0;                    //计数值清零
  g_flag ++;                      //输出信号计数标志
  TSC_FilterColor(Level0, Level1);//滤波器模式
  Timer1.setPeriod(500000);       //设置输出信号脉冲计数时长为 0.5s
}

int color_value()
{
  //初始化
  
  Timer1.initialize(500000);
  Timer1.attachInterrupt(TSC_Callback);
  attachInterrupt(0, TSC_Count, RISING);//上升沿计数
  Timer1.detachInterrupt();
  
  //每获得一次被测物体RGB颜色值需时2s
  delay(2000);
  g_flag = 0;
  for (int i = 0; i < 3; i++)
  {
    value[i] = int(g_array[i] * g_SF[i]);
    Serial.println(int(g_array[i] * g_SF[i]));
  }
  if (value[0] + value[1] + value[2] > 1400)
  {
    //白色
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
    delay(100);
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    return 2;
  }
  else
  {
    choose = 0;
    for (int i = 0; i < 3; i++)
    {
      if (value[i] > choose)
      {
        choose = value[i];
        number = i;
      }
    }
    for (int i = 0; i < 3; i++)
    {
      if (i != number)
      {
        choose = choose - value[i];
      }
      else
      {
        choose = choose + value[i];
      }
    }
    if (choose < 30)
    {
      //黑色
      digitalWrite(Speak, LOW);
      delay(50);
      digitalWrite(Speak, HIGH);
      return 4;
    }
    else if (choose > 30)
    {
      if ((number == 0) && (value[0] + value[1] + value[2] - 3 * 255 > 90))
      {
        //红色
        digitalWrite(R, HIGH);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
        delay(100);
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
        return 3;
      }
      else if ((number == 1) && (value[0] + value[1] + value[2] - 3 * 255 > 50))
      {
        //绿色
        digitalWrite(R, LOW);
        digitalWrite(G, HIGH);
        digitalWrite(B, LOW);
        delay(100);
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
        return 1;
      }
      else if ((number == 2) && (value[0] + value[1] + value[2] - 3 * 255 > 60))
      {
        //蓝色
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, HIGH);
        delay(100);
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
        return 5;
      }
      else
      {
        //黑色
        digitalWrite(Speak, LOW);
        delay(50);
        digitalWrite(Speak, HIGH);
        return 4;
      }
    }
    else
    {
      //黑色
      digitalWrite(Speak, LOW);
      delay(50);
      digitalWrite(Speak, HIGH);
      return 4;
    }
  }
}
