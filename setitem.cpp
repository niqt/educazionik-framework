#include "setitem.h"

SetItem::SetItem(const QString &type, const QString &value, QObject *parent): QObject(parent)
{
    m_type = type;
    m_value = value;
}

SetItem::SetItem(const SetItem &other, QObject *parent): QObject(parent)
{
    m_type = other.m_type;
    m_value = other.m_value;
}

SetItem& SetItem::operator=(const SetItem &other)
{
    m_type = other.m_type;
    m_value = other.m_value;
    return *this;
}

void SetItem::setType(QString type)
{
    m_type = type;
    emit changeType();
}

void SetItem::setValue(QString value)
{
    m_value = value;
    emit changeValue();
}

