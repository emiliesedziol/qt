#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // delare list -> list starts at zero
    QList<QString> stringList;

    //put data in the list
    stringList << "Is" << "there" << "any" << "one" << "out" << "there";

    stringList.append("!!");
    stringList.append("??");

    qDebug() << stringList[0];
    qDebug() << "the number of elements " << stringList.count() << endl;


    // loop thru elements
    for (int i = 0;i < stringList.count();i++)
    {
        qDebug() << "i " << i << stringList[i];
        qDebug() << "i " << QString::number(i) << " is " << stringList.at(i);
    }

    /*
     *
     * "Is"
the number of elements  8

i  0 "Is"

i  "0"  is  "Is"

i  1 "there"

i  "1"  is  "there"

i  2 "any"

i  "2"  is  "any"

i  3 "one"

i  "3"  is  "one"

i  4 "out"

i  "4"  is  "out"

i  5 "there"

i  "5"  is  "there"

i  6 "!!"

i  "6"  is  "!!"

i  7 "??"

i  "7"  is  "??"
*/

    return a.exec();
}
