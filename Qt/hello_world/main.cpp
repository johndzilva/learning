#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("Hello World");
    label->setWindowTitle("DJ QT Learning");
    label->resize(400,400);
    label->show();
    return app.exec();
}
