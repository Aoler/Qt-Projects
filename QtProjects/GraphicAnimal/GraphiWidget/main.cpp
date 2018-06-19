#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    QTextEdit * edit = new QTextEdit;
    QPushButton * button = new QPushButton("clear");
    QObject::connect(button,SIGNAL(clicked()),edit,SLOT(clear()));

    QGraphicsWidget *textEdit = scene.addWidget(edit);
    QGraphicsWidget * pushButton = scene.addWidget(button);
    pushButton->setFlag(QGraphicsItem::ItemIsMovable);

    QGraphicsLinearLayout * layout = new QGraphicsLinearLayout;
    layout->addItem(textEdit);
    layout->addItem(pushButton);

    QGraphicsWidget * form = new QGraphicsWidget;
    form->setWindowTitle("Widget Item");
    form->setLayout(layout);

    scene.addItem(form);
    QGraphicsView view(&scene);
    view.show();
    return a.exec();
}
