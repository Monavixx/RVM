#pragma once

#include <iostream>
#include <string>
#include <vector>

class VirtualMachine
{
public:
    VirtualMachine(std::vector<unsigned char>&& bytes) : bytes{std::move(bytes)}
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
    constexpr static inline size_t version = 1;
    std::vector<unsigned char> bytes;

    _Assembly assembly;
};