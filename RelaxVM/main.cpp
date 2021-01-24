#include "Program.h"

int main(int argc, char *argv[])
{
    Program program(argc, argv);
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
