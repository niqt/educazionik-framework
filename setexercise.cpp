#include "setexercise.h"

/*!
 * \brief Contructor for SetExercise
 * \param a is the first set
 * \param b is the second first
 * \param solution is the solution
 */


SetExercise::SetExercise(const QList<SetItem> &a, const QList<SetItem> &b, int solution)

{
    m_setA = a;
    m_setB = b;
    m_solution = solution;
}


/*!
 * \brief returt the set A
 * \return list of the elements of the set A
 */

QList<SetItem> SetExercise::setA() const
{
    return m_setA;
}

/*!
 * \brief returt the set B
 * \return list of the elements of the set B
 */

QList<SetItem> SetExercise::setB() const
{
    return m_setB;
}

/*!
 * \brief return the solutions
 * \return the solution
 */

int SetExercise::solution()
{
    return m_solution;
}

/*!
 * \brief return the size of the Set A
 * \return the size
 */

int SetExercise::setASize()
{
    return m_setA.size();
}

/*!
 * \brief return the size of the Set B
 * \return the size
 */

int SetExercise::setBSize()
{
return m_setB.size();
}


/*!
 * \brief return the type of the elment index of the set A
 * \param index
 * \return elment type
 */

QString SetExercise::setAElementType(int index)
{
    m_setA.at(index).type();
}

/*!
 * \brief return the type of the elment index of the set B
 * \param index
 * \return elment type
 */

QString SetExercise::setBElementType(int index)
{
    m_setB.at(index).type();
}

/*!
 * \brief return the value of the elment index of the set A
 * \param index
 * \return elment value
 */

QString SetExercise::setAElementValue(int index)
{
    m_setA.at(index).value();
}


/*!
 * \brief return the value of the elment index of the set B
 * \param index
 * \return elment value
 */

QString SetExercise::setBElementValue(int index)
{
    m_setB.at(index).value();
}
