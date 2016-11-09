#ifndef SCREENWIDGET_H
#define SCREENWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>

class ScreenWidget : public QGLWidget
{
public:
    ScreenWidget(QWidget *parent = 0);
    ~ScreenWidget();
    void DrawPixmap(QPixmap *pixmap);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
private:
    void makeObject();
    //QOpenGLTexture *texture;
    QOpenGLShaderProgram *program;
    QOpenGLBuffer vbo;
    QColor clearColor;
    QOpenGLFunctions* f;
    GLuint texId;
};

#endif // SCREENWIDGET_H
