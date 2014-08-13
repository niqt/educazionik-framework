#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "logic.h"
#include <QQmlContext>
#include "exercisevocabularyanswer.h"
#include "2setsexercise.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    //Logic logic(":/aggettivi.txt",  viewer.rootContext());
    Logic logic(":/indeterminativo",  viewer.rootContext());
    ExerciseVocabularyAnswer vocabulary(":/parole.txt");

    TwoSetExercise set;
    set.load("/tmp/sets.xml");

    set.print();
    viewer.rootContext()->setContextProperty("logic", &logic);
    viewer.rootContext()->setContextProperty("vocabulary", &vocabulary);

    viewer.rootContext()->setContextProperty("setexercise", &set);

    //viewer.addImportPath("qml/educazionik-framework/");
    viewer.setMainQmlFile(QStringLiteral("qml/educazionik-framework/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
