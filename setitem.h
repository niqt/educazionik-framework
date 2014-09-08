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
