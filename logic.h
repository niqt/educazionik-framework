#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QMap>
#include <QStringListModel>

#include "exercisemultiansewer.h"
#include <QQuickView>
#include <QQmlContext>

class Logic : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool ok
                 READ ok
                 NOTIFY isOk)
    Q_PROPERTY(bool error
                 READ error
                 NOTIFY isError)


    Q_PROPERTY(int corrects
                 READ corrects NOTIFY isOk
                 )

    Q_PROPERTY(int wrongs
                 READ wrongs NOTIFY isError
                 )

    Q_PROPERTY(QString question READ question NOTIFY questionChanged)


public:
    explicit Logic(QString fileName, QObject *parent = 0);
    Q_INVOKABLE void start();
    Q_INVOKABLE void next();
    Q_INVOKABLE void test(QString text);
    Q_INVOKABLE int answersNumber();

    Q_INVOKABLE QStringList answers();

    QString answer(int );
    bool ok();
    bool error();
    QString question();
    int corrects();
    int wrongs();
    QStringList m_model;
signals:
    void isError();
    void isOk();
    void questionChanged();

public slots:

private:
    int m_wrongs;
    int m_ok;
    bool m_isOk;
    QMap<QString, bool> m_alternativeStatus;
    int m_nAlternative;
    QString m_fileName;
    ExerciseMultiAnswer *m_exercise;

};

#endif // LOGIC_H
