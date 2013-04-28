#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>
#include <QTimer>
#include <QList>
#include <QLabel>
#include <QPushButton>
#include "bird.h"



class MainWindow : public QWidget{
  Q_OBJECT
  
  public:
    explicit MainWindow();
    ~MainWindow();
  
    void show();
    QGraphicsScene* scene;
    QList<Bird*>* bird_list;
    //void handle_click(int id);
  private:
    QWidget* main;

    QGraphicsView* view;
    QLineEdit* time;
    QLineEdit* score;
    QLineEdit* level;
    QTimer *timer;
    QTimer* level_timer;
    QLineEdit* status_bar;
    QPushButton* start_button;
    QPushButton* reset_button;
    QLineEdit* name_bar;
    QLabel* name_label;
    QLineEdit* total_score_bar;
    QLabel* total_score_label;
    QLineEdit* error_bar;
    
    int score_val;
    int time_hint;
    int total_score;

    int current_level;
    int tenth_seconds;
    int level_recs[6];
    int level_times[6];
    void show_level_screen();
    
    void addBird();

    //Store pictures;
    QPixmap* DBird_pic;
    QPixmap* HBird_pic;
    QPixmap* VBird_pic;
    QPixmap* ZigBird_pic;
    QPixmap* RandBird_pic;
  public slots:
    void start_level();
    void handle_timer();
    void end_level();
    void end_game();
    
  
};

#endif