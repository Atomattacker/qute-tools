#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>


static QString getMD5(const QByteArray &data)
{
    return QCryptographicHash::hash(data,QCryptographicHash::Md5).toHex();
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_open_clicked()
{
    ui->lineEdit->setText(QFileDialog::getOpenFileName(this,tr("open file")));
}

void MainWindow::on_btn_calc_clicked()
{
    QFileInfo fi(ui->lineEdit->text());
    if(fi.exists() && fi.isFile())
    {
        QFile file(fi.absoluteFilePath());
        if(file.open(QIODevice::ReadOnly))
        {
            ui->plainTextEdit->setPlainText(getMD5(file.readAll()));
            file.close();
        }
        else
        {
            QMessageBox::information(this,QString(),tr("open file failed!"));
        }
    }
    else
    {
        QMessageBox::information(this,QString(),tr("file is not exist"));
    }


}
