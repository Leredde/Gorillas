#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QtDeclarative>
#include <QtEvents>
#include <QTimer>
#include "graphicalengine.h"
#include "graphicalengine2.h"


#define FRAMES_PER_SECOND 60

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *pKeyEvent);

public slots:
    void gameStarted();
    void gameQuit();
    void timeOutSlot();

private:
    QObject *qmlObject;
    QDeclarativeView *_ui;
    GraphicalEngine *_engine;
    QGraphicsScene *_scene;
    QGraphicsView *_view;
    BananaLaunchDialog *_bananaLaunchDialog;

    QTimer *_timer;
    bool _isDialogTime;
    bool _isGLPainted;


    void _startGame();
    void _toggleFullScreen();
};

#endif // GAMEWINDOW_H
