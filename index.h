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
