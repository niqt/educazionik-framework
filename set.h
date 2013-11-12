#ifndef SET_H
#define SET_H

#include <QSet>
#include <QObject>
#include <QXmlStreamReader>
#include "setitem.h"


class SetExercise
{
public:
    SetExercise(const QSet<SetItem> &a, const QSet<SetItem> &b, int solution) {m_setA = a; m_setB = b; m_solution = solution;}
    QSet<SetItem> setA() {return m_setA;}
    QSet<SetItem> setB() {return m_setB;}
    int solution() {return m_solution;}
private:
    QSet<SetItem> m_setA;
    QSet<SetItem> m_setB;
    int m_solution;
};


class Set : public QObject
{
    Q_OBJECT
private:
    QList<SetExercise> m_exericises;
public:
    explicit Set(QObject *parent = 0);
    void load(QString fileName);
signals:

public slots:

};

#endif // SET_H
