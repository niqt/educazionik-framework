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
        //qDebug() << xmlStream.name() << "type" << xmlStream.tokenType();

        if (xmlStream.tokenType() == QXmlStreamReader::StartElement)
        {
            // Read the tag name.

            if (xmlStream.name() == "exercise") {
                qDebug() << xmlStream.name();
                xmlStream.readNext();
                if (xmlStream.name() == "")
                    xmlStream.readNext();

                if (xmlStream.name() == "setA") {
                    qDebug() << xmlStream.name();
                    xmlStream.readNext();
                    xmlStream.readNext();

                    while (xmlStream.name() != "setB") {
                        if (xmlStream.name() == "element" && xmlStream.tokenType() == QXmlStreamReader::StartElement) {
                            qDebug() << "card " << xmlStream.attributes().value("cardinality").toString();
                            qDebug() << " type " << xmlStream.attributes().value("type").toString() << endl;
                            xmlStream.readNext();
                            qDebug() << " Value = " << xmlStream.text().toString() << endl;
                        }
                        xmlStream.readNext();
                    }
                    qDebug() << xmlStream.name();
                    while (!(xmlStream.name() == "setB" && xmlStream.tokenType() == QXmlStreamReader::EndElement)) {
                        if (xmlStream.name() == "element" && xmlStream.tokenType() == QXmlStreamReader::StartElement) {
                            qDebug() << "card " << xmlStream.attributes().value("cardinality").toString();
                            qDebug() << " type " << xmlStream.attributes().value("type").toString() << endl;
                            xmlStream.readNext();
                            qDebug() << " Value = " << xmlStream.text().toString() << endl;
                        }
                        xmlStream.readNext();
                    }
                    while (!(xmlStream.name() == "solution" && xmlStream.tokenType() == QXmlStreamReader::EndElement)) {
                        if (xmlStream.name() == "solution" && xmlStream.tokenType() == QXmlStreamReader::StartElement) {

                            xmlStream.readNext();
                            qDebug() << " solution = " << xmlStream.text().toString() << endl;
                        }
                        xmlStream.readNext();
                    }
                }
            }

        }
    }
    qDebug() << "Fine\n";
}
