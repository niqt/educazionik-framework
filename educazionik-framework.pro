# Add more folders to ship with the application, here
folder_01.source = qml/educazionik-framework
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

QT += qml quick

qtHaveModule(widgets) {
    QT += widgets
}

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    index.cpp \
    logic.cpp \
    exercisemultianswer.cpp \
    exercisevocabularyanswer.cpp \
    set.cpp \
    setitem.cpp \
    setexercise.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    index.h \
    logic.h \
    exercisemultiansewer.h \
    exercisevocabularyanswer.h \
    set.h \
    setitem.h \
    setexercise.h

RESOURCES += \
    educazioni.qrc

OTHER_FILES += \
    qml/educazionik-framework/GameVocabularyAnswer.qml \
    qml/educazionik-framework/ConsonantsModel.qml \
    qml/educazionik-framework/CompareSet.qml \
    qml/educazionik-framework/Set.qml \
    objectCreation.js




