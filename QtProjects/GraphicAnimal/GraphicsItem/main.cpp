#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPropertyAnimation>
#include <QColor>
#include <QTimer>
#include <QTime>
#include "myitem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QGraphicsScene scence;
    scence.setSceneRect(-200,-150,400,300);
    for(int i = 0; i < 5; ++i)
    {
        MyItem * item = new MyItem;
        item->setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
        item->setPos(i*50-90,-50);
        scence.addItem(item);
    }
    QGraphicsView view;
    view.setForegroundBrush(QColor(255,255,255,100));
    //view.setBackgroundBrush(QPixmap("/Users/mac/Desktop/p.png"));
    view.resize(800,600);
    view.setScene(&scence);
    view.show();

//    QPropertyAnimation * animation = new QPropertyAnimation(item, "rotation");
//    animation->setDuration(2000);
//    animation->setStartValue(0);
//    animation->setEndValue(360);
//    animation->start(QAbstractAnimation::DeleteWhenStopped);
//    animation->setLoopCount(100);
    QTimer timer;
    QObject::connect(&timer,SIGNAL(timeout()),&scence,SLOT(advance()));
    timer.start(200);

    return a.exec();
}
