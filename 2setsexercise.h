#ifndef SET_H
#define SET_H

#include <QSet>
#include <QObject>
#include <QXmlStreamReader>

#include "setexercise.h"
#include <QVariant>



class TwoSetExercise : public QObject
{
    Q_OBJECT
private:
    QList<SetExercise> m_exericises;
    unsigned int m_current;
public:
    explicit TwoSetExercise(QObject *parent = 0);
    void load(QString fileName);
    void print();
    Q_INVOKABLE SetExercise exercise();
    Q_INVOKABLE void next();
    /*Q_INVOKABLE QString elementType(int index);
    Q_INVOKABLE QString elementValue(int index);
    Q_INVOKABLE int setBSize();*/
    Q_INVOKABLE int setASize() const {return m_exericises.at(m_current).setA().size();}
    Q_INVOKABLE int setBize() const {return m_exericises.at(m_current).setB().size();}
    Q_INVOKABLE QVariant setA();
    Q_INVOKABLE QVariant setB();
signals:

public slots:

};

#endif // SET_H
