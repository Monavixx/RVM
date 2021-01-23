#pragma once
#include <QtCore>

namespace Core::functions
{
    QList<QString> split(const QString& str, const QString& separator);
    QList<QString> split(const QString& str, const quint32& from, const quint32& to);
    QList<QString> splitBack(const QString& str, const QString& separator);
}