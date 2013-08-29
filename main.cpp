#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "logic.h"
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    Logic logic("/tmp/aggettivi.txt",  viewer.rootContext());

    viewer.rootContext()->setContextProperty("logic", &logic);
    viewer.setMainQmlFile(QStringLiteral("qml/educazionik-framework/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
