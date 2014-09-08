#include "setitem.h"

/*!
 * \brief Constructor of Set Item
 * \param type is a type of elements
 * \param value value of the element
 * \param parent
 */

SetItem::SetItem(const QString &type, const QString &value, QObject *parent): QObject(parent)
{
    m_type = type;
    m_value = value;
}

/*!
 * \brief Copy constructor
 * \param other element to copy
 * \param parent
 */

SetItem::SetItem(const SetItem &other, QObject *parent): QObject(parent)
{
    m_type = other.m_type;
    m_value = other.m_value;
}

/*!
 * \brief operator =
 * \param other
 * \return
 */

SetItem& SetItem::operator=(const SetItem &other)
{
    m_type = other.m_type;
    m_value = other.m_value;
    return *this;
}

/*!
 * \brief set type of the element
 * \param type ype of the element
 */

void SetItem::setType(QString type)
{
    m_type = type;
    emit changeType();
}

/*!
 * \brief Set the value of the item
 * \param value
 */

void SetItem::setValue(QString value)
{
    m_value = value;
    emit changeValue();
}

