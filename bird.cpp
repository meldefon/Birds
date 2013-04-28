#include "bird.h"
#include <iostream>
#include <QGraphicsSceneMouseEvent>

DBird::DBird(QPixmap* pic, MainWindow* big){
  pic_ = pic;
  big_ = big;
  setPixmap(*pic);
  //id_ = id;
  x = 20+rand()%460;
  y = 20+rand()%460;
  vx= 0;
  vy = 0;
  setPos(x,y);
  type = 0;
  show = true;
  chosen = false;
}

void Bird::mousePressEvent ( QGraphicsSceneMouseEvent* event ) {
  if(event->button() == Qt::LeftButton){
    show = false;
    return;
  }
  chosen = true;
}

/*void mouseDoubleClickEvent( QGraphicsSceneMouseEvent* event ) {
  chosen = true;
  
}*/

void DBird::move(){
}

HBird::HBird(QPixmap* pic, MainWindow* big){
  pic_ = pic;
  big_ = big;
  setPixmap(*pic);
  x = 20+rand()%460;
  y = 20+rand()%460;
  vy = 0;
  //vx = -1;
  vx = (rand()%6+1)*2*(rand()%2-.5);
  setPos(x,y);
  type = 1;
  show = true;
  chosen = false;
}

void HBird::move(){
  x+=vx;
  if(x<0)x+=500;
  if(x>=500)x-=500;
  setPos(x,y);
}
  

VBird::VBird(QPixmap* pic, MainWindow* big){
  pic_ = pic;
  big_ = big;
  setPixmap(*pic);
  x = 20+rand()%460;
  y = 20+rand()%460;
  vx = 0;
  vy = (rand()%5+1)*2*(rand()%2-.5);
  setPos(x,y);
  type = 2;
  show = true;
  chosen = false;
}

void VBird::move(){
  y+=vy;
  if(y<0)y+=500;
  if(y>=500)y-=500;
  setPos(x,y);
}

ZigBird::ZigBird(QPixmap* pic, MainWindow* big){
  pic_ = pic;
  big_ = big;
  setPixmap(*pic);
  type = 3;
  x = 20+rand()%460;
  y = 20+rand()%460;
  vx = 2*(rand()%4-1.5);
  vy = 2*(rand()%4-1.5);
  show = true;
  zig_count = 0;
  zig_speed = 20+rand()%50;
  hor = rand()%2;
  setPos(x,y);
  chosen = false;
}

void ZigBird::move(){
   if(zig_count>=zig_speed){
     zig_count = 0;
     if(hor){
       vy = -vy;
     }
     else{
       vx = -vx;
     }
   }
   x+=vx;
   y+=vy;
   if(x<0)x+=500;
   if(x>=500)x-=500;
   if(y<0)y+=500;
   if(y>=500)y-=500;
   setPos(x,y);
   ++zig_count;
}

LoopBird::LoopBird(QPixmap* pic, MainWindow* big){
  pic_ = pic;
  big_ = big;
  setPixmap(*pic);
  type = 4;
  show = true;
  chosen = false;
}

void LoopBird::move(){
}

RandBird::RandBird(QPixmap* pic, MainWindow* big){
  pic_ = pic;
  big_ = big;
  setPixmap(*pic);
  x = 20+rand()%460;
  y = 20+rand()%460;
  vx = 2*(rand()%4-1.5);
  vy = 2*(rand()%4-1.5);
  type = 5;
  show = true;
  count = 0;
  rand_time = 10+rand()%30;
  chosen = false;
}

void RandBird::move(){
  if(count>=rand_time){
    vx = 2*(rand()%4-1.5);
    vy = 2*(rand()%4-1.5);
    count = 0;
  }
  x+=vx;
  y+=vy;
  if(x<0)x+=500;
  if(x>=500)x-=500;
  if(y<0)y+=500;
  if(y>=500)y-=500;
  setPos(x,y);
  ++count;
  
    
}
