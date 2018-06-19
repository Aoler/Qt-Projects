#include "myitem.h"
#include <QPainter>
#include <QGraphicsView>
#include <QMenu>
#include <QAction>

MyItem::MyItem()
{
    brushColor = Qt::red;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
}

QPainterPath MyItem::shape()
{
    QPainterPath path;
    path.addRect(-10,-10,20,20);
    return path;
}

QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-10 - penWidth/2,-10 - penWidth/2,20+penWidth,20+penWidth);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(hasFocus() || !collidingItems().isEmpty())
    {
        painter->setPen(QPen(QColor(255,255,255,200)));
    }
    else
    {
        painter->setPen(QPen(QColor(100,100,100,100)));
    }
    painter->setBrush(brushColor);
    painter->drawRect(-10,-10,20,20);
}

void MyItem::mouseMoveEvent(QMouseEvent *event)
{
    QPoint viewPos = event->pos();
    qDebug() << "viewPos: " << viewPos;
    QPointF scenePos = mapToScene(viewPos);
    qDebug() << "scenePos:" << scenePos;
    //QGraphicsItem * item = scene()->i
}

void MyItem::advance(int phase)
{
    if(!phase)
        return;
    int value = qrand() % 100;
    if(value < 25)
    {
        setRotation(45);
        moveBy(qrand()%10,qrand()%10);
    }
    else if (value < 50)
    {
        setRotation(-45);
        moveBy(-qrand()%10,-qrand()%10);
    }
    else if (value < 75)
    {
        setRotation(-30);
        moveBy(-qrand()%10,qrand()%10);
    }
    else
    {
        setRotation(-30);
        moveBy(qrand()%10,-qrand()%10);
    }

}

void MyItem::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Down:
        moveBy(0,10);
        break;
    case Qt::Key_Plus:
        setScale(1.2);
        break;
    case Qt::Key_Minus:
        setScale(1/1.2);
        break;
    case Qt::Key_Right:
        setRotation(30);
        break;
    default:
        break;
    }
    // QGraphicsView::keyPressEvent(event);
}

void MyItem::mousePressEvent(QGraphicsSceneEvent *event)
{
    setFocus();
    setCursor(Qt::ClosedHandCursor);
}

void MyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    setToolTip("I am Item");
}

void MyItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction * moveAction = menu.addAction("move back");
    QAction * selectedAction = menu.exec(event->screenPos());
    if(selectedAction = moveAction)
    {
        setPos(0,0);
    }
}
