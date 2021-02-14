#pragma once

#include <QtCore>


#ifdef Q_OS_WIN32
#include <Windows.h>
#include <iostream>
#else
#include <locale.h>
#endif

namespace Core
{
    class ConsoleTextStreamOutput : public QTextStream {
    public:
        ConsoleTextStreamOutput() : QTextStream(stdout, QIODevice::WriteOnly) {}
        ConsoleTextStreamOutput& operator<<(const QString& string)
        {
            #ifdef Q_OS_WIN32
                WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),
                string.utf16(), string.size(), NULL, NULL);
            #else
                QTextStream::operator<<(string);
            #endif
                return *this;
        }

    };


    class ConsoleTextStreamInput : public QTextStream {
    public:
        ConsoleTextStreamInput() : QTextStream(stdin, QIODevice::ReadOnly) {}
        QString readLine()
        {
            #ifdef Q_OS_WIN32
                const int bufsize = 512;
                wchar_t buf[bufsize];
                DWORD read;
                QString res;
                do {
                    ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE),
                        buf, bufsize, &read, NULL);
                    res += QString::fromWCharArray(buf, read);
                } while (read > 0 && res[res.length() - 1] != '\n');
                // could just do res.truncate(res.length() - 2), but better be safe
                while (res.length() > 0
                    && (res[res.length() - 1] == '\r' || res[res.length() - 1] == '\n'))
                    res.truncate(res.length() - 1);
                return res;
            #else
                return QTextStream::readLine();
            #endif
        }
        ConsoleTextStreamInput& operator>>(QString& string)
        {
            string = readLine();
            return *this;
        }

    };
}

inline Core::ConsoleTextStreamOutput qout;
inline Core::ConsoleTextStreamInput qin;