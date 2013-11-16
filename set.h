#ifndef SET_H
#define SET_H

#include <QSet>
#include <QObject>
#include <QXmlStreamReader>
#include "setitem.h"




class SetExercise
{
public:
    SetExercise(const QList<SetItem> &a, const QList<SetItem> &b, int solution) {m_setA = a; m_setB = b; m_solution = solution;}
    Q_INVOKABLE QList<SetItem> setA() {return m_setA;}
    QList<SetItem> setB() {return m_setB;}
    int solution() {return m_solution;}
private:
    QList<SetItem> m_setA;
    QList<SetItem> m_setB;
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
    void print();
    Q_INVOKABLE SetExercise exercise();
signals:

public slots:

};

#endif // SET_H
