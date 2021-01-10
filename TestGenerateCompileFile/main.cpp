#include <QtCore>


void helloWorld(QDataStream& ds)
{
    ds << quint8(1) << QString("NameMainClass").toUtf8();
    ds << quint8(4) << quint8(1) << quint8(1) << QString("void").toUtf8() << QString("NameMainClass").toUtf8() << QString("Main").toUtf8() << int(0) << int(283);
    ds << quint8(7) << QString("hello world\n").toUtf8();
    ds << quint8(5) << quint8(1) << quint8(1) << QString("void").toUtf8() << QString("Relax.Console").toUtf8() << QString("Write").toUtf8() << int(1) << QString("Relax.String").toUtf8();
}

void PrintLocalVar(QDataStream& ds)
{
    ds << quint8(1) << QString("NameMainClass").toUtf8();
    ds << quint8(4) << quint8(1) << quint8(1) << QString("void").toUtf8() << QString("NameMainClass").toUtf8() << QString("Main").toUtf8() << int(0) << int(999);
    ds << quint8(11) << int(1);
    ds << quint8(7) << QString("Lofectr top").toUtf8();
    ds << quint8(10) << int(1);
    ds << quint8(6) << int(1);
    ds << quint8(5) << quint8(1) << quint8(1) << QString("void").toUtf8() << QString("Relax.Console").toUtf8() << QString("Write").toUtf8() << int(1) << QString("Relax.String").toUtf8();
    ds << quint8(6) << int(1);
    ds << quint8(5) << quint8(1) << quint8(1) << QString("void").toUtf8() << QString("Relax.Console").toUtf8() << QString("Write").toUtf8() << int(1) << QString("Relax.String").toUtf8();
}

int main()
{
    QString filename = "test.ree";
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QDataStream ds(&file);
    PrintLocalVar(ds);
    file.close();
    return 0;
}
