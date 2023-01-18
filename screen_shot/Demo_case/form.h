#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPoint>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
signals:
    void sigEndScreenShared();
private:
    Ui::Form *ui;
protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *painter);



private:
//     QPoint begin_pos;
//     QPoint leftTopPos_pos;
//       QPoint z;
       QPoint m_0ffset;
       QTimer *timer;
       QTime *timeRecord;

private:
       void initScreenSharedTitleView();



};

#endif // FORM_H
