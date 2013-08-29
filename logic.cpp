#include "logic.h"

Logic::Logic(QString fileName, QObject *parent) :
    QObject(parent)
{
    m_exercise = new ExerciseMultiAnswer(fileName, parent);
    m_ok = 0;
    m_wrongs = 0;


}

void Logic::start()
{
    m_ok = 0;
    m_wrongs = 0;
    next();

}

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

int Logic::answersNumber()
{
    return m_exercise->answersNumber();
}

QString Logic::answer(int i)
{
    return m_exercise->answers().at(i);
}

QStringList Logic::answers()
{
    return m_exercise->answers();
}

bool Logic::ok()
{
    return m_isOk;
}

bool Logic::error()
{
    return (m_isOk == false);
}

QString Logic::question()
{
    return m_exercise->question();
}

int Logic::corrects()
{
    return m_ok;
}

int Logic::wrongs()
{
    return m_wrongs;
}



