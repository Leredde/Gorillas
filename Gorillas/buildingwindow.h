#ifndef BUILDINGWINDOW_H
#define BUILDINGWINDOW_H

#include <QGLWidget>

class BuildingWindow
{
public:
    BuildingWindow();
    void draw(GLfloat pWidth, GLfloat pHeight);

private:

    bool _lightOn;
    QColor _color;

};

#endif // BUILDINGWINDOW_H
