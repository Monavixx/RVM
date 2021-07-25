#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include <boost/program_options.hpp>
#include <fmt/core.h>
#include "vm.h"

namespace bpo = boost::program_options;
namespace fs = std::filesystem;


std::vector<unsigned char> readFile(fs::path&& path)
{
    std::ifstream f(path, std::ios::in | std::ios::binary);
    const auto sz = fs::file_size(path);
    std::vector<unsigned char> bytes(sz, 0);
    f.read((char*)bytes.data(), sz);

    return bytes;
}


int main(int argc, char* argv[])
{
    bpo::options_description desc("All options");

    desc.add_options()
        ("help,h", "produce help message")
        ("run,r", bpo::value<std::string>(), "launching the program.\n\t-r program.ree");
    bpo::variables_map vm;
    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
    bpo::notify(vm);

    if (vm.contains("help")) {
        std::cout << desc << '\n';
        return 0;
    }

    if (vm.contains("run")) {
        std::string filename = vm["run"].as<std::string>();
        std::vector<unsigned char> bytes = readFile(filename);
        VirtualMachine vm{move(bytes)};

        try {
            vm.parse();
            vm.run();
        }
        catch (const char* str) {
            std::cerr << str;
            return 1;
        }
    }

    return 0;
}