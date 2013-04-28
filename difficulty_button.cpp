#include "difficulty_button.h"
#include <iostream>

DifficultyButton::DifficultyButton(std::string text_string){
  QString text_q(text_string.c_str());
  text_ = new QGraphicsTextItem(text_q);
  chosen = false;
}

void DifficultyButton::mousePressEvent ( QGraphicsSceneMouseEvent* event ){
  chosen = true;
  //std::cout<<"HERE";
}
