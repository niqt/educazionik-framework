#ifndef SETITEM_H
#define SETITEM_H

#include <QObject>
#include <QString>

class SetItem: public QObject
{
Q_OBJECT
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY changeType)
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY changeValue)
private:
    QString m_type;
    QString m_value;
public:
    //explicit SetItem() {;}
    SetItem(const QString &type, const QString &value, QObject *parent=0);
    SetItem(const SetItem &other, QObject *parent=0);
    SetItem &operator=(const SetItem &other);
     QString type() const {return m_type; }
    void setType(QString type);
    void setValue(QString value);
     QString value() const {return m_value; }
signals:
    void changeValue();
    void changeType();
public slots:

};

#endif // SETITEM_H
