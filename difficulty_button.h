#ifndef DIFFICULTY_BUTTON_H
#define DIFFICULTY_BUTTON_H
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QString>
#include <string>

class DifficultyButton: public QGraphicsRectItem{
  public:
    DifficultyButton(std::string text_string);
    void mousePressEvent ( QGraphicsSceneMouseEvent* event );
    bool chosen;
    QGraphicsTextItem* text_;
};


#endif


