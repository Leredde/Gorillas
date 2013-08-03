#include "buildingwindow.h"

BuildingWindow::BuildingWindow()
{
    _lightOn = (bool)(qrand()%2);
    _color = QColor(qrand()%256,qrand()%256,qrand()%256);
}

void BuildingWindow::draw(GLfloat pWidth, GLfloat pHeight)
{
    GLubyte lTopRed;
    GLubyte lTopGreen;
    GLubyte lTopBlue;
    GLubyte lBottomRed;
    GLubyte lBottomGreen;
    GLubyte lBottomBlue;

    if(_lightOn)
    {
        lTopRed = 254;
        lTopGreen = 250;
        lTopBlue = 200;

        lTopRed = lTopRed-(_color.red()/8);
        lTopGreen = lTopGreen-(_color.green()/8);
        lTopBlue = lTopBlue-(_color.blue()/8);

        lBottomRed = lTopRed - 1;
        lBottomGreen = lTopGreen - 1;
        lBottomBlue = lTopBlue - 1;

    }
    else
    {
        lTopRed = 3;
        lTopGreen = 4;
        lTopBlue = 10;

        lBottomRed = lTopRed + 10;
        lBottomGreen = lTopGreen + 10;
        lBottomBlue = lTopBlue + 10;
    }

    glBegin(GL_QUADS);
    glColor3ub(lTopRed,lTopGreen,lTopBlue);
    glVertex3f(pWidth,pHeight,0);
    glVertex3f(0,pHeight,0);

    glColor3ub(lBottomRed,lBottomGreen,lBottomBlue);
    glVertex3f(0,0,0);
    glVertex3f(pWidth,0,0);
    glEnd();
}

