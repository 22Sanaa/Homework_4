#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

#include "cell.h"

/**
  Creates a new Cell object with coordinates x and y
  @param x int x coordinate
  @param y int y coordinate
*/

Cell::Cell(QColor color, const int x, const int y) {
    this->color_ = color;
    bool deadOrAlive = false;
    x_ = x;
    y_ = y;
}

//in Cell.cpp
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Cell clicked!";

    if (event->button() == Qt::RightButton) {
        qDebug() << "right button clicked!";
        emit CellSelected(this);
    }

    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    QColor c(r, g, b);
    color_ = c;
    qDebug() << "(" << r << "," << g << "," << b << ")";

    // need to make the Cell actually re-paint itself
    update();

    // Day 3, Task 3
    // always emit the delete signal, let the PlotWindow decide whether or not to pay attention
    emit DeleteCell(this);
}

// where is this object located
// always a rectangle, Qt uses this to know "where" the user
// would be interacting with this object
QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

// define the actual shape of the object
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}

// called by Qt to actually display the Cell
void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
    painter->setBrush(QBrush(color_));

    painter->drawEllipse(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}

/**
  Calculates the distance between this Cell and another Cell.
  @param other Cell object to calculate the distance to
*/
double Cell::Distance(const Cell &other) const {
  double distance = (x_ - other.get_x()) * (x_ - other.get_x());
  distance += (y_ - other.y_) * (y_ - other.y_);
  return sqrt(distance);
}


/**
  Makes it so the == operator will have the behavior that you
  expect when comparing Cells.
  You can overload pretty much any operator in c++
  @param first Cell left hand side of the expression
  @param other Cell right hand side of the expression
*/
bool operator==(const Cell &first, const Cell &other) {
  return first.x_ == other.x_ && first.y_ == other.y_;
}
