#include "Program.h"
#include "Core/FieldObject.h"

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; ++i)
        Args::args.push_back(argv[i]);

    Program program;
    try
    {
        program.Start();
    }
    catch (const ExitException& e)
    {
        qout << e.What();
    }

    return 0;
}