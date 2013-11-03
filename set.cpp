#include "set.h"
#include <QDebug>
#include <QFile>

Set::Set(QObject *parent) :
    QObject(parent)
{
}

void Set::load(QString fileName)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);

    QString data = file.readAll();
    file.close();
    QXmlStreamReader xmlStream(data);
    while(!xmlStream.atEnd())
    {

        xmlStream.readNext();
        //if(xmlStream.isStartElement())
        qDebug() << xmlStream.text();
       qDebug() << xmlStream.tokenString() << "\n";
        if (xmlStream.tokenType() == QXmlStreamReader::StartDocument)
        {
            // Read the tag name.
            QString sec(xmlStream.tokenString());
            qDebug() << " sec " << sec << endl;
            // Check in settings map, whether there's already an entry. If not, insert.
            //if(!_settingsMap.contains(sec))
            //    _settingsMap.insert(sec, xmlStream.attributes());
        }
    }
    qDebug() << "Fine\n";
}
