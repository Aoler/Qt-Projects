#include <QMouseEvent>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsSceneEvent>
#include <QGraphicsSceneContextMenuEvent>

class MyItem : public QGraphicsItem
{
public:
    MyItem();
    QPainterPath shape();
    QRectF boundingRect() const;
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,QWidget * widget);
    void mouseMoveEvent(QMouseEvent *event);
    void setColor(const QColor &color) { brushColor = color; }
    void advance(int phase);
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
private:
    QColor brushColor;
};


