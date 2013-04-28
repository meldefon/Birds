#ifndef BIRD_H
#define BIRD_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QGraphicsScene>
//#include "mainwindow.h"

class MainWindow;

class Bird : public QGraphicsPixmapItem{
  public:
    //Bird(QPixmap* pic, MainWindow* big);
    virtual void move() = 0;
    QPixmap* pic_;
    int type;
    int id_;
    float x;
    float y;
    float vx;
    float vy;
    MainWindow* big_;
    void mousePressEvent ( QGraphicsSceneMouseEvent* event );
    bool show;
   
};

class DBird: public Bird{
  public:
    DBird(QPixmap* pic, MainWindow* big,int id);
    void move();
};

class HBird: public Bird{
  public:
    HBird(QPixmap* pic, MainWindow* big,int id);
    void move();
};

class VBird: public Bird{
  public:
    VBird(QPixmap* pic, MainWindow* big,int id);
    void move();
};

class ZigBird: public Bird{
  public:
    ZigBird(QPixmap* pic, MainWindow* big,int id);
    void move();
    int zig_count;
    int zig_speed;
    bool hor;
};

class LoopBird: public Bird{
  public:
    LoopBird(QPixmap* pic, MainWindow* big,int id);
    void move();
};

class RandBird: public Bird{
  public:
    RandBird(QPixmap* pic, MainWindow* big,int id);
    void move();
    int count;
    int rand_time;
};
  

#endif
