#pragma once

#include <QtCore>

class ByteArrayConvert
{
public:
    static int byteArrayToInt(const QByteArray& ba)
    {
        int res = 0;

        for (short i = 0; i < 4; ++i)
        {
            res = res << 8;
            res = res | unsigned char(ba[i]);
        }

        return res;
    }
    static short byteArrayToShort(const QByteArray& ba)
    {
        short res = 0;

        for (short i = 0; i < 2; ++i)
        {
            res = res << 8;
            res = res | unsigned char(ba[i]);
        }

        return res;
    }
    static long long byteArrayToLongLong(const QByteArray& ba)
    {
        long long res = 0;

        for (short i = 0; i < 8; ++i)
        {
            res = res << 8;
            res = res | unsigned char(ba[i]);
        }

        return res;
    }
    static unsigned char byteArrayToByte(const QByteArray& ba)
    {
        unsigned char res = 0;

        res = res << 8;
        res = res | unsigned char(ba[0]);

        return res;
    }
};

class ByteArrayReader
{
    quint64 readed = 0;
    QByteArray bytearray;
public:
    ByteArrayReader(const QByteArray& bytearray) : bytearray(bytearray){}
    QByteArray Read(const quint64& lenght)
    {
        QByteArray temp = bytearray.mid(readed, lenght);
        readed += lenght;
        return temp;
    }
    bool IsEnd()
    {
        return readed >= bytearray.size();
    }
    void AddToReaded(const quint64& n)
    {
        readed += n;
    }
};

class ByteArrayReadString
{
public:
    static QString ReadSizeAndString(QFile& file, short bytesSize = 8)
    {
        quint64 size = ByteArrayConvert::byteArrayToInt(file.read(bytesSize));
        return file.read(size);
    }
};