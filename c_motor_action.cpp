
#include <Arduino.h>
#include "a_car.h"

void half_back()
{
  become_shenxian();
  alpha(2, back_sensor);
  become_shenxian();
  alpha(2, center_sensor);
  delay(30);
  motor(93, 95);
  delay(40);
  motor(0, 0);
  delay(300);
}

void ahead_song()
{
  become_shenxian();
  track_ahead(1, hair_sensor);
  motor(-95, -95);
  delay(50);
  motor(0, 0);
  delay(300);
}

void back()
{
  become_shenxian();
  low_alpha(2, center_sensor);
  become_shenxian();
  alpha(2, center_sensor);
  motor(95, 95);
  delay(40);
  motor(0, 0);
  delay(300);
}

void half_ahead()
{
  become_shenxian();
  track_ahead(2, head_sensor);
  become_shenxian();
  track_ahead(2, center_sensor);
  motor(-95, -95);
  delay(30);
  motor(0, 0);
  delay(300);
}

void ahead()
{
  become_shenxian();
  track_ahead(2, head_sensor);
  become_shenxian();
  track_ahead(2, center_sensor);
  motor(0,0);
  become_shenxian();
  track_ahead(1, hair_sensor);
  motor(-95, -95);
  delay(50);
  motor(0, 0);
  delay(300);
}

void ahead_song_zhun()
{
  become_shenxian();
  track_ahead(1, head_sensor);
  motor(-90, -95);
  delay(27);
  motor(0, 0);
  delay(300);
}

void ahead_zhun()
{
  become_shenxian();
  track_ahead(2, head_sensor);
  become_shenxian();
  track_ahead(2, center_sensor);
  motor(0,0);
  become_shenxian();
  track_ahead(1, head_sensor);
  motor(-93, -95);
  delay(30);
  motor(0, 0);
  delay(300);
}


