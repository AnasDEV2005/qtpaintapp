#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QDate>
#include <QString>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QVBoxLayout>

// creating the canvas class
class Canvas: public QWidget {
public:
    Canvas(QWidget *parent = nullptr) : QWidget(parent){
        setAttribute(Qt::WA_StaticContents);
        setFixedSize(400, 300);      
    }
    virtual ~Canvas();
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawImage(event->rect(), image, event->rect());
    }
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            lastPoint = event->pos();
            drawing = true;
        }
    }
    void mouseMoveEvent(QMouseEvent *event) override {
        if ((event->buttons() & Qt::LeftButton) && drawing) {
            drawLineTo(event->pos());
        }
    }
    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton && drawing) {
            drawLineTo(event->pos());
            drawing = false;
        }
    }
private:
    void drawLineTo(const QPoint &endPoint) {
        QPainter painter(&image);
        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(lastPoint, endPoint);
        lastPoint = endPoint;
        update();
    }

    QImage image = QImage(400, 300, QImage::Format_RGB32);
    QPoint lastPoint;
    bool drawing = false;
};    







// main function
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    Canvas *canvas = new Canvas;
    window.setCentralWidget(canvas);
    window.resize(400, 300);
    window.show();

    return app.exec();
}
