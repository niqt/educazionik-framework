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

#ifndef EXERCISE_H
#define EXERCISE_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QVector>

class ExerciseMultiAnswer : public QObject
{
    Q_OBJECT

public:
    explicit ExerciseMultiAnswer(QString file, QObject *parent = 0);
    QString answer();
    QString question();
    QStringList answers();
    void next();
    int answersNumber() const;


signals:
    
public slots:
    
private:
    QVector<QString> m_listQuestion, m_listAnswer;
    QVector<int> m_check;
    QString m_answer;
    QString m_question;
    int m_nAnswer;
    QString m_fileName;
    QStringList m_answers;
    bool m_error;
    int m_answersNumber;
};

#endif // EXERCISE_H
