#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_algorythms.insert(0,qMakePair(QCryptographicHash::Algorithm::Md4,QString("MD4")));
    m_algorythms.insert(1,qMakePair(QCryptographicHash::Algorithm::Md5,QString("MD5")));
    m_algorythms.insert(2,qMakePair(QCryptographicHash::Algorithm::Sha1,QString("Sha1")));
    m_algorythms.insert(3,qMakePair(QCryptographicHash::Algorithm::Sha224,QString("Sha224")));
    m_algorythms.insert(4,qMakePair(QCryptographicHash::Algorithm::Sha256,QString("Sha256")));
    m_algorythms.insert(5,qMakePair(QCryptographicHash::Algorithm::Sha384,QString("Sha384")));
    m_algorythms.insert(6,qMakePair(QCryptographicHash::Algorithm::Sha512,QString("Sha512")));
    m_algorythms.insert(7,qMakePair(QCryptographicHash::Algorithm::Sha3_224,QString("Sha3_224")));
    m_algorythms.insert(8,qMakePair(QCryptographicHash::Algorithm::Sha3_256,QString("Sha3_256")));
    m_algorythms.insert(9,qMakePair(QCryptographicHash::Algorithm::Sha3_384,QString("Sha3_384")));
    m_algorythms.insert(10,qMakePair(QCryptographicHash::Algorithm::Sha3_512,QString("Sha3_512")));

    for(int i = 0; i< m_algorythms.count();++i)
    {
        ui->comboBox->addItem(QString());
    }

    for(IntPairHash::const_iterator it = m_algorythms.begin(); it != m_algorythms.end(); ++it)
    {
        ui->comboBox->setItemText(it.key(),it.value().second);
    }
    ui->comboBox->setCurrentIndex(0);

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
            ui->plainTextEdit->setPlainText(getHash(file.readAll()));
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

QString MainWindow::getHash(const QByteArray &data)
{
    return QCryptographicHash::hash(data,getAlgorythm()).toHex();
}

QCryptographicHash::Algorithm MainWindow::getAlgorythm()
{
    return m_algorythms[ui->comboBox->currentIndex()].first;
}
