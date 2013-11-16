#include "setitem.h"

SetItem::SetItem(const QString &type, const QString &value)
{
    m_type = type;
    m_value = value;
}

SetItem::SetItem(const SetItem &other)
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
