#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QTextEdit>
#include <QLabel>
#include <QDialog>
#include <QFileDialog>
#include <QIODevice>
#include <QFile>
#include <QTextDocument>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QMenu *file_New,*file_Edit;
    QToolBar* tbar;
    QTextEdit* tdt;
    QString fileName;
    QLabel *lab1,*lab2,*lab3;
private slots:
    void File_open();
    void File_save();
    void File_saveas();
    void File_build();
    void File_delete();

};

#endif // MAINWINDOW_H
