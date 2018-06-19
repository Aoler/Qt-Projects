#ifndef DETAILVIEW_H
#define DETAILVIEW_H

#include <QWidget>
#include "treemodel.h"

namespace Ui {
class DetailView;
}

class DetailView : public QWidget
{
    Q_OBJECT

public:
    explicit DetailView(QWidget *parent = 0);
    ~DetailView();
public:
    void GetData(QVector<QVariant> &headerData, QMap<QString,TreeGroupData> &treeGroupData);

private:
    Ui::DetailView *ui;
    TreeModel *model;
};

#endif // DETAILVIEW_H
