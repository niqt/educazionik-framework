#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "logic.h"
#include <QQmlContext>
#include "exercisevocabularyanswer.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    Logic logic(":/aggettivi.txt",  viewer.rootContext());
    ExerciseVocabularyAnswer vocabulary(":/parole.txt");

    viewer.rootContext()->setContextProperty("logic", &logic);
    viewer.rootContext()->setContextProperty("vocabulary", &vocabulary);
    viewer.setMainQmlFile(QStringLiteral("qml/educazionik-framework/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
