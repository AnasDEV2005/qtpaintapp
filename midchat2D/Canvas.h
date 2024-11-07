#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QString>

class Canvas : public QWidget {
    Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr);
    virtual ~Canvas();  // Virtual destructor should be defined
    virtual void paintEvent(QPaintEvent* event) override;  // Virtual function

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);

    QImage image;
    QPoint lastPoint;
    bool drawing;
};

#endif // CANVAS_H
