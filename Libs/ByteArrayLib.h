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

class ByteArrayRead
{
public:
    static QString ReadSizeAndString(QIODevice& device, short bytesSize = 4)
    {
        int size = ByteArrayConvert::byteArrayToInt(device.read(bytesSize));
        return device.read(size);
    }

    static quint8 ReadByte(QIODevice& device)
    {
        return ByteArrayConvert::byteArrayToByte(device.read(1));
    }

    static short ReadShort(QIODevice& device)
    {
        return ByteArrayConvert::byteArrayToShort(device.read(2));
    }

    static int ReadInt(QIODevice& device)
    {
        return ByteArrayConvert::byteArrayToByte(device.read(4));
    }

    static long long ReadLongLong(QIODevice& device)
    {
        return ByteArrayConvert::byteArrayToByte(device.read(8));
    }
};