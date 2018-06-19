//#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>

void ParallelAnimation();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ParallelAnimation();
    QPushButton button1("Animal Button");
    button1.show();
    QPushButton button2("Animal button2");
    button2.show();

    QPropertyAnimation * animal = new QPropertyAnimation(&button1,"geometry");
    animal->setDuration(2000);
    animal->setStartValue(QRect(250,0,100,30));
    animal->setEndValue(QRect(250,300,100,30));

    QPropertyAnimation *animal2 = new QPropertyAnimation(&button2,"geometry");
    animal2->setDuration(2000);
    animal2->setStartValue(QRect(400,300,100,30));
    animal2->setEndValue(QRect(400,300,200,60));
    QParallelAnimationGroup group;
    group.addAnimation(animal);
    group.addAnimation(animal2);
    group.start();
    return a.exec();
}

void ParallelAnimation()
{
    QPushButton button1("Animal Button");
    button1.show();
    QPushButton button2("Animal button2");
    button2.show();

    QPropertyAnimation * animal = new QPropertyAnimation(&button1,"geometry");
    animal->setDuration(2000);
    animal->setStartValue(QRect(250,0,100,30));
    animal->setEndValue(QRect(250,300,100,30));

    QPropertyAnimation *animal2 = new QPropertyAnimation(&button2,"geometry");
    animal2->setDuration(2000);
    animal2->setStartValue(QRect(400,300,100,30));
    animal2->setEndValue(QRect(400,300,200,60));
    QParallelAnimationGroup group;
    group.addAnimation(animal);
    group.addAnimation(animal2);
    group.start();

}

void SequentialAnimal()
{
    QPushButton button("Animal Button");
    button.show();
    QPropertyAnimation animatiom(&button,"geometry");
    animatiom.setDuration(2000);
    animatiom.setStartValue(QRect(250,0,100,30));
    animatiom.setEndValue(QRect(250,300,200,60));
    animatiom.setEasingCurve(QEasingCurve::OutBounce);
 //   animatiom.setKeyValueAt(0,QRect(0,0,100,30));
 //   animatiom.setKeyValueAt(0.8,QRect(250,250,200,60));
 //   animatiom.setKeyValueAt(1,QRect(0,0,100,30));
   //animatiom.start();

    QPropertyAnimation animatiom2(&button,"geometry");
    animatiom2.setDuration(1000);
    animatiom2.setStartValue(QRect(250,300,100,30));
    animatiom2.setEndValue(QRect(250,300,200,60));

    //串行动画
    QSequentialAnimationGroup group;
    group.addAnimation(&animatiom);
    group.addAnimation(&animatiom2);
    group.start();

}
