#ifndef _GLWIDGET_H_
#define _GLWIDGET_H_

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT;
public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    //    QSize minimumSizeHint() const;
    //    QSize sizeHint() const;

    /*
public slots:
    //    void setXRotation(int angle);
    //    void setYRotation(int angle);
    //    void setZRotation(int angle);

signals:
    //    void xRotationChanged(int angle);
    //    void yRotationChanged(int angle);
    //    void zRotationChanged(int angle);
    */
protected:
    void initializeGL();
    void paintGL();
    //    void resizeGL(int width, int height);
    //    void mousePressEvent(QMouseEvent *event);
    //    void mouseMoveEvent(QMouseEvent *event);

private:
};

#endif//_GLWIDGET_H_
