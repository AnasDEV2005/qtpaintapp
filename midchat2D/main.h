#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QImage>
#include <QPoint>

class Canvas : public QWidget {
    Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr);
    virtual ~Canvas();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);

    QImage image;
    QPoint las
