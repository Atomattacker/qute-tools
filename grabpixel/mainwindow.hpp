#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *e);
    // void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    QImage img;
};

#endif // MAINWINDOW_HPP
