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
