#include "building.h"

Building::Building(GLfloat pWidth)
{
    GLfloat lHeight;
    GLfloat lWidth;

    _width = pWidth;
    _height = (((GLfloat)(qrand()%80))/100.0)+0.25;
    _color = QColor(qrand()%30,qrand()%30,qrand()%30);

    lHeight = (((GLfloat)(qrand()%100))/100.0);
    lWidth = (((GLfloat)(qrand()%100))/100.0);

    _windowHeight = WINDOW_HEIGHT + lHeight*WINDOW_HEIGHT;
    _windowWidth = WINDOW_WIDTH + lWidth*WINDOW_WIDTH;

    _windowTopMargin = WINDOW_TOP_MARGIN + _windowHeight*WINDOW_TOP_MARGIN/2.0;
    _windowBottomMargin = WINDOW_BOTTOM_MARGIN + _windowHeight*WINDOW_BOTTOM_MARGIN/2.0;
    _windowLeftMargin = WINDOW_LEFT_MARGIN + _windowWidth*WINDOW_LEFT_MARGIN/2.0;
    _windowRightMargin = WINDOW_RIGHT_MARGIN + _windowWidth*WINDOW_RIGHT_MARGIN/2.0;

    _nbFloors = (_height - (BUILDING_INNER_BOTTOM_MARGIN + BUILDING_INNER_TOP_MARGIN)) /(_windowHeight + _windowTopMargin + _windowBottomMargin);
    _nbWindowsPerFloor = (_width - (BUILDING_INNER_RIGHT_MARGIN + BUILDING_INNER_LEFT_MARGIN)) / (_windowWidth + _windowRightMargin + _windowLeftMargin);
    _windowShift = (_width - (BUILDING_INNER_RIGHT_MARGIN + BUILDING_INNER_LEFT_MARGIN)) - (_nbWindowsPerFloor * (_windowWidth + _windowRightMargin + _windowLeftMargin));
    _windowShift /= 2.0;

    for(int i=0; i<_nbFloors*_nbWindowsPerFloor; i++)
    {
        _windows.append(new BuildingWindow());
    }
}

void Building::draw()
{
    // Top of the building
    glBegin(GL_QUADS);
    glColor3ub(70+_color.red(),70+_color.green(),70+_color.blue());
    glVertex3f(_width,_height,0);
    glVertex3f(0,_height,0);

    // Bottom of the building
    glColor3ub(20+_color.red(),20+_color.green(),20+_color.blue());
    glVertex3f(0,0,0);
    glVertex3f(_width,0,0);
    glEnd();

    // TODO check if it fits the building or floor the result

    // Draw windows for current building
    _drawWindows();
}

GLfloat Building::getHeight()
{
    return _height;
}

void Building::_drawWindows()
{

    glPushMatrix();
    glTranslatef(BUILDING_INNER_LEFT_MARGIN + _windowLeftMargin + _windowShift,
                 BUILDING_INNER_BOTTOM_MARGIN + _windowBottomMargin, 0);

    for(int i=0; i<_nbFloors; i++)
    {
        glPushMatrix();

        // Draw windows for ith floor
        for(int j=0; j<_nbWindowsPerFloor; j++)
        {
            _windows[i*_nbWindowsPerFloor+j]->draw(_windowWidth, _windowHeight);
            glTranslatef(_windowWidth + _windowLeftMargin + _windowRightMargin, 0, 0);
        }
        glPopMatrix();
        glTranslatef(0, _windowHeight + _windowTopMargin + _windowBottomMargin, 0);
    }
    glPopMatrix();
}
