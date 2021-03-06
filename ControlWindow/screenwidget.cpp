#include "screenwidget.h"


ScreenWidget::ScreenWidget(QWidget *parent)
    :QGLWidget(parent), program(0), clearColor(Qt::black)
{

}

ScreenWidget::~ScreenWidget()
{
    makeCurrent();
    vbo.destroy();
    delete program;
    doneCurrent();
}

void ScreenWidget::DrawPixmap(QPixmap *pixmap)
{
    deleteTexture(texId);
    texId = bindTexture(*pixmap);
//    delete pixmap;
    update();
}

void ScreenWidget::initializeGL()
{
    f = QOpenGLContext::currentContext()->functions();
    makeObject();

    f->glEnable(GL_DEPTH_TEST);
    f->glEnable(GL_CULL_FACE);

    #define PROGRAM_VERTEX_ATTRIBUTE 0
    #define PROGRAM_TEXCOORD_ATTRIBUTE 1

    QOpenGLShader *vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    const char *vsrc =
        "attribute highp vec4 vertex;\n"
        "attribute mediump vec4 texCoord;\n"
        "varying mediump vec4 texc;\n"
        "void main(void)\n"
        "{\n"
        "    gl_Position = vertex;\n"
        "    texc = texCoord;\n"
        "}\n";
    vshader->compileSourceCode(vsrc);

    QOpenGLShader *fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    const char *fsrc =
        "uniform sampler2D texture;\n"
        "varying mediump vec4 texc;\n"
        "void main(void)\n"
        "{\n"
        "    gl_FragColor = texture2D(texture, texc.st);\n"
        "}\n";
    fshader->compileSourceCode(fsrc);

    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);
    program->bindAttributeLocation("vertex", PROGRAM_VERTEX_ATTRIBUTE);
    program->bindAttributeLocation("texCoord", PROGRAM_TEXCOORD_ATTRIBUTE);
    program->link();

    program->bind();
    program->setUniformValue("texture", 0);
}

void ScreenWidget::resizeGL(int width, int height)
{
    f->glViewport(0, 0, width, height);
}

void ScreenWidget::paintGL()
{
    f->glClearColor(clearColor.redF(), clearColor.greenF(), clearColor.blueF(), clearColor.alphaF());
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    program->enableAttributeArray(PROGRAM_VERTEX_ATTRIBUTE);
    program->enableAttributeArray(PROGRAM_TEXCOORD_ATTRIBUTE);
    program->setAttributeBuffer(PROGRAM_VERTEX_ATTRIBUTE, GL_FLOAT, 0, 3, 5 * sizeof(GLfloat));
    program->setAttributeBuffer(PROGRAM_TEXCOORD_ATTRIBUTE, GL_FLOAT, 3 * sizeof(GLfloat), 2, 5 * sizeof(GLfloat));
    f->glBindTexture(GL_TEXTURE_2D, texId);
    f->glDrawArrays(GL_QUADS, 0, 4);
}

void ScreenWidget::makeObject()
{
    static const int coords[4][3] ={
        { +1, +1, 0 },
        { -1, +1, 0 },
        { -1, -1, 0 },
        { +1, -1, 0 } };
    QPixmap pixmap(100,100);
    pixmap.fill(Qt::white);
    texId = bindTexture(pixmap);

    QVector<GLfloat> vertData;
    for (int j = 0; j < 4; ++j) {
        // vertex position
        vertData.append(coords[j][0]);
        vertData.append(coords[j][1]);
        vertData.append(coords[j][2]);
        // texture coordinate
        vertData.append(j == 0 || j == 3);
        vertData.append(j == 0 || j == 1);
    }

    vbo.create();
    vbo.bind();
    vbo.allocate(vertData.constData(), vertData.count() * sizeof(GLfloat));
}
