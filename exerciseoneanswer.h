#ifndef EXERCISEONEANSWER_H
#define EXERCISEONEANSWER_H



#include <QObject>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QVector>

class ExerciseOneAnswer : public QObject
{
    Q_OBJECT

public:
    explicit ExerciseOneAnswer(QString file, QObject *parent = 0);
    bool answerFounded(QString answer);


signals:

public slots:

private:
    QString m_fileName;
    bool m_error;

};


#endif // EXERCISEONEANSWER_H
