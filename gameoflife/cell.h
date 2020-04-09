#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QGraphicsItem>

// any object that inherits from QObject can emit signals
// things that inherit from QGraphicsItem can be added to QGraphicScenes
class Cell : public QObject, public QGraphicsItem {

    // this makes it so that we can emit signals
    Q_OBJECT

public:
    Cell(QColor color, const int x, const int y);  // constructor

    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function

    double Distance(const Cell &other) const;  // member function

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

// in cell.h
signals:

    void CellSelected(Cell * p);

    void DeleteCell(Cell * p);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
  int x_;
  int y_;
  QColor color_;

  static const int width_ = 20;

  friend bool operator==(const Cell &first, const Cell &other);
};  // class Cell



#endif // Cell_H
