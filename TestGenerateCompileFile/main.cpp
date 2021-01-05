#include <QtCore>

int main()
{
    QString filename = "test.ree";
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QDataStream ds(&file);

    ds << quint8(1) << QString("NameMainClass").toUtf8();

    ds << quint8(4) << quint8(1) << quint8(1) << QString("void").toUtf8() << QString("NameMainClass").toUtf8() << QString("Main").toUtf8() << int(0) << int(281);
    ds << quint8(7) << int(2) << QString("fffff world\n").toUtf8();
    ds << quint8(2) << int(1) << quint8(1) << QString("Relax.String").toUtf8() << int(1) << QString("Relax.String").toUtf8() << QString("data").toUtf8();
    ds << quint8(6) << int(1);
    ds << quint8(5) << quint8(1) << quint8(1) << QString("void").toUtf8() << QString("Relax.Console").toUtf8() << QString("Write").toUtf8() << int(1) << QString("Relax.String").toUtf8() << QString("text").toUtf8();
    ds << quint8(7) << int(3) << QString("Hello world").toUtf8();
    ds << quint8(2) << int(4) << quint8(1) << QString("Relax.String").toUtf8() << int(1) << QString("Relax.String").toUtf8() << QString("data").toUtf8();
    ds << quint8(6) << int(4);
    ds << quint8(5) << quint8(1) << quint8(1) << QString("void").toUtf8() << QString("Relax.Console").toUtf8() << QString("Write").toUtf8() << int(1) << QString("Relax.String").toUtf8() << QString("text").toUtf8();

    file.close();
    return 0;
}
