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
#include "difficulty_button.h"


/** MainWindow class is the main object of the game. Stores all relevant information, 
and holds all game widgets.*/
class MainWindow : public QWidget{
  Q_OBJECT
  
  public:
    explicit MainWindow();
    ~MainWindow();
    /** Main show method*/
    void show();
    /**Displays all game graphics*/
    QGraphicsScene* scene;
    /** Stores all playing objects in game*/
    QList<Bird*>* bird_list;
  private:
    /**Main widget - holds all others*/
    QWidget* main;
    
    QGraphicsView* view;
    /**Displays time left in level*/
    QLineEdit* time;
    /**Displays level score*/
    QLineEdit* score;
    /**Displays level number*/
    QLineEdit* level;
    /**Keeps level time. Timeout signal moves all objects*/
    QTimer *timer;
    /**Starts game, restarts new game.*/
    QPushButton* start_button;
    /**Resets entire game*/
    QPushButton* reset_button;
    /**Pauses game*/
    QPushButton* pause_button;
    /**Holds player's name. Becomes read only after game begins*/
    QLineEdit* name_bar;
    /**Labels name bar*/
    QLabel* name_label;
    /**Holds total score*/
    QLineEdit* total_score_bar;
    /**Labels total score*/
    QLabel* total_score_label;
    /**Displays errors*/
    QLineEdit* error_bar;
    /**Outer begin-game timer. Waits for difficulty button presses.*/
    QTimer* begin_timer;
    /**Selects easy*/
    DifficultyButton* easy_button;
    /**Selects difficult*/
    DifficultyButton* med_button;
    /**Selects hard*/
    DifficultyButton* hard_button;
    
    /**Level score*/
    int score_val;
    /**Tells player how much time is left*/
    int time_hint;
    /**Total score*/
    int total_score;

    /**Current level*/
    int current_level;
    /**Not really tenth seconds. Controls timer speed*/
    int tenth_seconds;
    /**Score reqs for each level*/
    int level_recs[6];
    /**Time lengths of each level*/
    int level_times[6];
    /**Shows level info*/
    void show_level_screen();
    /**Allows cheat*/
    bool allow_cheat;
    /**Signals whether game is over or not*/
    bool game_over;
    /**Signals level over*/
    bool level_over;
    /**Signals whether power up has been used*/
    bool power_up_used;
    /**This is the pet bird that catches others*/
    Bird* chosen_one;
    /**Shows the difficulty select screen*/
    void show_front();
    /**Allows game to start when start button is pushed*/
    bool start_enable;
    /**Signals whether the cheat hs been used*/
    bool using_cheat;
    /**Signals to birds whether game is in pause or not*/
    bool bird_active;
    
    /**Adds birds to keep roughly constant crowding*/
    void addBird();

    //Store pictures;
    QPixmap* DBird_pic;
    QPixmap* HBird_pic;
    QPixmap* VBird_pic;
    QPixmap* ZigBird_pic;
    QPixmap* RandBird_pic;
  public slots:
    /**Starts levels*/
    void start_level();
    /**Timer timout signal. Moves objects*/
    void handle_timer();
    /**End level signal*/
    void end_level();
    /**End whole game signal*/
    void end_game();
    /**Begin_timer timeout signal. Sees if difficulty has been selected*/
    void check_begin();
    /**Pause button signal*/
    void pause_game();
    
  
};

#endif
