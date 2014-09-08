#include "exercisevocabularyanswer.h"
#include <QFile>
#include <QTextStream>


/*!
 * \brief Constructor for the Vocabulary exercise
 * \param file within the vocabulary
 * \param parent
 */

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


/*!
 * \brief Verify if the answer is correct
 * \param answer the answer
 * \return corretness
 */

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
