/**
  * @file mainwindow.h
  * @author Ignacio Morales
  * @brief App ceSearch
  * @version 1.1
  * @date 2021-06-24
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief realiza busqueda en libros y muestra el texto de los libros que corresponda
     */
    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

