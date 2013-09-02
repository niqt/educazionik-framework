#include "exerciseoneanswer.h"
#include <QFile>

ExerciseOneAnswer::ExerciseOneAnswer(QString file, QObject *parent = 0)
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

bool ExerciseOneAnswer::answerFounded(QString answer)
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
