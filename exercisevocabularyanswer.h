#ifndef EXERCISEVOCABULARYANSWER_H
#define EXERCISEVOCABULARYANSWER_H



#include <QObject>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QVector>

class ExerciseVocabularyAnswer : public QObject
{
    Q_OBJECT

public:
    explicit ExerciseVocabularyAnswer(QString file, QObject *parent = 0);
    bool answerFounded(QString answer);


signals:

public slots:

private:
    QString m_fileName;
    bool m_error;

};


#endif // EXERCISEONEANSWER_H
