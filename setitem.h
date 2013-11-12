#ifndef SETITEM_H
#define SETITEM_H

#include <QObject>
#include <QString>

class SetItem
{

private:
    QString m_type;
    QString m_value;
public:
    explicit SetItem();
    SetItem(const SetItem &other);
    SetItem &operator=(const SetItem &other);
signals:

public slots:

};

#endif // SETITEM_H
