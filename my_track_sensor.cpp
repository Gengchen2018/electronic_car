
#include <Arduino.h>
#include "a_car.h"

//循迹传感器黑为0，白为1
//定位传感器黑为1，白为0

static float integer_error = 0;

bool Digital_Read(int sensor)
{
  if (digitalRead(sensor))
    return false;
  return true;
}

void Track_Sensor_Init()
{
  pinMode(X_sensor1, INPUT);
  pinMode(X_sensor2, INPUT);
  pinMode(X_sensor3, INPUT);

  pinMode(X_sensor4, INPUT);
  pinMode(X_sensor5, INPUT);
  pinMode(X_sensor6, INPUT);

  pinMode(Y_sensor1, INPUT);
  pinMode(Y_sensor2, INPUT);
  pinMode(Y_sensor3, INPUT);

  pinMode(Y_sensor4, INPUT);
  pinMode(Y_sensor5, INPUT);
  pinMode(Y_sensor6, INPUT);


}

void track_ahead(int location, int stop_sensor)
{
  while (locate(location, stop_sensor))
  {
    if (X1 && X2 && X3 && X4 && X5 && X6)
    {
      motor(leftz, rightz);
    }
    else if (X1 && X2 && !X3 && X4 && X5 && X6)
    {
      motor(leftm, rightk);
    }
    else if (X1 && !X2 && !X3 && X4 && X5 && X6)
    {
      motor(leftm, rightk);
    }
    else if (X1 && !X2 && X3 && X4 && X5 && X6)
    {
      motor(leftm, rightk );
    }
    else if (!X1 && !X2 && X3 && X4 && X5 && X6)
    {
      motor(leftm, rightk);
    }
    else if (!X1 && X2 && X3 && X4 && X5 && X6)
    {
      motor(leftm, rightk);
    }
    else if (X1 && X2 && X3 && !X4 && X5 && X6)
    {
      motor(leftk, rightm);
    }
    else if (X1 && X2 && X3 && !X4 && !X5 && X6)
    {
      motor(leftk, rightm);
    }
    else if (X1 && X2 && X3 && X4 && !X5 && X6)
    {
      motor(leftk, rightm);
    }
    else if (X1 && X2 && X3 && X4 && !X5 && !X6)
    {
      motor(leftk, rightm);
    }
    else if (X1 && X2 && X3 && X4 && X5 && !X6)
    {
      motor(leftk, rightm);
    }
    else if (!X1 && !X2 && !X3 && !X4 && !X5 && !X6)
    {
      motor(leftz, rightz);
    }
    else if (X2 && X3 && X4 && X5)
    {
      motor(leftz, rightz);
    }
    else if (X2 && !X3 && X4 && X5)
    {
      motor(leftm, rightk);
    }
    else if (!X2 && !X3 && X4 && X5)
    {
      motor(leftm, rightk);
    }
    else if (!X2 && X3 && X4 && X5)
    {
      motor(leftm, rightk);
    }
    else if ( X2 && X3 && !X4 && X5)
    {
      motor(leftk, rightm);
    }
    else if (X2 && X3 && !X4 && !X5)
    {
      motor(leftk, rightm);
    }
    else if ( X2 && X3 && X4 && !X5)
    {
      motor(leftk, rightm);
    }
    else if (!X2 && !X3 && !X4 && !X5)
    {
      motor(leftz, rightz);
    }
    else
    {
      motor(leftz, rightz);
    }
  }
}

void alpha(int location, int stop_sensor)
{
  while (locate(location, stop_sensor))
  {
    //后退循迹程序
    if (Y1 && Y2 && Y3 && Y4 && Y5 && Y6)
    {
      motor(leftzh, rightzh);
    }
    else if (Y1 && Y2 && !Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh_x, rightkh_x);
    }
    else if (Y1 && !Y2 && !Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh, rightkh);
    }
    else if (Y1 && !Y2 && Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh, rightkh);
    }
    else if (!Y1 && !Y2 && Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh, rightkh);
    }
    else if (!Y1 && Y2 && Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh, rightkh);
    }
    else if (Y1 && Y2 && Y3 && !Y4 && Y5 && Y6)
    {
      motor(leftkh_x, rightmh_x);
    }
    else if (Y1 && Y2 && Y3 && !Y4 && !Y5 && Y6)
    {
      motor(leftkh, rightmh);
    }
    else if (Y1 && Y2 && Y3 && Y4 && !Y5 && Y6)
    {
      motor(leftkh, rightmh);
    }
    else if (Y1 && Y2 && Y3 && Y4 && !Y5 && !Y6)
    {
      motor(leftkh, rightmh);
    }
    else if (Y1 && Y2 && Y3 && Y4 && Y5 && !Y6)
    {
      motor(leftkh, rightmh);
    }
    else if (!Y1 && !Y2 && !Y3 && !Y4 && !Y5 && !Y6)
    {
      motor(leftzh, rightzh);
    }
    else if ( Y2 && Y3 && Y4 && Y5)
    {
      motor(leftzh, rightzh);
    }
    else if (Y2 && !Y3 && Y4 && Y5)
    {
      motor(leftmh, rightkh);
    }
    else if (!Y2 && !Y3 && Y4 && Y5)
    {
      motor(leftmh, rightkh);
    }
    else if ( !Y2 && Y3 && Y4 && Y5)
    {
      motor(leftmh, rightkh);
    }
    else if (Y2 && Y3 && !Y4 && Y5)
    {
      motor(leftkh, rightmh);
    }
    else if (Y2 && Y3 && !Y4 && !Y5)
    {
      motor(leftkh, rightmh);
    }
    else if (Y2 && Y3 && Y4 && !Y5)
    {
      motor(leftkh, rightmh);
    }
    else if (!Y2 && !Y3 && !Y4 && !Y5)
    {
      motor(leftzh, rightzh);
    }
    else
    {
      motor(leftzh, rightzh);
    }
  }
}

void low_alpha(int location, int stop_sensor)
{
  while (locate(location, stop_sensor))
  {
    //后退循迹程序
    if (Y1 && Y2 && Y3 && Y4 && Y5 && Y6)
    {
      motor(leftzh_x, rightzh_x);
    }
    else if (Y1 && Y2 && !Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh_x, rightkh_x);
    }
    else if (Y1 && !Y2 && !Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh_x, rightkh_x);
    }
    else if (Y1 && !Y2 && Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh_x, rightkh_x);
    }
    else if (!Y1 && !Y2 && Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh_x, rightkh_x);
    }
    else if (!Y1 && Y2 && Y3 && Y4 && Y5 && Y6)
    {
      motor(leftmh_x, rightkh_x);
    }
    else if (Y1 && Y2 && Y3 && !Y4 && Y5 && Y6)
    {
      motor(leftkh_x, rightmh_x);
    }
    else if (Y1 && Y2 && Y3 && !Y4 && !Y5 && Y6)
    {
      motor(leftkh_x, rightmh_x);
    }
    else if (Y1 && Y2 && Y3 && Y4 && !Y5 && Y6)
    {
      motor(leftkh_x, rightmh_x);
    }
    else if (Y1 && Y2 && Y3 && Y4 && !Y5 && !Y6)
    {
      motor(leftkh_x, rightmh_x);
    }
    else if (Y1 && Y2 && Y3 && Y4 && Y5 && !Y6)
    {
      motor(leftkh_x, rightmh_x);
    }
    else if (!Y1 && !Y2 && !Y3 && !Y4 && !Y5 && !Y6)
    {
      motor(leftzh_x, rightzh_x);
    }
    else if ( Y2 && Y3 && Y4 && Y5)
    {
      motor(leftzh_x, rightzh_x);
    }
    else if (Y2 && !Y3 && Y4 && Y5)
    {
      motor(leftmh_x, rightkh_x);
    }
    else if (!Y2 && !Y3 && Y4 && Y5)
    {
      motor(leftmh_x, rightkh_x);
    }
    else if ( !Y2 && Y3 && Y4 && Y5)
    {
      motor(leftmh_x, rightkh_x);
    }
    else if (Y2 && Y3 && !Y4 && Y5)
    {
      motor(leftkh_x, rightmh_x);
    }
    else if (Y2 && Y3 && !Y4 && !Y5)
    {
      motor(leftkh_x, rightmh_x);
    }
    else if (Y2 && Y3 && Y4 && !Y5)
    {
      motor(leftkh, rightmh);
    }
    else if (!Y2 && !Y3 && !Y4 && !Y5)
    {
      motor(leftzh_x, rightzh_x);
    }
    else
    {
      motor(leftzh, rightzh);
    }
  }
}


void init_error()
{
  integer_error = 0.0;
}

void track_PID()
{
  float error = 0.0, last_error = 0.0, my_error = 0.0;
  float Kp_l = 0.0, Ki_l = 0.0, Kd_l = 0.0;
  float Kp_r = 0.0, Ki_r = 0.0, Kd_r = 0.0;
  float left_speed = 0.0, right_speed = 0.0;
  float left_error = 0.0, right_error = 0.0;
  float pwm_l = 0.0, pwm_r = 0.0;
  float x1 = 0.0, x2 = 0.0, x3 = 0.0, x4 = 0.0, x5 = 0.0;
  float y1 = 0.0, y2 = 0.0, y3 = 0.0, y4 = 0.0, y5 = 0.0;

  if (X1 && X2 && X3 && X4 && X5 && X6)
  {
    error = 0.0;
  }
  else if (X1 && X2 && !X3 && X4 && X5 && X6)
  {
    error = x1;
  }
  else if (X1 && !X2 && !X3 && X4 && X5 && X6)
  {
    error = x2;
  }
  else if (X1 && !X2 && X3 && X4 && X5 && X6)
  {
    error = x3;
  }
  else if (!X1 && !X2 && X3 && X4 && X5 && X6)
  {
    error = x4;
  }
  else if (!X1 && X2 && X3 && X4 && X5 && X6)
  {
    error = x5;
  }
  else if (X1 && X2 && X3 && !X4 && X5 && X6)
  {
    error = y1;
  }
  else if (X1 && X2 && X3 && !X4 && !X5 && X6)
  {
    error = y2;
  }
  else if (X1 && X2 && X3 && X4 && !X5 && X6)
  {
    error = y3;
  }
  else if (X1 && X2 && X3 && X4 && !X5 && !X6)
  {
    error = y4;
  }
  else if (X1 && X2 && X3 && X4 && X5 && !X6)
  {
    error = y5;
  }
  else if (!X1 && !X2 && !X3 && !X4 && !X5 && !X6)
  {
    error = 0.0;
  }
  else if (X2 && X3 && X4 && X5)
  {
    error = 0.0;
  }
  else if (X2 && !X3 && X4 && X5)
  {
    error = x1;
  }
  else if (!X2 && !X3 && X4 && X5)
  {
    error = x2;
  }
  else if (!X2 && X3 && X4 && X5)
  {
    error = x3;
  }
  else if ( X2 && X3 && !X4 && X5)
  {
    error = y1;
  }
  else if (X2 && X3 && !X4 && !X5)
  {
    error = y2;
  }
  else if ( X2 && X3 && X4 && !X5)
  {
    error = y3;
  }
  else if (!X2 && !X3 && !X4 && !X5)
  {
    error = 0.0;
  }
  else
  {
    error = 0.0;
  }
  integer_error += error;
  left_error = Kp_l * error + Ki_l * integer_error + Kd_l * (error - last_error);
  right_error = Kp_r * error + Ki_r * integer_error + Kd_r * (error - last_error);
  last_error = error;
  pwm_l = left_speed - left_error;
  pwm_r = right_speed - right_error;
  motor(pwm_l, pwm_r);
}

