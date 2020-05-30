//刹车动作单独写，其余自带延时
//前进后退循迹自带循环
#include <Arduino.h>
#include "a_car.h"

int colorA = 0 ;
int colorB = 0;
int colorC = 0;
int colorD = 0;
int colorE = 0;

int lu = 3;

void leave_home()
{
  become_shenxian();
  track_ahead(6, center_sensor);
  become_shenxian();
  track_ahead(4, center_sensor);
  motor(-90, -95);
  delay(63);
  motor(0, 0);
  delay(100);
  open_hand();
}

void first_assignment()
{
  turn_around(lu, 1);
  lu = 1;
  half_ahead();
  pick_object();
  color_value() ;
  colorA = color_value() ;
  if (colorA == 1 || colorA == 2 || colorA == 4)
  {
    if (colorA == 1)
    {
      ahead_song();//绿色物块配送完毕
      open_hand();
      loose_object();
    }
    else
    {
      half_back();
      turn_around(lu, colorA);
      lu = colorA;
      ahead();
      open_hand();
      loose_object();
    }
    back();
    turn_around(lu, 3);
    lu = 3;
    half_ahead();
    pick_object();
    color_value() ;
    colorC = color_value() ;
    if (colorC == 3)
    { //第一个抓住的物块为简单色且第二个抓住的物块为红色
      ahead_song();
      open_hand();
      loose_object();
      //红色物块配送完毕
      back();
      turn_around(lu, 5);
      lu = 5;
      half_ahead();
      pick_object();
      color_value() ;
      colorE = color_value() ;
      if (colorE == 5)
      { //第一个抓住的物块为绿色且第二个抓住的物块为红色且第三个抓住的是蓝色
        ahead_song();
        open_hand();
        loose_object();
        //第三个物块配送完毕
        back();
        motor(0, 0);
      }
      else
      { //第一个抓住的物块为绿色且第二个抓住的物块为红色且第三个抓住的是其他颜色
        half_back();
        turn_around(lu, colorE);
        lu = colorE;
        ahead();
        open_hand();
        loose_object();
        //第三个物块配送完毕
        back();
        motor(0, 0);
      }
    }
    else
    { //第一个抓住的物块为简单色且第二个抓住的物块是其他颜色
      if (colorC == 5)
      { //第一个抓住的物块为简单色且第二个抓住的物块是蓝色（第2、3冲突）
        half_back();
        rise_object();
        turn_around(lu, 5);      //转到第五路
        lu = 5;
        half_ahead();
        catch_object();
        color_value() ;
        colorE = color_value() ;
        half_back();                 //返回原点
        turn_around(lu, colorE);   //转到第三个物块所在的路
        lu = colorE;
        ahead();                   //第二个物块成功
        put_object() ;
        back();               //返回原点
        turn_around(lu, 5);   //转到第三个物块所在的路
        lu = 5;
        ahead();              //第三个物块成功
        down_object();
        open_hand();
        loose_object();
        back();              //返回起始位置
        motor(0, 0);         //任务1结束
      }
      else
      { //第一个抓住的物块为绿色且第二个抓住的物块不是蓝色也不是红色（第二个物块不冲突也不简便）
        half_back();
        turn_around(lu, colorC);
        lu = colorC;
        ahead();
        open_hand();
        loose_object();
        back();
        turn_around(lu, 5);
        lu = 5;
        half_ahead();
        pick_object();
        color_value() ;
        colorE = color_value() ;
        if (colorE == 5)
        {
          ahead_song();
          open_hand();
          loose_object();
          back();
          motor(0, 0);
        }
        else
        {
          half_back();
          turn_around(lu, colorE);
          lu = colorE;
          ahead();
          open_hand();
          loose_object();
          back();
          motor(0, 0);
        }
      }
    }
  }
  else
  { // 第一个抓住的物块为红或蓝
    int three;
    if (colorA == 3)
    {
      three = 5;
    }
    else
    {
      three = 3;
    }
    half_back();
    rise_object();
    turn_around(lu, three);
    lu = three;
    half_ahead();
    catch_object();
    if (colorA == 3)
    {
      color_value() ;
      colorE = color_value() ;
      if (lu == colorE)
      {
        ahead_song();
        put_object();
        back();
      }
      else
      {
        half_back();
        turn_around(lu, colorE);
        lu = colorE;
        ahead();
        put_object();
        back();
      }
      turn_around(lu, colorA);
      lu = colorA;
      half_ahead();
      catch_object();
      color_value() ;
      colorC = color_value() ;
      half_back();
      turn_around(lu, colorC);
      lu = colorC;
      ahead();
      put_object();
      back();
    }
    else
    {
      color_value() ;
      colorC = color_value() ;
      if (lu == colorC)
      {
        ahead_song();
        put_object();
        back();
      }
      else
      {
        half_back();
        turn_around(lu, colorC);
        lu = colorC;
        ahead();
        put_object();
        back();
      }
      turn_around(lu, colorA);
      lu = colorA;
      half_ahead();
      catch_object();
      color_value() ;
      colorE = color_value() ;
      half_back();
      turn_around(lu, colorE);
      lu = colorE;
      ahead();
      put_object();
      back();
    }
    turn_around(lu, colorA);
    lu = colorA;
    ahead();
    down_object();
    open_hand();
    loose_object();
    back();              //返回起始位置
    motor(0, 0);         //任务1结束
  }
}

void second_assignment()
{

  //撞开F区AB
  pick_object();
  turn_around(lu, 8);
  lu = 8;
  rise_object();
  half_ahead();
  become_shenxian();
  track_ahead(2, head_sensor);
  become_shenxian();
  track_ahead(2, X_sensor1);
  motor(-95, -97);
  delay(56);
  motor(0, 0);
  delay(300);
  catch_ABEC();

  //把A放在了8路
  become_shenxian();
  alpha(2, back_sensor);
  become_shenxian();
  alpha(2, head_sensor);
  motor(95, 95);
  delay(30);
  motor(0, 0);
  delay(300);
  R_loose();

  //把B放在手里并抬升，推理colorD
  half_back();
  turn_around(lu, 6);
  lu = 6;
  L_loose();
  half_ahead();
  assignment_dui_two();
  pick_object();
  color_value();
  colorB = color_value();
  colorD = 1 + 2 + 3 + 4 + 5 - colorA - colorB - colorC - colorE;
  rise_object();

  //撞开G区AB
  become_shenxian();
  track_ahead(2, head_sensor);
  become_shenxian();
  track_ahead(2, X_sensor1);
  motor(-95, -97);
  delay(58);
  motor(0, 0);
  delay(500);
  catch_ABEC();

  //把A放在了6路
  become_shenxian();
  alpha(2, back_sensor);
  become_shenxian();
  alpha(2, head_sensor);
  motor(95, 95);
  delay(30);
  motor(0, 0);
  delay(300);
  L_loose();
  delay(200);
  half_back();
  delay(300);

  //配送B
  turn_around(lu, colorB);
  lu = colorB;
  R_loose();
  half_ahead();
  catch_object();
  ahead_song_zhun();
  put_object();
  assignment_dui_two();
  correct_object();
  back();
  delay(300); //送完B

  //撞F--EC
  turn_around(lu, 8);
  lu = 8;
  pick_object();
  rise_object();
  half_ahead();
  assignment_dui_one();
  become_shenxian();
  track_ahead(4, head_sensor);
  delay(70);
  motor(-93, -95);
  delay(85);
  motor(0, 0);
  delay(300);
  catch_ABEC();

  //把E放在了8路
  become_shenxian();
  alpha(4, hair_sensor);
  become_shenxian();
  alpha(2, head_sensor);
  motor(95, 95);
  delay(30);
  motor(0, 0);
  delay(300);
  R_loose();
  half_back();
  delay(300);

  //把C放在对应方向
  turn_around(lu, colorC);
  lu = colorC;
  L_loose();
  become_shenxian();
  track_ahead(2, head_sensor);
  motor(-95, -95);
  delay(30);
  motor(0, 0);
  delay(300);
  become_shenxian();
  alpha(2, center_sensor);
  delay(30);
  motor(90, 90);
  delay(40);
  motor(0, 0);
  delay(300);

  //撞G--EC
  turn_around(lu, 6);
  lu = 6;
  half_ahead();
  assignment_dui_one();//手里两个A
  become_shenxian();
  track_ahead(4, head_sensor);
  delay(70);
  motor(-93, -95);
  delay(85);
  motor(0, 0);
  delay(300);
  catch_ABEC();

  //把C放在了6路
  become_shenxian();
  alpha(4, hair_sensor);
  become_shenxian();
  alpha(2, head_sensor);
  motor(95, 95);
  delay(30);
  motor(0, 0);
  delay(300);
  R_loose();
  half_back();
  delay(300);

  //把E放在对应方向
  turn_around(lu, colorE);
  lu = colorE;
  L_loose();
  become_shenxian();
  track_ahead(2, head_sensor);
  motor(-95, -95);
  delay(30);
  motor(0, 0);
  delay(300);
  become_shenxian();
  alpha(2, center_sensor);
  delay(30);
  motor(90, 90);
  delay(40);
  motor(0, 0);
  delay(300);

  //配送A
  turn_around(lu, colorA);
  lu = colorA;
  ahead_zhun();
  catch_object();
  put_object();
  assignment_dui_two();
  correct_object();
  back();//A完
  delay(300);


  turn_around(lu, 8);
  lu = 8;
  half_ahead();
  pick_object();
  rise_object();
  become_shenxian();
  track_ahead(4, head_sensor);
  track_ahead(1, hair_sensor);
  motor(-95, -95);
  delay(30);
  motor(0, 0);
  catch_object();
  become_shenxian();
  alpha(6, back_sensor);
  alpha(2, center_sensor);
  motor(95, 95);
  delay(40);
  motor(0, 0);
  delay(200);
  turn_around(lu, colorD);
  lu = colorD;
  ahead();
  put_object();
  back();
  delay(300);

  //配送E
  turn_around(lu, colorE);
  lu = colorE;
  half_ahead();
  assignment_dui_one();
  ahead_song_zhun();
  catch_object();
  put_object();
  assignment_dui_two();
  correct_object();
  back();//E玩
  delay(300);

  turn_around(lu, 6);
  lu = 6;
  half_ahead();
  pick_object();
  rise_object();
  become_shenxian();
  track_ahead(4, head_sensor);
  track_ahead(1, hair_sensor);
  motor(-95, -95);
  delay(30);
  motor(0, 0);
  catch_object();
  become_shenxian();
  alpha(6, back_sensor);
  alpha(2, center_sensor);
  motor(95, 95);
  delay(40);
  motor(0, 0);
  delay(300);

  //把D放在对应方向
  turn_around(lu, colorD);
  lu = colorD;
  become_shenxian();
  track_ahead(2, head_sensor);
  motor(-95, -95);
  delay(30);
  motor(0, 0);
  delay(300);
  put_object();
  become_shenxian();
  alpha(2, center_sensor);
  delay(30);
  motor(90, 90);
  delay(40);
  motor(0, 0);
  delay(300);

  //配送C
  turn_around(lu, colorC);
  lu = colorC;
  half_ahead();
  assignment_dui_one();
  ahead_song_zhun();
  catch_object();
  put_object();
  assignment_dui_two();
  correct_object();
  back();//C完
  delay(300);

  //配送D
  turn_around(lu, colorD);
  lu = colorD;
  half_ahead();
  pick_object();
  rise_object();
  ahead_song_zhun();
  catch_object();
  put_object();
  assignment_dui_two();
  correct_object();
  back();//D完
  delay(300);
}

void back_home()
{
  pick_object();
  turn_around(lu,7);
  lu=7;
  become_shenxian();
  track_ahead(7, hair_sensor);
  motor(-95, -95);
  delay(70);
  while (1)
  {
    motor(0, 0);
  }
}
