#include "bodymetrics.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BodyMetrics w;
    w.show();
    return a.exec();
}
