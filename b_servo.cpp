//舵机执行完动作后回掉电
//且自带延时
#include <Arduino.h>
#include <Servo.h>
#include "a_car.h"

Servo servo_hand;
Servo servo_L_xoy;
Servo servo_L_z;
Servo servo_R_z;
Servo servo_R_xoy;
Servo servo_up_down;

void Servo_Init()
{
  pinMode(L_xoy, OUTPUT);
  pinMode(L_z, OUTPUT);
  pinMode(R_xoy, OUTPUT);
  pinMode(R_z, OUTPUT);
  pinMode(hand, OUTPUT);
  pinMode(up_down, OUTPUT);
}

void Servo_Locate_Init()
{
  servo_hand.attach(hand);
  servo_hand.write(175);
  delay(200);
  servo_hand.detach();

  servo_L_z.attach(L_z);
  servo_L_z.write(70);
  delay(200);
  servo_L_z.detach();

  servo_R_z.attach(R_z);
  servo_R_z.write(140);
  delay(200);
  servo_R_z.detach();

  servo_L_xoy.attach(L_xoy);
  servo_L_xoy.write(175);
  delay(200);
  servo_L_xoy.detach();

  servo_R_xoy.attach(R_xoy);
  servo_R_xoy.write(5);
  delay(200);
  servo_R_xoy.detach();

  servo_up_down.attach(up_down);
  servo_up_down.write(34);
  delay(200);
  servo_up_down.detach();
  //L，上为0，下为180，左平90
  //R，上为180，下为0，右平120
  //大舵机最下为34，最上为180
  //手初始闭合为175
  //左钩子175，右钩子初始5
}

void open_hand()          //张开圆柱形舵机,165--65
{
  servo_hand.attach(hand);
  for (int i = 0; i <= 100; i++)
  {
    servo_hand.write(165 - i);
    delay(3);
  }
  servo_hand.detach();
  delay(100);
}

void pick_object()        //合上圆柱形舵机,65--165
{
  servo_hand.attach(hand);
  for (int i = 0; i <= 100 ; i++)
  {
    servo_hand.write(65 + i);
    delay(3);
  }
  servo_hand.detach();
  delay(100);
}

void loose_object()       //钩子轻拨物块
{
  servo_R_xoy.attach(R_xoy);
  for (int i = 0; i <= 75; i++)
  {
    servo_R_xoy.write(5 + i);
    delay(5);
  }
  servo_R_z.attach(R_z);
  for (int i = 0; i < 40; i++)
  {
    servo_R_z.write(120 - i);
    delay(10);
  }
  for (int i = 0; i < 40; i++)
  {
    servo_R_z.write(80 + i);
    delay(10);
  }
  for (int i = 0; i <= 75; i++)
  {
    servo_R_xoy.write(80 - i);
    delay(5);
  }
  servo_R_xoy.detach();
  servo_R_xoy.detach();
  delay(100);
}

void catch_object()      //钩子挡住物块
{
  servo_L_xoy.attach(L_xoy);
  servo_R_xoy.attach(R_xoy);
  for (int i = 0; i < 40; i++)
  {
    servo_L_xoy.write(175 - i);
    delay(3);
    servo_R_xoy.write(10 + i);
    delay(3);
  }
  servo_L_z.attach(L_z);
  servo_R_z.attach(R_z);
  for (int i = 0; i < 40; i++)
  {
    servo_R_z.write(120 - i);
    delay(3);
    servo_L_z.write(90 + i);
    delay(3);
  }
  for (int i = 0; i < 30; i++)
  {
    servo_L_xoy.write(130 - i);
    delay(3);
    servo_R_xoy.write(50 + i);
    delay(3);
  }
  servo_L_xoy.detach();
  servo_R_xoy.detach();
  servo_L_z.detach();
  servo_R_z.detach();
  delay(100);
}

void put_object()        //钩子放开物块
{
  servo_L_xoy.attach(L_xoy);
  servo_R_xoy.attach(R_xoy);
  for (int i = 0; i < 30; i++)
  {
    servo_L_xoy.write(100 + i);
    delay(3);
    servo_R_xoy.write(80 - i);
    delay(3);
  }
  for (int i = 0; i < 40; i++)
  {
    servo_R_z.write(80 + i);
    delay(3);
    servo_L_z.write(130 - i);
    delay(3);
  }
  servo_L_z.attach(L_z);
  servo_R_z.attach(R_z);
  for (int i = 0; i < 40; i++)
  {
    servo_L_xoy.write(135 + i);
    delay(3);
    servo_R_xoy.write(45 - i);
    delay(3);
  }
  servo_L_xoy.detach();
  servo_R_xoy.detach();
  servo_L_z.detach();
  servo_R_z.detach();
}

void correct_object()
{
  servo_hand.attach(hand);
  for (int i = 0; i < 10; i++)
  {
    servo_hand.write(140 + i);
    delay(14);
  }
  for (int i = 0; i < 90; i++)
  {
    servo_hand.write(150 - i);
    delay(5);
  }
  servo_hand.detach();
  delay(100);
}

void rise_object()         //大舵机升起34-174
{
  servo_hand.attach(hand);
  servo_hand.write(165);
  delay(150);
  servo_up_down.attach(up_down);
  for (int i = 0; i <= 140; i++)
  {
    servo_up_down.write(34 + i);
    delay(4);
  }
  servo_up_down.detach();
  delay(50);
}

void down_object()//大舵机下降174--34
{
  servo_up_down.attach(up_down);
  for (int i = 0; i <= 140; i++)
  {
    servo_up_down.write(174 - i);
    delay(4);
  }
  servo_up_down.detach();
  delay(50);
}

void assignment_dui_one()
{
  servo_up_down.attach(up_down);
  for (int i = 0; i <= 70; i++)
  {
    servo_up_down.write(174 - i);
    delay(4);
  }
  servo_hand.attach(hand);
  for (int i = 0; i <= 25; i++)
  {
    servo_hand.write(165 - i);
    delay(3);
  }
  for (int i = 0; i <= 70; i++)
  {
    servo_up_down.write(104 - i);
    delay(4);
  }
  for (int i = 0; i <= 25; i++)
  {
    servo_hand.write(140 + i);
    delay(3);
  }
  rise_object();
  servo_up_down.detach();
  delay(200);
}

void assignment_dui_two()
{
  servo_up_down.attach(up_down);
  for (int i = 0; i <= 70; i++)
  {
    servo_up_down.write(174 - i);
    delay(4);
  }
  servo_hand.attach(hand);
  for (int i = 0; i <= 25; i++)
  {
    servo_hand.write(165 - i);
    delay(3);
  }
  for (int i = 0; i <= 70; i++)
  {
    servo_up_down.write(104 - i);
    delay(4);
  }
  for (int i = 0; i <= 75; i++)
  {
    servo_hand.write(140 - i);
    delay(4);
  }
  servo_hand.detach();
  servo_up_down.detach();
  delay(100);
}

void catch_ABEC()
{
  servo_R_xoy.attach(R_xoy);
  servo_L_xoy.attach(L_xoy);
  for (int i = 0; i < 35; i++)
  {
    servo_R_xoy.write(i + 5);
    servo_L_xoy.write(180 - i);
    delay(7);
  }
  servo_R_z.attach(R_z);
  servo_L_z.attach(L_z);
  for (int i = 0; i < 50; i++)
  {
    servo_R_z.write(140 - i);
    servo_L_z.write(70 + i);
    delay(10);
  }
  for (int i = 0; i < 40; i++)
  {
    servo_R_z.write(90 - i);
    servo_L_z.write(120 + i);
    delay(10);
  }
  for (int i = 0; i < 20; i++)
  {
    servo_R_xoy.write(50 + i);
    servo_L_xoy.write(135 - i);
    delay(10);
  }
  servo_R_xoy.detach();
  servo_L_xoy.detach();
  servo_R_z.detach();
  servo_L_z.detach();
}

void R_loose()
{
  servo_R_xoy.attach(R_xoy);
  for (int i = 0; i < 20; i++)
  {
    servo_R_xoy.write(70 - i);
    delay(5);
  }
  servo_R_z.attach(R_z);
  for (int i = 0; i < 40; i++)
  {
    servo_R_z.write(50 + i);
    delay(9);
  }
  for (int i = 0; i < 50; i++)
  {
    servo_R_z.write(90 + i);
    delay(8);
  }
  for (int i = 0; i < 35; i++)
  {
    servo_R_xoy.write(40 - i);
    delay(5);
  }
  servo_R_xoy.detach();
  servo_R_z.detach();
}

void L_loose()
{
  servo_L_xoy.attach(L_xoy);
  for (int i = 0; i < 20; i++)
  {
    servo_L_xoy.write(115 + i);
    delay(5);
  }
  servo_L_z.attach(L_z);
  for (int i = 0; i < 40; i++)
  {
    servo_L_z.write(160 - i);
    delay(9);
  }
  for (int i = 0; i < 50; i++)
  {
    servo_L_z.write(120 - i);
    delay(8);
  }
  for (int i = 0; i < 35; i++)
  {
    servo_L_xoy.write(145 + i);
    delay(5);
  }
  servo_L_xoy.detach();
  servo_L_z.detach();
}

