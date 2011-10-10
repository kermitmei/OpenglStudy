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

protected:
    void initializeGL();
    void paintGL();
    //    void resizeGL(int width, int height);
    //    void mousePressEvent(QMouseEvent *event);
    //    void mouseMoveEvent(QMouseEvent *event);

private:
    static void display();
    static void reshape(int w, int h);

};

#endif//_GLWIDGET_H_
