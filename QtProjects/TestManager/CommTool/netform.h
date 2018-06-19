#ifndef NETFORM_H
#define NETFORM_H

#include <QWidget>

namespace Ui {
class NetForm;
}

class NetForm : public QWidget
{
    Q_OBJECT

public:
    explicit NetForm(QWidget *parent = 0);
    ~NetForm();

private:
    Ui::NetForm *ui;
};

#endif // NETFORM_H
