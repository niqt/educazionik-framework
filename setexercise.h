#ifndef SETEXERCISE_H
#define SETEXERCISE_H

#include <QObject>
#include <QList>
#include "setitem.h"


class SetExercise
{

public:
    SetExercise(const QList<SetItem> &a, const QList<SetItem> &b, int solution);

    Q_INVOKABLE QList<SetItem> setA() const;
    Q_INVOKABLE QList<SetItem> setB() const;
    Q_INVOKABLE int solution();
    Q_INVOKABLE int setASize();
    Q_INVOKABLE int setBSize() ;
    Q_INVOKABLE QString setAElementType(int index) ;
    Q_INVOKABLE QString setBElementType(int index) ;
    Q_INVOKABLE QString setAElementValue(int index) ;
    Q_INVOKABLE QString setBElementValue(int index) ;
private:
    QList<SetItem> m_setA;
    QList<SetItem> m_setB;
    int m_solution;
};


#endif // SETEXERCISE_H
