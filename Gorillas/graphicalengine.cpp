#include "graphicalengine.h"
#include <QTime>
#include <QKeyEvent>
#include <QDialog>

GraphicalEngine::GraphicalEngine(QWidget *parent, float pBuildingWidth, int pNbBuildings) :
    QGLWidget(parent)
{
    setWindowTitle("Gorillas");
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
    setAutoBufferSwap(false);

    _buildingWidth = pBuildingWidth;

    if(pNbBuildings > MAX_NB_BUILDINGS)
    {
        _nbBuildings = MAX_NB_BUILDINGS;
    }
    else
    {
        _nbBuildings = pNbBuildings;
    }

    qsrand(QDateTime::currentDateTime ().toTime_t());
    for(int i=0; i<_nbBuildings; i++)
    {
        _buildings[i] = new Building(pBuildingWidth);
    }

    _player1Name = "PLAYER1";
    _player2Name = "PLAYER2";

    _isFullScreen = this->isFullScreen();

    _bananaLaunchDialog = new BananaLaunchDialog(this);
    _bananaLaunchDialog->hide();
    _bananaLaunchDialog->setFixedSize(200,100);

    // Init frame timer
    int lSeconde = 1000; // 1 seconde = 1000 ms
    int lTimerInterval = lSeconde / FRAMES_PER_SECOND;
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
    _timer->start( lTimerInterval );

    _isDialogTime = false;
    _isGLPainted = false;
}
/*
void GraphicalEngine::keyPressEvent(QKeyEvent *pKeyEvent)
{

    switch(pKeyEvent->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_Return:
        break;
    case Qt::Key_F1:
        _toggleFullScreen();
        break;
    }
}
*/

void GraphicalEngine::timeOutSlot()
{
    if (!_bananaLaunchDialog->isVisible())
    {
        if(_isDialogTime && _isGLPainted)
        {
           // _bananaLaunchDialog->show();
            _isDialogTime = false;
        }
        else
        {
            updateGL();
            _isGLPainted = true;
        }
    }
}

void GraphicalEngine::initializeGL()
{
    qglClearColor(Qt::blue);
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glShadeModel(GL_SMOOTH);
    //glEnable(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    //glDepthFunc(GL_LEQUAL);
    //glDepthFunc(GL_ALWAYS);

    // no need here but could be useful in 3D context
    // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glGenTextures(NB_TEXTURES, _textures);
    _loadTexture("textures/gorilla_norm_texture.png",0);
    _loadTexture("textures/gorilla_left_texture.png",1);
    _loadTexture("textures/gorilla_right_texture.png",2);
    _loadTexture("textures/banana_texture.png",3);
    glEnable(GL_TEXTURE_2D);

    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_NOTEQUAL,0.0f);

    _banana = new Banana(0.08, _textures, 3);
    _banana->show();
}

void GraphicalEngine::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat x = GLfloat(width) / height;
    glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GraphicalEngine::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    _drawSkyline(); // problem here the buildings won't draw without the gorillas.
    _drawGorillas();
    _banana->draw();

    swapBuffers();
}

void GraphicalEngine::_drawTest()
{
    GLfloat x = 1;
    glBegin(GL_QUADS);
    glColor3ub(255,50,50);
    glVertex3f(x,x,0);
    glVertex3f(-x,x,0);
    glVertex3f(-x,-x,0);
    glVertex3f(x,-x,0);
    glEnd();
}

void GraphicalEngine::_drawSkyline()
{
    GLfloat skyline_width = _nbBuildings*_buildingWidth;
    GLfloat scene_start = -(skyline_width/2.0);

    // TODO check if it fits the building or floor the result : if(nb_windows_per_floor...

    glPushMatrix();
    // Origin to the left of the scene
    glTranslatef(scene_start, -1, -4.0);

    // Draw buildings
    for(int i= 0; i<_nbBuildings; i++)
    {
        _buildings[i]->draw();

        // Move origin at building right side
        glTranslatef(_buildingWidth, 0, 0);
    }
    glPopMatrix();
}

void GraphicalEngine::_drawGorillas()
{
    GLfloat lGorillaSize = 0.1;

    GLfloat lSkylineWidth = _nbBuildings*_buildingWidth;
    GLfloat lSceneStart = -(lSkylineWidth/2.0);

    glPushMatrix();
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    // Left Gorilla
    glTranslatef(lSceneStart-lGorillaSize/2.0+_buildingWidth/2.0, -1+_buildings[0]->getHeight(), -4.0);

    glBindTexture(GL_TEXTURE_2D, _textures[0]);

    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(lGorillaSize,lGorillaSize,0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0,lGorillaSize,0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0,0,0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(lGorillaSize,0,0);
    glEnd();
    glLoadIdentity();

    // Right Gorilla
    lSceneStart = (lSkylineWidth/2.0);
    glTranslatef(lSceneStart-lGorillaSize/2.0-_buildingWidth/2.0, -1+_buildings[_nbBuildings-1]->getHeight(), -4.0);

    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(lGorillaSize,lGorillaSize,0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0,lGorillaSize,0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0,0,0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(lGorillaSize,0,0);
    glEnd();

    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLoadIdentity();
    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();
}

void GraphicalEngine::_drawBackground()
{
}

void GraphicalEngine::_drawSun()
{
}

void GraphicalEngine::_loadTexture(QString pTextureName, int pIndex)
{
    QImage lGorillaTextureTemp;
    QImage lGorillaTexture;

    lGorillaTextureTemp.load(pTextureName,"PNG");
    lGorillaTexture = convertToGLFormat(lGorillaTextureTemp);
    glBindTexture(GL_TEXTURE_2D,_textures[pIndex]);

    glTexImage2D(GL_TEXTURE_2D, 0, 4, lGorillaTexture.width(), lGorillaTexture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, lGorillaTexture.bits());
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
}

void GraphicalEngine::_toggleFullScreen()
{
    if(_isFullScreen)
    {
        showNormal();
        _isFullScreen = false;
    }
    else
    {
        showFullScreen();
        _isFullScreen = true;
    }

}

void GraphicalEngine::start()
{
   // _isDialogTime = true;
}
