#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QToolButton>
#include<QSpinBox>
#include<QTextEdit>
#include<QMdiSubWindow>
#include<QPalette>
#include<QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *edit=ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction *set=edit->addAction(QIcon(":/myImages/images/new.png"),tr("打开文件"));
    ui->mainToolBar->addAction(set);

    QActionGroup *group=new QActionGroup(this);
    QAction *actionL=group->addAction(tr("左对齐(&L)"));
    actionL->setCheckable(true);
    QAction *actionC=group->addAction(tr("居中(&C)"));
    actionC->setCheckable(true);
    QAction *actionR=group->addAction(tr("右对齐(&R)"));
    actionR->setCheckable(true);

    actionL->setChecked(true);
    edit->addSeparator();
    edit->addAction(actionL);
    edit->addAction(actionC);
    edit->addAction(actionR);

    ui->mainToolBar->addAction(actionL);
    ui->mainToolBar->addAction(actionC);
    ui->mainToolBar->addAction(actionR);

    QToolButton *toolButton=new QToolButton(this);
    toolButton->setText(tr("颜色"));
    QMenu *colorMenu=new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolButton->setMenu(colorMenu);
    toolButton->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(toolButton);

    QSpinBox *spinBox=new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);

    ui->statusBar->showMessage(tr("欢迎使用多文档编辑器"),2000);
    QLabel *permanent=new QLabel(this);
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText("haitao.yu");
    ui->statusBar->addPermanentWidget(permanent);

    QPalette palette1=ui->pushButton->palette();
    palette1.setColor(QPalette::ButtonText,Qt::red);
    palette1.setColor(QPalette::Button,Qt::green);
    ui->pushButton->setPalette(palette1);

    //ui->lineEdit->setDisabled(true);

    QList<QPair<QString, QString> > dataList;
    dataList.append(QPair<QString,QString>("hello","haitao"));
    dataList.append(QPair<QString,QString>("lllll","yu"));
    //TableModel model(dataList);
    model=new TableModel(dataList);
    ui->tableView->setModel(model);

    QStringList list;
    list<<"A"<<"B"<<"C";
    modelList =new StringListMode(list);
    ui->listView->setModel(modelList);


    QFile file(":/myImages/qss/white.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_triggered()
{
    /*
    QTextEdit *edit=new QTextEdit(this);
    QMdiSubWindow *child=ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();
    */
}
