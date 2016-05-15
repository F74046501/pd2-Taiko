#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <game_scene.h>
#include "game_scene.h"
#include "ui_game_scene.h"
#include <QtCore>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsTextItem>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QWidget>
#include <QBrush>
#include <string>
#include <stdlib.h>
#include <QpropertyAnimation.h>
#include <typeinfo>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    game_scene *second;

public slots:
    void on_exit_button_clicked();
    void on_start_button_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *music = new QMediaPlayer();
};

#endif // MAINWINDOW_H
