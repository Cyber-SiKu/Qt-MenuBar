#include "mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QTextEdit>
#include <QTextStream>
#include <QApplication>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{    
    menu_bar = new QMenuBar();
    this->setMenuBar(menu_bar);

    menu_file = new QMenu();
    menu_file->setTitle(tr("File"));
    menu_bar->addMenu(menu_file);

    action_new = new QAction();
    action_new->setText(tr("New"));
    menu_file->addAction(action_new);

    action_open = new QAction();
    action_open->setText(tr("Open"));
    menu_file->addAction(action_open);
    connect(action_open,SIGNAL(triggered()),this,SLOT(actionOpenCklicked()));

    action_save = new QAction();
    action_save->setText(tr("save"));
    menu_file->addAction(action_save);
    connect(action_save,SIGNAL(triggered()),this,SLOT(actionSaveCklicked()));

    action_close = new QAction();
    action_close->setText(tr("close"));
    menu_file->addAction(action_close);
    connect(action_close,SIGNAL(triggered()),this,SLOT(actionCloseCklicked()));


    menu_edit= new QMenu();
    menu_edit->setTitle(tr("Edit"));
    menu_bar->addMenu(menu_edit);

    action_cut = new QAction();
    action_cut->setText(tr("cut"));
    menu_edit->addAction(action_cut);
    connect(action_cut,SIGNAL(triggered()),this,SLOT(actionCutCklicked()));

    action_copy = new QAction();
    action_copy->setText(tr("copy"));
    menu_edit->addAction(action_copy);
    connect(action_copy,SIGNAL(triggered()),this,SLOT(actionCopyCklicked()));

    action_past = new QAction();
    action_past->setText(tr("Past"));
    menu_edit->addAction(action_past);
    connect(action_past,SIGNAL(triggered()),this,SLOT(actionPastCklicked()));

    text_edit = new QTextEdit();

    widget = new QWidget();

    text_edit->setParent(widget);

    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{

}

void MainWindow::actionOpenCklicked(){
    QFile * file = new QFile();
    file->setFileName(QFileDialog::getOpenFileName(this,tr("open file"),"/home/siku/Documents/"));
    if (file->open(QIODevice::ReadOnly)){
        QTextStream in(file);
        text_edit->setText(in.readAll());
    }else{
        qDebug()<<"open file failure";
    }
    file->close();
}

void MainWindow::actionSaveCklicked()
{
    QFile * file = new QFile();
    file->setFileName(QFileDialog::getOpenFileName(this,tr("open file"),"/home/siku/Documents/"));
    if (file->open(QIODevice::WriteOnly)){
        QTextStream out(file);
        out<<text_edit->toPlainText();
    }else{
        qDebug()<<"open file failure";
    }
    file->close();
}

void MainWindow::actionCloseCklicked()
{
    this->close();
}

void MainWindow::actionCutCklicked()
{
    text_edit->cut();
    QClipboard *clipboard = QApplication::clipboard();
    QString str = clipboard->text();
    qDebug() << str;
}

void MainWindow::actionPastCklicked()
{
    text_edit->paste();
    QClipboard *clipboard = QApplication::clipboard();
    QString str = clipboard->text();
    qDebug() << str;
}

void MainWindow::actionCopyCklicked()
{
    text_edit->copy();
    QClipboard *clipboard = QApplication::clipboard();
    QString str = clipboard->text();
    qDebug() << str;
}
