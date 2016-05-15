#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QGridLayout>
#include <QtCore>
#include <QGraphicsRectItem>
#include <QObject>
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
class game_scene;
}

class game_scene : public QWidget , public QGraphicsRectItem
{
    Q_OBJECT

public:
    explicit game_scene(QWidget *parent = 0);
    ~game_scene();
    QLabel *BackGround;
    QString BackGround_Path;
    void flying();
    void flying_king();
    void keyPressEvent(QKeyEvent *event);
    void frame_show();
    void score_LCD();

public slots:
    void on_time_linkActivated();
    void on_fr_restart_clicked();
    void on_fr_exit_clicked();
    void on_test_ball_hit_clicked();

private slots:
    void on_test_king_ball_hit_clicked();

private:
    Ui::game_scene *ui;
    QTimer *timer = new QTimer(this);
    int time;
    int score;
    int final_score;
};

#endif // GAME_SCENE_H1
