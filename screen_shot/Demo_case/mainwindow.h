#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showwin();
public:
    void initbutton();
private slots:
    void on_start_shared_clicked();

private:
    Ui::MainWindow *ui;
    Form *screenSharedView;

};
#endif // MAINWINDOW_H
