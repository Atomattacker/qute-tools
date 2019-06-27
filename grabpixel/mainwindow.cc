#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QScreen>
#include <QWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    QColor color(img.pixel(e->globalPos()));
    QPalette p = ui->frame->palette();
    p.setColor(QPalette::Window, color);
    ui->frame->setPalette(p);

    ui->le_hex->setText(QString("%1%2%3")
                            .arg(color.red(), 2, 16)
                            .arg(color.red(), 2, 16)
                            .arg(color.green(), 2, 16)
                            .toUpper());
    ui->le_rgb_r->setText(QString::number(color.red()));
    ui->le_rgb_g->setText(QString::number(color.green()));
    ui->le_rgb_b->setText(QString::number(color.blue()));
}

void MainWindow::mousePressEvent(QMouseEvent *e) {

    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle()) screen = window->screen();
    if (!screen) return;
    QPixmap p = screen->grabWindow(0);
    img = p.toImage();
}

// void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
//    qDebug() << "Mouse Released";
//}
