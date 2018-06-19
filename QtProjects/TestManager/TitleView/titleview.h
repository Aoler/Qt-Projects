#ifndef TITLEVIEW_H
#define TITLEVIEW_H

#include <QWidget>

namespace Ui {
class TitleView;
}

class TitleView : public QWidget
{
    Q_OBJECT
public:
    explicit TitleView(QWidget *parent = 0);
    ~TitleView();


private:
    Ui::TitleView *ui;
};

#endif // TITLEVIEW_H
