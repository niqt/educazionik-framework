#include "exercisemultiansewer.h"
#include <QTextStream>
#include <QFile>

ExerciseMultiAnswer::ExerciseMultiAnswer(QString file, QObject *parent) :
    QObject(parent)
{
    QString s;
    QFile fd;

    fd.setFileName(file);

    if ( fd.open(QIODevice::ReadOnly) ) {
       QTextStream *t = new QTextStream( &fd );
       while ( !t->atEnd() ) {
           s = t->readLine();
           m_listQuestion.push_back(s);
           if ( !t->atEnd() ) {
               s = t->readLine();
               m_listAnswer.push_back(s);
           }
       }
       m_answersNumber = s.count(",") + 1;
       m_error = false;
       for (int i = 0; i < m_listQuestion.size(); m_check.push_back(0),i++);
    }
    else
       m_error = true;

    m_answer = "";
    srand(time(0));
}

QString ExerciseMultiAnswer::answer()
{
    return m_answer;
}

QString ExerciseMultiAnswer::question()
{
    return m_question;
}

QStringList ExerciseMultiAnswer::answers()
{
    return m_answers;
}

void ExerciseMultiAnswer::next()
{
    QString s,dum;
    int i,j;

    //random number [0,4]
    i = 1 + (int) ((m_answersNumber - 1) * rand()/(RAND_MAX));
    //random number [0,n_frasi]
    j=(int) (((double)m_listQuestion.size())*rand()/(RAND_MAX));


    if ( m_check[j] !=0 ) {
        m_check[j] = 0;
        j = (int) (((double)m_listQuestion.size())*rand()/(RAND_MAX));
    }

    m_check[j] = 1;
    // read frase
    m_question = m_listQuestion[j];

    // read solution
    s = m_listAnswer[j];

    m_answers.clear();

    for (int k = 0; k < m_answersNumber; k++) {
        m_answers << s.section(',', k, k);
    }
    // swap the right solution (0) with i-esima

    dum = m_answers[0];
    m_answers[0] = m_answers[i];
    m_answers[i] = dum;

    //the right solution
    m_answer = dum;
}


int ExerciseMultiAnswer::answersNumber() const
{
    return m_answersNumber;
}

