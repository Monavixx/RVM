#pragma once

#include <fstream>
#include <vector>
#include <iostream>
#include "String.h"
#include "../Functions/Exit.h"

using std::ifstream;

class ByteArray
{
public:
    ByteArray() {}
    ByteArray(const std::vector<unsigned char>& vec)
    {
        data = new unsigned char[vec.size()];
        for (size_t i = 0; i < vec.size(); ++i)
        {
            data[i] = vec[i];
        }
    }
    ByteArray(const ByteArray& other)
    {
        _size = other._size;
        capacity = other.capacity;
        data = new unsigned char[other.size()];
        for (size_t i = 0; i < other.size(); ++i)
        {
            data[i] = other[i];
        }
    }

    ByteArray mid(size_t start, size_t length = -1) const
    {
        ByteArray res;
        length = (length == -1) ? _size - start : length;
        res.Resize(length);
        for (size_t i = 0; i < length; ++i)
        {
            res[i] = data[i + start];
        }
        return res;
    }
    inline unsigned char& operator[](size_t index) const
    {
#ifdef DEBUG
        if (index >= _size) Exit("String. Index out of range");
#endif
        return data[index];
    }
    inline size_t size() const
    {
        return _size;
    }

    void push_back(unsigned char el)
    {
        if (capacity > _size)
            data[_size++] = el;
        else
        {
            unsigned char* newData = new unsigned char[capacity = _isCapacity ? _size + 10 : _size];
            for (size_t i = 0; i < _size; ++i)
            {
                newData[i] = data[i];
            }
            newData[_size++] = el;
            delete[] data;
            data = newData;
        }
    }

    void SetSize(size_t newSize)
    {
        _size = capacity = newSize;
    }

    void Resize(size_t size)
    {
        if (data == nullptr)
        {
            data = new unsigned char[_size = capacity = size] {0};
        }
        else
        {
            unsigned char* newData = new unsigned char[capacity = _isCapacity ? _size + 10 : _size];
            size_t newSize = (_size >= size) ? size : _size;
            for (size_t i = 0; i < newSize; ++i)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            _size = newSize;
        }
    }

    inline void isCapacity(bool value) { _isCapacity = value; }
    inline bool isCapacity() const { return _isCapacity; }
    inline unsigned char* GetData() const { return data; }

private:
    size_t _size = 0;
    size_t capacity = 0;
    unsigned char* data = nullptr;
    bool _isCapacity = true;
};

class ByteArrayConvert
{
public:
    static int byteArrayToInt(const ByteArray& ba)
    {
        int res = 0;

        for (short i = 0; i < 4; ++i)
        {
            res = res << 8;
            res = res | ba[i];
        }

        return res;
    }
    inline static short byteArrayToShort(const ByteArray& ba)
    {
        return (ba[0] << 8) | ba[1];
    }
    static long long byteArrayToLongLong(const ByteArray& ba)
    {
        long long res = ba[0];

        for (unsigned char i = 1; i < 8; ++i)
        {
            res = (res << 8) | ba[i];
        }

        return res;
    }
    inline static unsigned char byteArrayToByte(const ByteArray& ba)
    {
        return ba[0];
    }

    static float byteArrayToFloat(const ByteArray& ba)
    {
        float res;
        int num = ByteArrayConvert::byteArrayToInt(ba.mid(0, 4)), fracPart = ByteArrayConvert::byteArrayToInt(ba.mid(4, 4));
        short numberOfDigitsInFractionalPart = (fracPart == 0 ? 1 : short(log10(fracPart) + 1));
        res = num + float(fracPart) / float(pow(10, numberOfDigitsInFractionalPart));
        return res;
    }
};

class ByteArrayReader
{
    size_t readed = 0;
    ByteArray bytearray;
public:
    ByteArrayReader(const ByteArray& bytearray) : bytearray(bytearray){}
    ByteArray Read(size_t lenght)
    {
        ByteArray temp = bytearray.mid(readed, lenght);
        readed += lenght;
        return temp;
    }
    bool IsEnd()
    {
        return readed >= bytearray.size();
    }
    void AddToReaded(size_t n)
    {
        readed += n;
    }
};

class ByteArrayRead
{
public:
#ifdef _WIN32
    static String ReadSizeAndString(HANDLE& device, short bytesSize = 4)
    {
        ByteArray bsize;
        bsize.isCapacity(false);
        bsize.Resize(bytesSize);
        ReadFile(device, &bsize[0], bytesSize, nullptr, nullptr);
        int size = ByteArrayConvert::byteArrayToInt(bsize);

        String str;
        ByteArray bstr;
        bstr.Resize(size);
        ReadFile(device, &bstr[0], size, nullptr, nullptr);
        
        for (size_t i = 0; i < size; i += 2)
        {
            unsigned short res = bstr[i];
            res <<= 8;
            res |= bstr[i + 1];
            str.push_back(res);
        }
        return str;
    }

    static ByteArray ReadSizeAndByteArray(HANDLE& device, short bytesSize = 4)
    {
        ByteArray bsize;
        bsize.isCapacity(false);
        bsize.Resize(bytesSize);
        ReadFile(device, &bsize[0], bytesSize, nullptr, nullptr);
        int size = ByteArrayConvert::byteArrayToInt(bsize);

        ByteArray ba;
        ba.Resize(size);
        ReadFile(device, &ba[0], size, nullptr, nullptr);

        return ba;
    }

    static unsigned char ReadByte(HANDLE& device)
    {
        unsigned char res = 0;
        BOOL err = ReadFile(device, &res, 1, nullptr, nullptr);
        return res;
    }

    static short ReadShort(HANDLE& device)
    {
        ByteArray ba;
        ba.Resize(2);
        ReadFile(device, ba.GetData(), 2, nullptr, nullptr);
        return ByteArrayConvert::byteArrayToShort(ba);
    }

    static int ReadInt(HANDLE& device)
    {
        ByteArray ba;
        ba.Resize(4);
        ReadFile(device, ba.GetData(), 4, nullptr, nullptr);
        return ByteArrayConvert::byteArrayToInt(ba);
    }

    static float ReadFloat(HANDLE& device)
    {
        ByteArray ba;
        ba.Resize(8);
        ReadFile(device, ba.GetData(), 8, nullptr, nullptr);
        return ByteArrayConvert::byteArrayToFloat(ba);
    }

    static long long ReadLongLong(HANDLE& device)
    {
        ByteArray ba;
        ba.Resize(8);
        ReadFile(device, ba.GetData(), 8, nullptr, nullptr);
        return ByteArrayConvert::byteArrayToLongLong(ba);
    }
#endif
};