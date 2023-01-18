#include "form.h"
#include "ui_form.h"
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QStyleOption>
#include <QBitmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QTime>
#include <QPushButton>
#include <QApplication>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlag(Qt::FramelessWindowHint);
    QDesktopWidget *screenResolution = QApplication::desktop();
    int appWindowWidth = this->geometry().width()+400;
    int appWindowHeight = this->geometry().height();
    this->setStyleSheet("background-color:rgba(0,0,0,0.7)");

    int center_y = screenResolution->height()/2 - appWindowHeight/2;
    int center_x = screenResolution->width()/2 - appWindowWidth/2;
    //此处的Width,Height不要被修改了(例如除以2了)
    //不然看起来不是居中的
    setGeometry(center_x, 0,
                appWindowWidth,appWindowHeight);
//    this->setFixedSize(appWindowWidth,appWindowHeight);
    timeRecord=new QTime(0,0,0);
    initScreenSharedTitleView();

}

Form::~Form()
{
    delete ui;
}

void Form::mouseMoveEvent(QMouseEvent *event)
{
//    QWidget::mouseMoveEvent(event);
//    QPoint y= event->globalPos();
//    QPoint x=y-z;

//        QWidget::mouseMoveEvent(event);
//        QPoint y= event->globalPos();
//        QPoint x=y-z;
//        QPoint x1=x-QPoint(0,z.ry());
//        this->move(x);

//        qDebug()<<"x=:"<<x;
//         qDebug()<<"y=:"<<x;
//          qDebug()<<"z=:"<<x;


    if(event->buttons()==Qt::LeftButton)
    {
        QPoint endpos=event->globalPos();
        move(endpos-m_0ffset);
    }
        QWidget::mouseMoveEvent(event);

}

void Form::mousePressEvent(QMouseEvent *event)
{
//    QWidget::mousePressEvent(event);
//       QPoint x=this->geometry().topLeft();
//       QPoint y=event->globalPos();
//       this->z=y-x;
    if(event->buttons()==Qt::LeftButton)
    {
        QPoint startpoint=event->globalPos();
        m_0ffset=startpoint-geometry().topLeft();
        qDebug()<<startpoint<<":"<<m_0ffset;
    }
        QWidget::mousePressEvent(event);
}

void Form::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    //    this->z=QPoint();
}

void Form::paintEvent(QPaintEvent *painter)
{
//     QStyleOption opt;
//     opt.initFrom(this);
//     QPainter p(this);
//     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);//绘制样式

//     QBitmap bmp(this->size());
//     bmp.fill();
//     QPainter painter(&bmp);
//     painter.setPen(Qt::NoPen);
//     painter.setBrush(Qt::black);
//     painter.setRenderHint(QPainter::Antialiasing);
//     painter.drawRoundedRect(bmp.rect(), 12, 12);
//     setMask(bmp);


     QBitmap bmp(this->size());
     bmp.fill();
     QPainter p(&bmp);
     p.setPen(Qt::NoPen);
     p.setBrush(Qt::black);
     p.drawRoundedRect(bmp.rect(),8,8);  //10表示圆角大小this->setMask(bmp);
     this->setMask(bmp);
//     qDebug()<<"++++++++++++++++++++++++++";
}

void Form::initScreenSharedTitleView()
{

    QPushButton *endScreenShared=new QPushButton("结束共享",this);
    endScreenShared->setGeometry(580,20,108,34);
    endScreenShared->setStyleSheet("background-color: rgb(241,68,68);border-radius:6px;color:white;QPushButton:hover{background-color: rgb(20, 62, 134)}");
   //endScreenShared->setStyleSheet("{color:rgb(255, 255, 255);}""QPushButton:hover{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}""QPushButton:checked{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}");


    connect(endScreenShared,&QPushButton::clicked,this,[=]
    {
        this->close();
        emit sigEndScreenShared();
    });
    QPushButton *allSelect = new QPushButton;
    allSelect->setStyleSheet("QPushButton{border-image: url(:/1.png) 0 0 0 0;border:none;color:rgb(255, 255, 255);}""QPushButton:hover{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}""QPushButton:checked{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}");


    QLabel *dragLabel=new QLabel(this);
    dragLabel->setGeometry(0,0,40,this->height());
    dragLabel->setPixmap(QPixmap(":/icon/xED0X5MHZ2.jpg"));
    dragLabel->setScaledContents(true);
    dragLabel->setCursor(Qt::CrossCursor);
//    label->setText("生活");
//    label->show();

    QLabel *videoRecordLabel=new QLabel(this);
    videoRecordLabel->setGeometry(460,22,64,22);
//    videoRecordLabel->adjustSize();
    videoRecordLabel->setStyleSheet("color:white");
    videoRecordLabel->setScaledContents(true);

//    videoRecordLabel->setText("DIAOZHIQIAN");

    qDebug()<<this->width()<<"++"<<this->height();
     timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,[=]

    {
//        timeRecord.setHMS(0,0,0);
        *timeRecord=timeRecord->addSecs(1);
        videoRecordLabel->setText(timeRecord->toString("hh:mm:ss"));
    });
    timer->start(1000);

}
