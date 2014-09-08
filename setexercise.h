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


#ifndef SETEXERCISE_H
#define SETEXERCISE_H

#include <QObject>
#include <QList>
#include "setitem.h"


class SetExercise
{

public:
    SetExercise(const QList<SetItem> &a, const QList<SetItem> &b, int solution);

    Q_INVOKABLE QList<SetItem> setA() const;
    Q_INVOKABLE QList<SetItem> setB() const;
    Q_INVOKABLE int solution();
    Q_INVOKABLE int setASize();
    Q_INVOKABLE int setBSize() ;
    Q_INVOKABLE QString setAElementType(int index) ;
    Q_INVOKABLE QString setBElementType(int index) ;
    Q_INVOKABLE QString setAElementValue(int index) ;
    Q_INVOKABLE QString setBElementValue(int index) ;
private:
    QList<SetItem> m_setA;
    QList<SetItem> m_setB;
    int m_solution;
};


#endif // SETEXERCISE_H
