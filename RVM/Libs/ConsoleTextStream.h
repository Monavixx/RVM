#pragma once

#include "String.h"


#ifdef _WIN32
#include <Windows.h>
#include <iostream>
#else
#include <locale.h>
#endif
class ConsoleTextStreamOutput {
public:
    ConsoleTextStreamOutput& operator<<(const String& str)
    {
#ifdef _WIN32
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),
            str.utf16(), str.size(), NULL, NULL);
#else
        std::cout << str;
#endif
        return *this;
    }

};


class ConsoleTextStreamInput {
public:
    String readLine()
    {
        #ifdef _WIN321
            const int bufsize = 1024;
            wchar_t buf[bufsize];
            DWORD read;
            String res;
            do {
                ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE),
                    buf, bufsize, &read, NULL);
                res += String::FromWCharArray(buf, read);
            } while (read > 0 && res[res.size() - 1] != '\n');
            while (res.size() > 0
                && (res[res.size() - 1] == '\r' || res[res.size() - 1] == '\n'))
                res.truncate(res.size() - 1);
            return res;
        #else
            std::string str;
            std::cin >> str;
            return str;
        #endif
    }
    ConsoleTextStreamInput& operator>>(String& string)
    {
        string = readLine();
        return *this;
    }
};

inline ConsoleTextStreamOutput qout;
inline ConsoleTextStreamInput qin;