#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCryptographicHash>
#include <QHash>
#include <QPair>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btn_open_clicked();

    void on_btn_calc_clicked();

private:
    QString getHash(const QByteArray &data);
    QCryptographicHash::Algorithm getAlgorythm();

private:
    using IntPairHash = QHash<int, QPair<QCryptographicHash::Algorithm,QString>>;

    Ui::MainWindow *ui;

    IntPairHash m_algorythms;
};

#endif // MAINWINDOW_H
