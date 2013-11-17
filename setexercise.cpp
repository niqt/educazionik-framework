#include "setexercise.h"

SetExercise::SetExercise(const QList<SetItem> &a, const QList<SetItem> &b, int solution)

{
    m_setA = a;
    m_setB = b;
    m_solution = solution;
}


QList<SetItem> SetExercise::setA() const
{
    return m_setA;
}

QList<SetItem> SetExercise::setB() const
{
    return m_setB;
}

int SetExercise::solution()
{
    return m_solution;
}

int SetExercise::setASize()
{
    return m_setA.size();
}

int SetExercise::setBSize()
{
return m_setB.size();
}

QString SetExercise::setAElementType(int index)
{
    m_setA.at(index).type();
}

QString SetExercise::setBElementType(int index)
{
    m_setB.at(index).type();
}


QString SetExercise::setAElementValue(int index)
{
    m_setA.at(index).value();
}

QString SetExercise::setBElementValue(int index)
{
    m_setB.at(index).value();
}
