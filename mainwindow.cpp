#include "mainwindow.h"
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <string>
#include <sstream>
#include <iostream>
#include <QColor>
//#include "bird.h"

void MainWindow::show_level_screen(){
  if(current_level==0){
    QGraphicsTextItem* level_1 = new QGraphicsTextItem("Level 1\n\nProbably the easiest level I feather seen. \nJust click on the birds to catch them. In this case,\nthey're dead birds, so they won't move. \n\nMake sure to catch enough to meet the minimum\nlevel score before the timer runs out! \n\nThe birds will look like this");
    scene->addItem(level_1);
    level_1->setPos(100,150);
    QGraphicsPixmapItem* example = new QGraphicsPixmapItem;
    example->setPixmap(QPixmap("DBird.png"));
    scene->addItem(example);
    example->setPos(245,350);
    return;
  }
  if(current_level==1){
    QGraphicsTextItem* level_2 = new QGraphicsTextItem("Level 2\n\nGive up now, or you'll egret it. Now there will be\nvertically moving birds. These will be worth\n 30 points, rather than DeadBird's 5. Good Luck.\n\n The newest birds will look like this");
    scene->addItem(level_2);
    level_2->setPos(100,150);
    QGraphicsPixmapItem* example = new QGraphicsPixmapItem;
    example->setPixmap(QPixmap("VBird.png"));
    scene->addItem(example);
    example->setPos(245,300);
    return;
  }
  if(current_level==2){
    QGraphicsTextItem* level_3 = new QGraphicsTextItem("Level 3\n\nYou're Aight. But let's see what you can really do\nNow there will be another bird, worth 45 points.\n\nFrom now on, owl help you out (because you're going\nto need it). the first bird you right click will become\nyour pet, catching all birds it collides with. Go now.\n\n The newest birds will look like this");
    scene->addItem(level_3);
    level_3->setPos(100,150);
    QGraphicsPixmapItem* example = new QGraphicsPixmapItem;
    example->setPixmap(QPixmap("HBird.png"));
    scene->addItem(example);
    example->setPos(245,350);
    return;
  }
  if(current_level==3){
    QGraphicsTextItem* level_4 = new QGraphicsTextItem("Level 4\n\nThink you're stumping me, eh? Toucan play at this game.\nNow there will be another bird, worth 75 points.\n\nYou'll probably find that he's a bit harder to catch...\nMUAHAHAHAH.\n\nHe'll look like this");
    scene->addItem(level_4);
    level_4->setPos(100,150);
    QGraphicsPixmapItem* example = new QGraphicsPixmapItem;
    example->setPixmap(QPixmap("ZigBird.png"));
    scene->addItem(example);
    example->setPos(245,340);
    return;
  }
  if(current_level==4){
    QGraphicsTextItem* level_5 = new QGraphicsTextItem("Level 5\n\nThere's no denying: you've got talont. But this level\nwill be a little more of a... birden. This time you\nmight be lucky enough to sight the majestic RandBird.\nHe's worth 150.\n\nHe'll look like this");
    scene->addItem(level_5);
    level_5->setPos(100,150);
    QGraphicsPixmapItem* example = new QGraphicsPixmapItem;
    example->setPixmap(QPixmap("RandBird.png"));
    scene->addItem(example);
    example->setPos(245,330);
    return;
  }   
  if(current_level==5){
    QGraphicsTextItem* level_6 = new QGraphicsTextItem("Level 5\n\nYou've exhausted my supply of birds.\n\nBut we can still find a way to make things more\nchallenging. Clock's running much faster this time.\n\nIt's Ostrich of the imagination to think how\nyou're gonna survive this one.");
    scene->addItem(level_6);
    level_6->setPos(100,150);
    //QGraphicsPixmapItem* example = new QGraphicsPixmapItem;
    //example->setPixmap(QPixmap("RandBird.png"));
    //scene->addItem(example);
    //example->setPos(245,330);
    return;
  }   
}

QPixmap* get_back(int current_level,QPixmap* temp){
  switch(current_level){
    QPixmap* b;
    case 0:
      b = new QPixmap("hills.png");
      *temp = b->scaled(500,500);
      return temp;
      break;
    case 1:
      b= new QPixmap("beach.png");
      *temp = b->scaled(500,500);
      return temp;
      break;
    case 2:
      b= new QPixmap("desert.png");
      *temp = b->scaled(500,500);
      return temp;
      break;
    case 3: 
      b= new QPixmap("safari.png");
      *temp = b->scaled(500,500);
      return temp;
      break;
    case 4:
      b= new QPixmap("arctic.png");
      *temp = b->scaled(500,500);
      return temp;
     default:
      b= new QPixmap("desert.png");
      *temp = b->scaled(500,500);
      return temp;
      break;       
    }
    return NULL;
}
    

QString score_text(int score, int level_rec){
  std::stringstream c;
  std::string text;
  c<<score<<"/"<<level_rec;
  c>>text;
  return QString(text.c_str());
}  

void MainWindow::addBird(){
  int next_bird_type = rand()%(current_level+1);
  Bird* next_bird;
  //std::cout<<"HERE";
  switch(next_bird_type){
    case 0:
      next_bird = new DBird(DBird_pic,this,1);
      bird_list->push_back(next_bird);
      scene->addItem(next_bird);
    break;
    case 1:
      next_bird = new VBird(VBird_pic,this,1);
      bird_list->push_back(next_bird);
      scene->addItem(next_bird);
      break;
    case 2:
      next_bird = new HBird(HBird_pic,this,1);
      bird_list->push_back(next_bird);
      scene->addItem(next_bird);
      break;
    case 3:
      next_bird = new ZigBird(ZigBird_pic,this,1);
      bird_list->push_back(next_bird);
      scene->addItem(next_bird);
      break;
    case 4:
      next_bird = new RandBird(RandBird_pic,this,1);
      bird_list->push_back(next_bird);
      scene->addItem(next_bird);
      break;
        //std::cout<<"FUCK YOU";
    }
}

int get_score(int type){
  if(type ==0){
    return 5;
  }
  if(type ==2 ){
    return 30;
  }
  if(type==1){
    return 45;
  }
  if(type==3){
    return 75;
  }
  if(type==5){
    return 150;
  }
  return 0;   
}

void MainWindow::start_level(){
  if(current_level==0){
    if(name_bar->text()==QString("")){
      error_bar->setText("Please enter your name before starting");
      return;
    }
    name_bar->setReadOnly(true);
  }
  error_bar->clear();
  timer->stop();
  scene->clear();
  bird_list = new QList<Bird*>;
  score_val = 0;
  score->setText(score_text(0,level_recs[current_level]));
  time->setText("60");
  time_hint = 60;
  std::stringstream c;
  std::string level_text;
  c<<(current_level+1);
  c>>level_text;
  level->setText(QString(level_text.c_str()));
  timer->start();
  
  QPixmap* b = new QPixmap;
  b = get_back(current_level,b);
  /*QPixmap b("hills.png");
  QPixmap temp = b.scaled(500,500);*/
  QGraphicsPixmapItem* background = new QGraphicsPixmapItem;
  background->setPixmap(*b);
  scene->addItem(background);
  background->setPos(0,0);
}
  

void MainWindow::end_level(){
  scene->clear();
  timer->stop();
  if(score_val<level_recs[current_level]){
    QGraphicsPixmapItem* game_over_message = new QGraphicsPixmapItem;
    QGraphicsPixmapItem* crying = new QGraphicsPixmapItem;
    QGraphicsTextItem* knew = new QGraphicsTextItem("Called it.");
    QGraphicsTextItem* restart = new QGraphicsTextItem("To try again from the beginning, click start");
    crying->setPixmap(QPixmap("cry.png"));
    game_over_message->setPixmap(QPixmap("loser.png"));
    restart->setDefaultTextColor(QColor("red"));
    knew->setDefaultTextColor(QColor("red"));
    QFont f("Sans Serif",15);
    knew->setFont(f);
    restart->setFont(f);
    //game_over_message->adjustSize();
    //game_over_message->setFont(f);
    scene->addItem(crying);
    crying->setPos(0,0);
    scene->addItem(game_over_message);
    scene->addItem(restart);
    scene->addItem(knew);
    restart->setPos(15,420);
    knew->setPos(190,395);
    game_over_message->setPos(60,0);
    current_level = 0;
    total_score = 0;
    return;
  }
  total_score+=score_val;
  std::stringstream c;
  std::string score_text;
  c<<total_score;
  c>>score_text;
  total_score_bar->setText(QString(score_text.c_str()));
  ++current_level;
  show_level_screen();
}

void MainWindow::handle_timer(){
  //delete scene;
  QList<Bird* >* copy = new QList<Bird*>;
  ++tenth_seconds;
  if(bird_list->size()<10/*+current_level*current_level*/){
    addBird();
  }
  //std::cout<<level_times[current_level];
  if(tenth_seconds>=level_times[current_level]/*30/*75*/){
    tenth_seconds = 0;
    --time_hint;
    std::stringstream c;
    std::string time_label;
    c<<time_hint;
    c>>time_label;
    time->setText(QString(time_label.c_str()));
    if(rand()%2){
      //addBird();
    }
  }
  if(time_hint==0){
    timer->stop();
    scene->clear();
    bird_list = new QList<Bird*>;
    end_level();
    return;
  }
  
  for(int i = 0;i<bird_list->size();++i){
    if(bird_list->at(i)->show){
      copy->push_back(bird_list->at(i));
    }
    else{
      score_val+=get_score(bird_list->at(i)->type);
      std::stringstream ss;
      ss<<score_val;
      std::string s;
      ss>>s;
      QString g(score_text(score_val,level_recs[current_level]));
      score->setText(g);
      scene->removeItem(bird_list->at(i));
      //scene->removeItem(bird_list[i]);

    }
  }
  for(int i = 0;i<copy->size();++i){
    copy->at(i)->move();
  }
  bird_list = copy;
  //view->show();
}

void MainWindow::end_game(){
  current_level = 0;
  scene->clear();
  bird_list = new QList<Bird*>;
  timer->stop();
  time->setText("");
  score->setText("");
  level->setText("");
  name_bar->clear();
  name_bar->setReadOnly(false);
  total_score = 0;
  total_score_bar->setText("");
  show_level_screen();
  
}



MainWindow::MainWindow(){

  //Initialize total score;
  total_score = 0;

  //Initialize level stuff
  current_level = 5;
  level_recs[0] =125;
  level_recs[1] =225;
  level_recs[2] =350;
  level_recs[3] =500;
  level_recs[4] =800;
  level_recs[5] =1200;
  level_times[0] = 30;
  level_times[1] = 45;
  level_times[2] = 40;
  level_times[3] = 30;
  level_times[4] = 25;
  level_times[5] = 20;
  

  //Initialize bird list
  bird_list = new QList<Bird*>;

  //Initialize the main widget
  main = new QWidget;
  
  //Info Panel Stuff
  QLabel* time_label = new QLabel("Time left");
  time = new QLineEdit;
  time->setReadOnly(true);
  QVBoxLayout* time_layout  = new QVBoxLayout;
  time_layout->addWidget(time_label);
  time_layout->addWidget(time);
  
  QLabel* score_label = new QLabel("Level Score");
  score = new QLineEdit;
  score->setReadOnly(true);
  QVBoxLayout* score_layout = new QVBoxLayout;
  score_layout->addWidget(score_label);
  score_layout->addWidget(score);
  score_val = 0;
  //score->setText(score_text(0,level_recs[current_level]));
  
  QLabel* level_label = new QLabel("Level");
  level = new QLineEdit;
  level->setReadOnly(true);
  QVBoxLayout* level_layout = new QVBoxLayout;
  level_layout->addWidget(level_label);
  level_layout->addWidget(level);
  
  QHBoxLayout* info_layout = new QHBoxLayout;
  info_layout->addLayout(time_layout);
  info_layout->addLayout(score_layout);
  info_layout->addLayout(level_layout);
  
  
  //Scene Stuff
  scene = new QGraphicsScene;
  view = new QGraphicsView(scene);
  view->setSceneRect(0,0,500,500);
  QHBoxLayout* board_layout = new QHBoxLayout;
  board_layout->addWidget(view);
 
  
  //Status Panel Stuff
  status_bar = new QLineEdit;
  //status_bar->setReadOnly(true);
  start_button = new QPushButton("Start");
  reset_button = new QPushButton("Reset");
  name_bar = new QLineEdit;
  total_score_bar = new QLineEdit;
  
  total_score_bar->setReadOnly(true);
  name_label = new QLabel("Name");
  total_score_label = new QLabel("Total Score");
  
  QVBoxLayout* name_layout = new QVBoxLayout;
  QVBoxLayout* total_score_layout = new QVBoxLayout;
  name_layout->addWidget(name_label);
  name_layout->addWidget(name_bar);
  total_score_layout->addWidget(total_score_label);
  total_score_layout->addWidget(total_score_bar);
  

  
  QHBoxLayout* status_panel_layout = new QHBoxLayout;
  status_panel_layout->addLayout(name_layout);
  status_panel_layout->addLayout(total_score_layout);
  status_panel_layout->addWidget(start_button);
  status_panel_layout->addWidget(reset_button);
  connect(start_button,SIGNAL(clicked()),this,SLOT(start_level()));
  connect(reset_button,SIGNAL(clicked()),this,SLOT(end_game()));
  
  error_bar = new QLineEdit;
  error_bar->setReadOnly(true);
  
  
  //Set pic members
  DBird_pic = new QPixmap("DBird.png");
  HBird_pic = new QPixmap("HBird.png");
  VBird_pic = new QPixmap("VBird.png");
  ZigBird_pic = new QPixmap("ZigBird.png");
  RandBird_pic = new QPixmap("RandBird.png");
  
  /*DBird* bird_1 = new DBird(pic1,this,0);
  HBird* bird_2 = new HBird(pic2,this,1);
  VBird* bird_3 = new VBird(pic3,this,2);
  ZigBird* bird_4 = new ZigBird(pic4,this,3);
  RandBird* bird_5 = new RandBird(pic5,this,4);
  bird_list->push_back(bird_1);
  bird_list->push_back(bird_2);
  bird_list->push_back(bird_3);
  bird_list->push_back(bird_4);
  bird_list->push_back(bird_5);
  
  //QPixmap* p = &pic1;
  scene->addItem(bird_1);
  scene->addItem(bird_2);
  scene->addItem(bird_3);
  scene->addItem(bird_4);
  scene->addItem(bird_5);*/
  
  
  //Set whole widget layout   
  QVBoxLayout* whole_layout = new QVBoxLayout;
  whole_layout->addLayout(info_layout);
  whole_layout->addLayout(board_layout);
  whole_layout->addLayout(status_panel_layout);
  whole_layout->addWidget(error_bar);
  main->setLayout(whole_layout);
  main->setGeometry(0,0,650,670);
  
  //Timer stuff
  tenth_seconds = 0;
  timer = new QTimer(this);
  timer->setInterval(10);
  connect(timer,SIGNAL(timeout()),this,SLOT(handle_timer()));
  
  show_level_screen();
  
    
}

MainWindow::~MainWindow(){
}

void MainWindow::show(){
  main->show();
  //start_level();
}