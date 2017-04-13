#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QTextEdit>
#include <QClipboard>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMenuBar *menu_bar;

    QMenu *menu_file;

    QAction *action_new;
    QAction *action_open;
    QAction *action_save;
    QAction *action_close;

    QMenu *menu_edit;

    QAction *action_cut;
    QAction *action_copy;
    QAction *action_past;

    QWidget * widget;
    QTextEdit * text_edit;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void actionOpenCklicked();
    void actionSaveCklicked();
    void actionCloseCklicked();
    void actionCutCklicked();
    void actionPastCklicked();
    void actionCopyCklicked();
};

#endif // MAINWINDOW_H
