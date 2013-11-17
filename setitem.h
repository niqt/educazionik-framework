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
    //explicit SetItem() {;}
    SetItem(const QString &type, const QString &value);
    SetItem(const SetItem &other);
    SetItem &operator=(const SetItem &other);
     QString type() const {return m_type; }
     QString value() const {return m_value; }
signals:

public slots:

};

#endif // SETITEM_H
