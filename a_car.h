#ifndef _MY_CAR_H
#define _MY_CAR_H

#include <TimerOne.h>
#include <Servo.h>

#define Balance_R 0.79193
#define Balance_G 1.05809
#define Balance_B 0.90747

#define leftz 60
#define rightz 64
#define leftk  26
#define rightk 26
#define leftm -24
#define rightm -24

#define leftzh -65
#define rightzh -60
#define leftkh -45
#define rightkh -45
#define leftmh 45
#define rightmh 45

#define leftzh_x -50
#define rightzh_x -52
#define leftkh_x -54
#define rightkh_x -55
#define leftmh_x -35
#define rightmh_x -32

#define L_xoy 49
#define L_z 19
#define R_xoy 46
#define R_z 45
#define hand 47
#define up_down 22
#define S0 15
#define S1 16
#define S2 3
#define S3 4
#define VCC 14
#define GND 18
#define OUT 2
#define LED 17


#define RGB 30
#define Speak 34
#define Black 53
#define R 31
#define G 32
#define B 33

#define X_sensor1 13
#define X_sensor2 12
#define X_sensor3 11

#define X_sensor4 23
#define X_sensor5 24
#define X_sensor6 25

#define Y_sensor1 26
#define Y_sensor2 27
#define Y_sensor3 28

#define Y_sensor4 42
#define Y_sensor5 43
#define Y_sensor6 44

#define hair_sensor 37
#define head_sensor 35
#define center_sensor 36
#define back_sensor 29

#define X1 Digital_Read(X_sensor1)
#define X2 Digital_Read(X_sensor2)
#define X3 Digital_Read(X_sensor3)

#define X4 Digital_Read(X_sensor4)
#define X5 Digital_Read(X_sensor5)
#define X6 Digital_Read(X_sensor6)

#define Y1 Digital_Read(Y_sensor1)
#define Y2 Digital_Read(Y_sensor2)
#define Y3 Digital_Read(Y_sensor3)

#define Y4 Digital_Read(Y_sensor4)
#define Y5 Digital_Read(Y_sensor5)
#define Y6 Digital_Read(Y_sensor6)

#define AIN1 6
#define AIN2 7
#define PWMA 5

#define BIN1 8
#define BIN2 9
#define PWMB 10

void TSC_Init();//颜色传感器引脚初始化
void Servo_Init();//舵机引脚初始化
void Servo_Locate_Init();//舵机位置初始化
void Motor_Init();//电机引脚初始化
void Track_Sensor_Init();//两排循迹传感器引脚初始化
void Locate_Sensor_Init();//定位传感器引脚初始化
bool Digital_Read(int sensor);//转变灰度传感器的返回值
void TSC_FilterColor(int Level01, int Level02);//改变颜色传感器滤波方式
void TSC_Count();//曝光计数
void TSC_Callback();
void TSC_WB(int Level0, int Level1);//设置振荡器比例因子
int color_value();//识别颜色并返回结果
void become_shenxian();                                         //数组清零用于数线
void motor(double left , double right);                         //电机驱动
bool locate(int b, int sensor);                                 //定位函数
void track_ahead(int location, int stop_sensor);                //向前循迹
void alpha(int location, int stop_sensor);                      //倒车循迹
void low_alpha(int location, int stop_sensor);  
void correct_direction();
void turn_around(int start_direction , int end_direction);      //转向系统
void half_back();
void back();
void ahead_song();            //任务一，不精准停车
void half_ahead();
void ahead();
void open_hand();
void pick_object();
void loose_object();
void catch_object();
void put_object();
void rise_object();
void down_object();
void correct_object();        //使物块堆准
void catch_ABEC();
void L_loose();
void R_loose();
void assignment_dui_one();   //初始在180，把两个物块堆起后再抬升,或者是仅把一个物块拿起
void assignment_dui_two();   //初始为180，把以松动方式三个或两个物块堆起来,并打开手
void ahead_song_zhun();      //任务二，精准的停车
void ahead_zhun();           //从中心到，颜色区准确停车
void leave_home();
void first_assignment();
void second_assignment();
void back_home();
void track_PID();
void init_error();

#endif
