#ifndef SET_H
#define SET_H

#include <QSet>
#include <QObject>
#include <QXmlStreamReader>
#include "setitem.h"

class Set : public QObject
{
    Q_OBJECT
public:
    explicit Set(QObject *parent = 0);
    void load(QString fileName);
signals:

public slots:

};

#endif // SET_H
