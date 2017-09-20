#include "mainwindow.h"
#include <QAction>
#include <QStatusBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    fileName="";
    setWindowTitle("NoteBook");
    setFixedSize(640,480);
    QAction* build_file = new QAction(QIcon("newfile.png"), "New file ",this);
    build_file->setShortcut(QKeySequence("Ctrl+n"));
    QAction* open_file = new QAction(QIcon("openfile.png"), "Open Files",this);
    open_file->setShortcut(QKeySequence("Ctrl+o"));
    QAction* save_file = new QAction(QIcon("save.png"), "Save All",this);
    save_file->setShortcut(QKeySequence("Ctrl+s"));
    QAction* saveas_file = new QAction(QIcon("saveas.png"), "Save As",this);
    saveas_file->setShortcut(QKeySequence("Ctrl+a"));
    QAction* delete_file = new QAction(QIcon("delete.png"), "Delete Current",this);
    delete_file->setShortcut(QKeySequence("Ctrl+d"));


    file_New = menuBar()->addMenu("File");
    file_Edit = menuBar()->addMenu("Help");

    file_New->addAction(build_file);
    file_New->addAction(open_file);
    file_New->addAction(save_file);
    file_New->addAction(saveas_file);
    file_New->addAction(delete_file);

    tbar = addToolBar("file");
    tbar->addAction(build_file);
    tbar->addAction(open_file);
    tbar->addAction(save_file);
    tbar->addAction(saveas_file);
    tbar->addAction(delete_file);

    tdt = new QTextEdit(this);
    setCentralWidget(tdt);
    tdt->setEnabled(true);

    lab1 = new QLabel("status:");
    lab2 =new QLabel("line:");
    lab3 = new QLabel;
    lab3->setMinimumWidth(300);

    statusBar()->addWidget(lab1);
    statusBar()->addWidget(lab3);
    statusBar()->addWidget(lab2);

    connect(build_file,SIGNAL(triggered(bool)),this,SLOT(File_build()));
    connect(open_file,SIGNAL(triggered(bool)),this,SLOT(File_open()));
    connect(save_file,SIGNAL(triggered(bool)),this,SLOT(File_save()));
    connect(saveas_file,SIGNAL(triggered(bool)),this,SLOT(File_saveas()));
    connect(delete_file,SIGNAL(triggered(bool)),this,SLOT(File_delete()));

}

void MainWindow::File_build(){
    /*QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/home/jana/untitled.png",
                               tr("Images (*.png *.xpm *.jpg)"))
            "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"*/
    fileName = QFileDialog::getSaveFileName(this,"build file","./","Text files (*.txt)");
    QFile myfile(fileName);
    if(myfile.open(QIODevice::WriteOnly)==false){
        lab1->setText("status: build fault");
    }
    lab1->setText("status: build success");
    myfile.write(tdt->toPlainText().toStdString().c_str());
    myfile.close();
}

void MainWindow::File_open(){
    fileName = QFileDialog::getOpenFileName(this,"select file","./","");
    //tdt->insertPlainText(fileName);
    QFile myfile(fileName);
    if(myfile.open(QIODevice::ReadWrite)==false){
        lab1->setText("status: open fault");
    }
    lab1->setText("status: open success");
    //lab2->setText(QString::number(QTextDocument::lineCount() const));
#if 1
    QByteArray data = myfile.readAll();
    QString str;
    str.append(data);
    tdt->insertPlainText(str);
#else
    tdt->insertPlainText(myfile.readAll().toStdString().c_str());
#endif
    myfile.close();
}

void MainWindow::File_save(){
    if(fileName==""){
        File_build();
        lab1->setText("status: save success");
        return;
    }

    QFile myfile(fileName);
    if(myfile.open(QIODevice::WriteOnly)==false){
        lab1->setText("status: save fault");
    }
    lab1->setText("status: save success");
    myfile.write(tdt->toPlainText().toStdString().c_str());
    myfile.close();
}

void MainWindow::File_saveas(){
    fileName = QFileDialog::getSaveFileName(this);
    File_save();
}

void MainWindow::File_delete(){
    tdt->clear();
}

MainWindow::~MainWindow()
{

}
