#pragma once

#include <string>
#include <vector>

#include <fmt/core.h>

#include "bytearray_reader.h"
#include "ifunction.h"
#include "opcodes/opcode.h"
#include "opcode_build.h"

class VirtualMachine
{
private:
    VirtualMachine(std::vector<byte>&& bytes) noexcept : reader{std::move(bytes)}
    {
    }

public:
    static VirtualMachine& get_instance() noexcept
    {
        return *vm;
    }
    static void construct_instance(std::vector<byte>&& bytes) noexcept
    {
        if (vm != nullptr)
            delete vm;
        vm = new VirtualMachine(std::move(bytes));
    }
    static void free() noexcept
    {
        if (vm != nullptr)
            delete vm;
    }

    ~VirtualMachine() noexcept
    {
        for (auto& item : functions) {
            delete item;
        }
    }

    void parse();
    void run();

public:
    struct _Assembly
    {
        std::string name, version;
    };

public:
    std::vector<IFunction*>& get_functions() noexcept { return functions; }
    std::vector<std::string>& get_include_assembly() noexcept { return includeAssebly; }
    _Assembly& get_assembly() noexcept { return assembly; }


private:
    static inline VirtualMachine* vm = nullptr;
    constexpr static inline int version = 1;
    const ByteArrayReader reader;

    _Assembly assembly;
    std::vector<std::string> includeAssebly;
    std::vector<IFunction*> functions;
};