#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>

class Logic : public QObject
{
    Q_OBJECT
public:
    explicit Logic(QObject *parent = 0);
    
signals:
    
public slots:

private:
    int m_wrongs;
    int m_ok;
    bool m_alternativeStatus[10];
    int m_nAlternative;
    QString m_fileName;
};

#endif // LOGIC_H
