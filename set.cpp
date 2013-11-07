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
        //qDebug() << xmlStream.text();
       //qDebug() << xmlStream.tokenString() << "\n";
        if (xmlStream.tokenType() == QXmlStreamReader::StartElement)
        {
            // Read the tag name.

            if (xmlStream.name() == "exercise") {
                 qDebug() << xmlStream.name();
                xmlStream.readNext();

                qDebug() << "NAME " << xmlStream.readElementText();
                if (xmlStream.readElementText() == "setA") {
                    qDebug() << xmlStream.name();
                    xmlStream.readNext();
                    while (xmlStream.readElementText() == "element") {
                        if (xmlStream.name() == "element")
                            qDebug() << "card " << xmlStream.attributes().value("cardinality").toString() << endl;
                        xmlStream.readNext();
                    }
                }
            }
            // Check in settings map, whether there's already an entry. If not, insert.
            //if(!_settingsMap.contains(sec))
            //    _settingsMap.insert(sec, xmlStream.attributes());
        }
    }
    qDebug() << "Fine\n";
}
