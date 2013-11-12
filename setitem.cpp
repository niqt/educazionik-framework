#include "setitem.h"

SetItem::SetItem()
{
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
