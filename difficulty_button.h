#ifndef DIFFICULTY_BUTTON_H
#define DIFFICULTY_BUTTON_H
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QString>
#include <string>

/**Will implement the difficulty button at the front screen*/
class DifficultyButton: public QGraphicsRectItem{
  public:
    DifficultyButton(std::string text_string);
    void mousePressEvent ( QGraphicsSceneMouseEvent* event );
    /**Signals whether button has been pressed. Flipped on during click event.*/
    bool chosen;
    /**Text on the button*/
    QGraphicsTextItem* text_;
};


#endif


