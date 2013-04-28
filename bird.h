#ifndef BIRD_H
#define BIRD_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QGraphicsScene>
//#include "mainwindow.h"

class MainWindow;

/**Bird abstract class. Inherited classes implement move function*/
class Bird : public QGraphicsPixmapItem{
  public:
    //Bird(QPixmap* pic, MainWindow* big);
    virtual void move() = 0;
    QPixmap* pic_;
    int type;
    //int id_;
    /**x position*/
    float x;
    /**y position*/
    float y;
    /**x velocity*/
    float vx;
    /**y velocity*/
    float vy;
    /**Pointer to its parent mainwindow*/
    MainWindow* big_;
    /**Reimplements mouse click event*/
    void mousePressEvent ( QGraphicsSceneMouseEvent* event );
    /**Signals whether bird has been caught*/
    bool show;
    /**Signals whether bird has been right clicked*/
    bool chosen;
    /**Signals whether clicking should have any effect*/
    bool* active_;
};

class DBird: public Bird{
  public:
    DBird(QPixmap* pic, MainWindow* big,bool* active);
    void move();
};

class HBird: public Bird{
  public:
    HBird(QPixmap* pic, MainWindow* big,bool* active);
    void move();
};

class VBird: public Bird{
  public:
    VBird(QPixmap* pic, MainWindow* big,bool* active);
    void move();
};

class ZigBird: public Bird{
  public:
    ZigBird(QPixmap* pic, MainWindow* big,bool* active);
    void move();
    int zig_count;
    int zig_speed;
    bool hor;
};

class LoopBird: public Bird{
  public:
    LoopBird(QPixmap* pic, MainWindow* big,bool* active);
    void move();
};

class RandBird: public Bird{
  public:
    RandBird(QPixmap* pic, MainWindow* big,bool* active);
    void move();
    int count;
    int rand_time;
};
  

#endif
