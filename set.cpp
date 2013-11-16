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

            if (xmlStream.name() == "exercise") {


                QList<SetItem> setA;
                QList<SetItem> setB;
                QString solution;
                xmlStream.readNext();
                if (xmlStream.name() == "")
                    xmlStream.readNext();

                if (xmlStream.name() == "setA") {

                    xmlStream.readNext();
                    xmlStream.readNext();

                    while (xmlStream.name() != "setB") {


                        if (xmlStream.name() == "element" && xmlStream.tokenType() == QXmlStreamReader::StartElement) {

                            int cardinality = xmlStream.attributes().value("cardinality").toString().toInt();
                            QString type = xmlStream.attributes().value("type").toString();
                            xmlStream.readNext();
                            QString value = xmlStream.text().toString();

                            for (int i = 0; i < cardinality; i++) {
                                SetItem currentItem(type, value);
                                setA.append(currentItem);
                            }

                        }

                        xmlStream.readNext();
                    }

                    while (!(xmlStream.name() == "setB" && xmlStream.tokenType() == QXmlStreamReader::EndElement)) {
                        if (xmlStream.name() == "element" && xmlStream.tokenType() == QXmlStreamReader::StartElement) {

                            int cardinality = xmlStream.attributes().value("cardinality").toString().toInt();
                            QString type = xmlStream.attributes().value("type").toString();
                            xmlStream.readNext();
                            QString value = xmlStream.text().toString();

                            for (int i = 0; i < cardinality; i++) {
                                SetItem currentItem(type, value);
                                setB.append(currentItem);
                            }
                        }
                        xmlStream.readNext();
                    }
                    while (!(xmlStream.name() == "solution" && xmlStream.tokenType() == QXmlStreamReader::EndElement)) {
                        if (xmlStream.name() == "solution" && xmlStream.tokenType() == QXmlStreamReader::StartElement) {

                            xmlStream.readNext();
                            solution = xmlStream.text().toString();
                        }
                        xmlStream.readNext();
                    }
                    SetExercise currentExercise(setA, setB, solution.toInt());
                    m_exericises.append(currentExercise);
                }
            }

        }
    }

}

SetExercise Set::exercise()
{
    return m_exericises.at(0);
}

void Set::print()
{
    for (int i = 0; i < m_exericises.length(); i++) {
        SetExercise current = m_exericises.at(i);
        QList<SetItem> a = current.setA();
        QList<SetItem> b = current.setB();
        int solution = current.solution();

        qDebug() << " Exercise " << i << endl;
        qDebug() << " SETA " << endl;
        for (int j = 0; j < a.length(); j++ ) {
            qDebug() << "Item " << j << " type " << (a.at(j)).type() << " value " << (a.at(j)).value() << endl;
        }
        qDebug() << " SETB " << endl;
        for (int j = 0; j < a.length(); j++ ) {
            qDebug() << "Item " << j << " type " << b.at(j).type() << " value " << b.at(j).value() << endl;
        }
        qDebug() << "Solution = " << solution;
        qDebug() << "--------------------------------\n\n";
    }
}
