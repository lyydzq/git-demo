#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QLabel>
#include <QDebug>
#include  "form.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initbutton();
    this->setAttribute(Qt::WA_DeleteOnClose);
    Form *form=new Form();

//    connect(form,SIGNAL(sigEndScreenShared()),this,SLOT(showwin()));

    //_pPushButtonClose->setStyleSheet("background-color: rgba(0, 0, 0, 0)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showwin()
{
    this->show();
    qDebug()<<"5632906题ty834ew9pgt8i0dvhdf ";
}

void MainWindow::initbutton()
{
    ui->start_shared->setStyleSheet("background: rgb(0,255,0)");
    ui->start_shared->setStyleSheet("color:rgb(200, 255, 255);}");
    //   ui->start_shared->setFlat(true);
    //     ui->start_shared->setStyleSheet( "QPushButton{background:rgba(0,0,0,0);border:1px; solid; rgba(0,0,0,0);}");
    QIcon icon(":/icon/320.png");
    ui->start_shared->setIcon(icon);
    QIcon icon_stop(":/icon/780.jpg");
    ui->stop_shared->setIcon(icon_stop);
    ui->stop_shared->setStyleSheet("color:white");
}


void MainWindow::on_start_shared_clicked()
{
    this->hide();
    screenSharedView=new Form();
    screenSharedView->show();
}

