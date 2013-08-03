#ifndef BUILDING_H
#define BUILDING_H

#include <QGLWidget>
#include "buildingwindow.h"

#define WINDOW_HEIGHT 0.015
#define WINDOW_TOP_MARGIN 0.005
#define WINDOW_BOTTOM_MARGIN 0.005
#define BUILDING_INNER_BOTTOM_MARGIN 0.01
#define BUILDING_INNER_TOP_MARGIN 0.01
#define WINDOW_WIDTH 0.01
#define WINDOW_RIGHT_MARGIN 0.0035
#define WINDOW_LEFT_MARGIN 0.0035
#define BUILDING_INNER_RIGHT_MARGIN 0.005
#define BUILDING_INNER_LEFT_MARGIN 0.005

class Building
{
public:
    Building(GLfloat pWidth);
    void draw();
    GLfloat getHeight();

private:
    QColor _color;
    GLfloat _height;
    GLfloat _width;
    GLfloat _buildingWidth;
    GLfloat _windowLeftMargin;
    GLfloat _windowRightMargin;
    GLfloat _windowTopMargin;
    GLfloat _windowBottomMargin;
    GLfloat _windowShift;
    GLint _nbFloors;
    GLint _nbWindowsPerFloor;

    QVector<BuildingWindow*> _windows;

    GLfloat _windowHeight;
    GLfloat _windowWidth;

    void _drawWindows();

};

#endif // BUILDING_H
