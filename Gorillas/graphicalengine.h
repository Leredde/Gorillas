#ifndef GORILLAENGINE_H
#define GORILLAENGINE_H

#include <QGLWidget>
#include <QImage>
#include <QTimer>
#include "building.h"
#include "banana.h"
#include "bananalaunchdialog.h"

#define FRAMES_PER_SECOND 60

#define MAX_NB_BUILDINGS 30
#define DEFAULT_NB_BUILDINGS 12
#define DEFAULT_BUILDING_WIDTH 0.28

#define NB_TEXTURES 4

class GraphicalEngine : public QGLWidget
{
    Q_OBJECT
public:
    explicit GraphicalEngine(QWidget *parent = 0, float pBuildingWidth = DEFAULT_BUILDING_WIDTH, int pNbBuildings = DEFAULT_NB_BUILDINGS);
    //void keyPressEvent(QKeyEvent *pKeyEvent);
    void start();
/*
    void drawSkyline();
    void drawGorillas();
    void drawBanana();
*/
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    QString _player1Name;
    QString _player2Name;
    GLint _nbBuildings;
    GLfloat _buildingWidth;
    Building *_buildings[MAX_NB_BUILDINGS];
    Banana *_banana;
    GLuint _textures[NB_TEXTURES];
    QTimer *_timer;

    BananaLaunchDialog *_bananaLaunchDialog;

    bool _isDialogTime;
    bool _isGLPainted;
    bool _isFullScreen;

    void _drawTest();
    void _drawSkyline();
    void _drawGorillas();
    void _drawBackground();
    void _drawSun();

    void _loadTexture(QString pTextureName, int pIndex);

    void _toggleFullScreen();

    void _game();

signals:

public slots:
    void timeOutSlot();

    
};

#endif // GORILLAENGINE_H
