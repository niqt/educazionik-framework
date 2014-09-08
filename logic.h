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


#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QMap>
#include <QStringListModel>

#include "exercisemultiansewer.h"
#include <QQuickView>
#include <QQmlContext>

class Logic : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool ok
                 READ ok
                 NOTIFY isOk)
    Q_PROPERTY(bool error
                 READ error
                 NOTIFY isError)


    Q_PROPERTY(int corrects
                 READ corrects NOTIFY isOk
                 )

    Q_PROPERTY(int wrongs
                 READ wrongs NOTIFY isError
                 )

    Q_PROPERTY(QString question READ question NOTIFY questionChanged)


public:
    explicit Logic(QString fileName, QObject *parent = 0);
    Q_INVOKABLE void start();
    Q_INVOKABLE void next();
    Q_INVOKABLE void test(QString text);
    Q_INVOKABLE int answersNumber();

    Q_INVOKABLE QStringList answers();

    QString answer(int );
    bool ok();
    bool error();
    QString question();
    int corrects();
    int wrongs();
    QStringList m_model;
signals:
    void isError();
    void isOk();
    void questionChanged();

public slots:

private:
    int m_wrongs;
    int m_ok;
    bool m_isOk;
    QMap<QString, bool> m_alternativeStatus;
    int m_nAlternative;
    QString m_fileName;
    ExerciseMultiAnswer *m_exercise;

};

#endif // LOGIC_H
