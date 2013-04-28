#include <iostream>
#include <QtGui/QApplication>
#include "mainwindow.h"

using namespace std;

int main(int argc,char* argv[]){

  QApplication a(argc,argv);
  /*for(int i =0;i<10;++i){
  cout<<rand()%1;
  }*/
  
  MainWindow* m = new MainWindow;
  m->show();
  
  
  return a.exec();
}
