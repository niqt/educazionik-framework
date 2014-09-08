#include "logic.h"


/*!
 * \brief Logic from the multianswer exercise
 * \param fileName the file name that contain the exercises
 * \param parent
 */

Logic::Logic(QString fileName, QObject *parent) :
    QObject(parent)
{
    m_exercise = new ExerciseMultiAnswer(fileName, parent);
    m_ok = 0;
    m_wrongs = 0;


}

/*!
 * \brief start the exercise
 */

void Logic::start()
{
    m_ok = 0;
    m_wrongs = 0;
    next();

}


/*!
 * \brief Next exercise
 */

void Logic::next()
{
    m_exercise->next();
    m_isOk = false;
    m_alternativeStatus.clear();

    QStringList answers = m_exercise->answers();
   m_model.clear();

    for (int i = 0; i < answers.length(); i++) {
        m_alternativeStatus.insert(answers.at(i), false);

    }
    emit questionChanged();
}


/*!
 * \brief Test the correctness of the answer
 * \param text the answer
 */

void Logic::test(QString text)
{
    if (text == m_exercise->answer()) {
        m_alternativeStatus.insert(text, true);
        m_ok++;
        m_isOk = true;
        emit isOk();
    } else {
        m_wrongs++;
        m_isOk = false;
        emit isError();
    }

}


/*!
 * \brief Return a number of answer
 * \return the number of answer
 */

int Logic::answersNumber()
{
    return m_exercise->answersNumber();
}


/*!
 * \brief Return the i answer
 * \param i number of answer
 * \return the i answer
 */

QString Logic::answer(int i)
{
    return m_exercise->answers().at(i);
}



/*!
 * \brief return the answers
 * \return the list of the answer
 */

QStringList Logic::answers()
{
    return m_exercise->answers();
}


/*!
 * \brief verify if the answer is correct
 * \return correctness
 */

bool Logic::ok()
{
    return m_isOk;
}


/*!
 * \brief verify if the answer is wrong
 * \return not correctness
 */

bool Logic::error()
{
    return (m_isOk == false);
}

/*!
 * \brief Return the question
 * \return the question
 */

QString Logic::question()
{
    return m_exercise->question();
}

/*!
 * \brief Return the number of the correct answer
 * \return
 */

int Logic::corrects()
{
    return m_ok;
}

/*!
 * \brief Return the number of the wrong answer
 * \return
 */

int Logic::wrongs()
{
    return m_wrongs;
}



