#include "Canvas.h"
#include <QPainter>
#include <QMouseEvent> 


Canvas::Canvas(QWidget *parent) : QWidget(parent), drawing(false) {
    setAttribute(Qt::WA_StaticContents);
    image = QImage(400, 300, QImage::Format_RGB32);
    image.fill(Qt::white);  // Initialize with white background
    setFixedSize(400, 300);
}
Canvas::~Canvas() {
    // destructor code
}
void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(event->rect(), image, event->rect());
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        drawing = true;
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        drawLineTo(event->pos());
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) {
        drawLineTo(event->pos());
        drawing = false;
    }
}

void Canvas::drawLineTo(const QPoint &endPoint) {
    QPainter painter(&image);
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    lastPoint = endPoint;
    update();
}
