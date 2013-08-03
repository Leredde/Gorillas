#include "banana.h"

#include <QtCore/qmath.h>

Banana::Banana(float pSize, GLuint *pGlTextures, int pGlTextureIndex)
{
    _size = pSize;
    _textures = pGlTextures;
    _textureIndex = pGlTextureIndex;
    _isVisible = false;
    _x = 0.0;
    _y = 0.0;
    _velocity = 1.0;
    _angle = 0.0;
    _rotation = 0.0;
}

void Banana::setPosition(float pX, float pY)
{
    _x = pX;
    _y = pY;
}

void Banana::setVelocity(float pVelocity)
{
    _velocity = pVelocity;
}

void Banana::setAngle(float pAngle)
{
    _angle = pAngle;
}

void Banana::nextPosition(int pTimeDelta)
{
    _x = _x + (_velocity/pTimeDelta) * qAcos(_angle);
    _y = _y + (_velocity/pTimeDelta) * qAsin(_angle);
    _rotation = _rotation + _velocity * 0.1;
}

void Banana::show()
{
    _isVisible = true;
}

void Banana::hide()
{
    _isVisible = false;
}

void Banana::draw()
{
    _draw(_x,_y,_rotation);
}

void Banana::_draw(GLfloat pX, GLfloat pY, GLfloat pRotation)
{
    if(_textures != NULL && _isVisible)
    {
        glPushMatrix();
        glLoadIdentity();
        glRotatef(pRotation,0,0,1.0);
        glTranslatef(pX-_size/2.0, pY-_size/2.0, -4.0);
        glBindTexture(GL_TEXTURE_2D, _textures[_textureIndex]);
        glBegin(GL_QUADS);
        glColor4ub(255,255,255,255);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(_size,_size,0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0,_size,0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0,0,0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(_size,0,0);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
        glPopMatrix();
    }
}
