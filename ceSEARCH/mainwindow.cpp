#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QDir>
#include "iostream"
#include <ctype.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    setWindowTitle("ceSEARCH");
    qDebug() << QDir::currentPath();
    qDebug() << QDir::homePath();
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_searchButton_clicked()
{
    QString searchString(ui->searchText->text());
    QString dir = "files/file";
    //QFile file("files/file1.txt");


    QDir directory("files");
    QStringList fileList = directory.entryList(QStringList() << "*.txt" << "*.TXT", QDir::Files);
    foreach(QString filename, fileList){

        QFile file("files/" + filename);
        if (file.open(QIODevice::ReadOnly)) {

            QTextStream in(&file);

            while (!in.atEnd()){
                QString line = in.readLine();
                if(line.contains(searchString, Qt::CaseSensitive)) {
                    ui->results->appendPlainText("//////////////////");
                    in.seek(0);
                    QString text = in.readAll();
                    ui->results->appendPlainText(text);
                    break;
                }
            }
            file.close();
        }
    }
}

