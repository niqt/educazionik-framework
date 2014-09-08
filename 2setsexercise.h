/*
* This file is part of educazionik-framework
*
* Copyright (C) 2014 Nicola De Filippo.
*
* Contact: Nicola De Filippo <nicola@nicoladefilippo.it> or <nicola.defilippo@lizard-solutions.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
* 02110-1301 USA
*
*/

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
