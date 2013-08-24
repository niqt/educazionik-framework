#ifndef EXERCISE_H
#define EXERCISE_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QStringList>

class Exercise : public QObject
{
    Q_OBJECT

public:
    explicit Exercise(QObject *parent = 0);
    
signals:
    
public slots:
    
private:
    QString m_answer;
    QString m_question;
    int m_nAnswer;
    QString m_fileName;
    QStringList m_answers;
};

#endif // EXERCISE_H
