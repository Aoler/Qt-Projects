#include <QApplication>
#include <QPushButton>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton button("state Machine");
    QStateMachine machine;
    QState * s1 = new QState(&machine);
    QState * s2 = new QState(&machine);
    QState * s3 = new QState(&machine);

    //切换状态时的属性样式
    s1->assignProperty(&button, "geometry", QRect(100,100,100,50));
    s2->assignProperty(&button, "geometry", QRect(300,100,100,50));
    s3->assignProperty(&button, "geometry", QRect(200,100,100,50));

    //状态切换时的动画
    QPropertyAnimation * animal = new QPropertyAnimation(&button, "geometry");
    animal->setDuration(2000);
    animal->setStartValue(QRect(0,0,100,30));
    animal->setEndValue(QRect(250,300,100,30));


    //状态切换
    QSignalTransition * transtion1 = s1->addTransition(&button,SIGNAL(clicked()),s2);
    QSignalTransition * transtion2 = s2->addTransition(&button,SIGNAL(clicked()),s3);
    QSignalTransition * transtion3 = s3->addTransition(&button,SIGNAL(clicked()),s1);

    transtion1->addAnimation(animal);
    transtion2->addAnimation(animal);
    transtion3->addAnimation(animal);

    //先执行动画，再执行属性样式

    machine.setInitialState(s1);
    machine.start();
    button.show();
    return a.exec();
}
