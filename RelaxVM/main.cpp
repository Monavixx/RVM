#include "Program.h"

int main(int argc, char *argv[])
{
    /*Program program(argc, argv);
    try
    {
        program.Start();
    }
    catch (const ExitException& e)
    {
        qout << e.What();
    }*/
    Stack s, s1;

    RelaxString* data = new RelaxString("Lol");

    s.push(data);
    s1.push(data);

    RelaxString* poped = dynamic_cast<RelaxString*>(s.pop());
    poped = new RelaxString("Kek");
    
    qout << data->GetData();
    qout << dynamic_cast<RelaxString*>(s1.pop())->GetData();

    return 0;
}
