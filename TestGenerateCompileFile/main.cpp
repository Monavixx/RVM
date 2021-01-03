#include <QtCore>

int main()
{
    QString filename = "test.ree";
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QDataStream ds(&file);

    ds << quint8(1) << QString("NameMainClass").toUtf8();
    ds << quint8(4) << quint8(1) << QString("void").toUtf8() << QString("NameMainClass").toUtf8() << QString("Main").toUtf8() << int(0);
    ds << quint8(7) << QString("Hello world").toUtf8();
    ds << quint8(5) << quint8(1) << QString("void").toUtf8() << QString("Relax.Console").toUtf8() << QString("Print").toUtf8() << int(1) << QString("Relax.String").toUtf8();
    ds << quint8(9);

    file.close();
    return 0;
}
