#include "gamewindow.h"
#include "gorillascene.h"
#include <QtCore>
#include <QtGui>
#include <QtOpenGL>

/*
 * METHODS
 *
 */
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Set up the QML.
    _ui = new QDeclarativeView(QUrl("qml/Gorillas/main.qml"), this);
    setCentralWidget(_ui);
    _ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    qmlObject = _ui->rootObject();

    _engine = new GraphicalEngine(this);
    _engine->hide();
    _bananaLaunchDialog = new BananaLaunchDialog(this);
    _bananaLaunchDialog->hide();

    // Connect
    connect(qmlObject, SIGNAL(gameStarted()), this, SLOT(gameStarted()));
    connect(qmlObject, SIGNAL(gameQuit()), this, SLOT(gameQuit()));



/*

    _isDialogTime = false;
    _isGLPainted = false;

    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
    */
}

void GameWindow::keyPressEvent(QKeyEvent *pKeyEvent)
{
    switch(pKeyEvent->key())
    {
    case Qt::Key_Escape:
        gameQuit();
        break;
    case Qt::Key_Return:
        break;
    case Qt::Key_F1:
        _toggleFullScreen();
        break;
    }
}


/*
 * SLOTS
 *
 */
void GameWindow::gameStarted()
{
    //Start OpenGL
    _startGame();
    /*_scene = new GorillaScene(this, new GraphicalEngine2);
    _scene->addWidget(_bananaLaunchDialog);
    _view = new QGraphicsView(this);
    _view->setViewport(new QGLWidget(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer)));
    _view->setScene(_scene);
    _view->setGeometry(QRect(0, 0, this->width(), this->height()));
    */
    /*_bananaLaunchDialog->show();
    _bananaLaunchDialog->setFixedHeight(200);
    _bananaLaunchDialog->setFixedWidth(400);
    */
    //_view->show();
    _ui->hide();
    //this->setCentralWidget(_view);

    // Init frame timer
    /*
    int lSeconde = 1000; // 1 seconde = 1000 ms
    int lTimerInterval = lSeconde / FRAMES_PER_SECOND;
    _timer->start( lTimerInterval );
    */
}

void GameWindow::gameQuit()
{
    //Close game
    delete _bananaLaunchDialog;
    delete _engine;

    close();
}


/*
 * PRIVATE FUNCTIONS
 *
 */
void GameWindow::_startGame()
{
    //_engine->showFullScreen();
    this->setCentralWidget(_engine);
    _engine->show();
    _engine->start();

    //_bananaLaunchDialog->setGeometry(this->width()/2-200, 10, 400, 200);
    _bananaLaunchDialog->setBaseSize(400,200);

    _bananaLaunchDialog->show();
    /*_bananaLaunchDialog->setFixedHeight(200);
    _bananaLaunchDialog->setFixedWidth(400);
    _bananaLaunchDialog->show();*/
    //this->hide();
}

void GameWindow::_toggleFullScreen()
{
    if(isFullScreen())
    {
        showNormal();
    }
    else
    {
        showFullScreen();
    }
}

void GameWindow::timeOutSlot()
{
    if (!_bananaLaunchDialog->isVisible())
    {
        if(_isDialogTime && _isGLPainted)
        {
            _bananaLaunchDialog->show();
            _isDialogTime = false;
        }
        else
        {
            _scene->update(this->rect());
            _isGLPainted = true;
        }
    }
}
