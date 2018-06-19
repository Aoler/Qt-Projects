#ifndef UUTVIEW_H
#define UUTVIEW_H

#include <QWidget>

namespace Ui {
class UUTView;
}

class UUTView : public QWidget
{
    Q_OBJECT

public:
    explicit UUTView(QWidget *parent = 0);
    ~UUTView();

private:
    Ui::UUTView *ui;
};

#endif // UUTVIEW_H
