#include "split.h"

QList<QString> Core::functions::split(const QString& str, const QString& separator)
{
    QList<QString> elems;
    elems.reserve(3);

    int index = str.indexOf(separator);
    if (index != -1)
    {
        elems.push_back(str.mid(0, index));
        elems.push_back(separator);
        elems.push_back(str.mid(index + separator.length(), str.length() - 1));
    }

    return elems;
}

QList<QString> Core::functions::split(const QString& str, const quint32& from, const quint32& to)
{
    QList<QString> elems;

    if (from != 0)
        elems.push_back(str.mid(0, from));

    elems.push_back(str.mid(from, to - from));

    if (to <= str.length() - 1)
        elems.push_back(str.mid(to, str.length() - 1));

    return elems;
}

QList<QString> Core::functions::splitBack(const QString& str, const QString& separator)
{
    QList<QString> elems;

    int index = str.indexOf(separator);
    while (index != -1)
    {
        int temp = str.indexOf(separator);

        if (temp != -1)
            index = temp;
        else
            break;
    }
    if (index != -1)
    {
        elems.reserve(3);
        elems.push_back(str.mid(0, index));
        elems.push_back(separator);
        elems.push_back(str.mid(index + separator.length(), str.length() - 1));
    }

    return elems;
}