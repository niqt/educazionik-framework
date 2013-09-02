#include "exercisevocabularyanswer.h"
#include <QFile>
#include <QTextStream>

ExerciseVocabularyAnswer::ExerciseVocabularyAnswer(QString file, QObject *parent)
{
    QFile fd;
    m_fileName = file;
    fd.setFileName(m_fileName);

    if ( fd.exists()) {
        m_error = false;
    } else {
        m_error = true;
    }
}

bool ExerciseVocabularyAnswer::answerFounded(QString answer)
{
    QString s;
    QFile fd;
    bool founded = false;

    fd.setFileName(m_fileName);

    if ( fd.open(QIODevice::ReadOnly) ) {
       QTextStream *t = new QTextStream( &fd );
       while ( !t->atEnd() && !founded ) {
           s = t->readLine();
           if (s == answer) {
                founded = true;
           }
       }
       fd.close();
    }

    return founded;

}
