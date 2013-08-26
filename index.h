#ifndef INDEX_H
#define INDEX_H

#include <QObject>
#include <QMap>
#include <QString>
#include "logic.h"

class Index : public QObject
{
    Q_OBJECT
public:
    explicit Index(QObject *parent = 0);
    
signals:
    
public slots:

private:
    QMap <QString, QString> m_indexMap;
    Index *m_next;
    Logic *m_logic;
    int m_level;
};

#endif // INDEX_H
