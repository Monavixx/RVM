#pragma once

#include <string>
#include <vector>

#include "bytearray_reader.h"

class VirtualMachine
{
public:
    VirtualMachine(std::vector<unsigned char>&& bytes) : reader{std::move(bytes)}
    {
    }

    void parse();
    void run();

public:
    struct _Assembly
    {
        std::string name, version;
    };

private:
    constexpr static inline int version = 1;
    ByteArrayReader reader;

    _Assembly assembly;
};