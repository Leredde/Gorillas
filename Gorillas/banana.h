#ifndef BANANA_H
#define BANANA_H

#include <QGLWidget>

class Banana
{
public:
    Banana(float pSize, GLuint *pGlTextures=NULL, int pGlTextureIndex=0);
    void setPosition(float pX, float pY);
    void setVelocity(float pVelocity);
    void setAngle(float pAngle);
    void nextPosition(int pTimeDelta);
    void show();
    void hide();
    void draw();

private:
    float _x;
    float _y;
    float _size;
    float _rotation;
    float _angle;
    float _velocity;

    bool _isVisible;
    int _textureIndex;
    GLuint *_textures;

    void _draw(GLfloat pX, GLfloat pY, GLfloat pRotation);
};

#endif // BANANA_H
