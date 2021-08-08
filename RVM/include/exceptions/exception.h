#pragma once

#include <exception>
#include <string>
#include <sstream>

using namespace std::string_literals;

class all_exception : public std::exception
{
public:
    all_exception(std::string&& msg) : msg{std::move(msg)}
    {
    }

    const char* what() const noexcept override
    {
        return msg.c_str();
    }
private:
    std::string msg;
};

class bytearray_reader_exception : public all_exception
{
public:
    bytearray_reader_exception(const std::string& msg)
        : all_exception{ "bytearray_reader_exception: " + msg }
    {
    }
};

class bytecode_exception : public all_exception
{
public:
    bytecode_exception(const std::string& msg)
        : all_exception{ "bytecode_exception: " + msg }
    {
    }
};
