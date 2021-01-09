#include "Program.h"
#include "Frame.h"

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
    Frame f;
    f.SetVariableList(VariableList({Variable(10, new RelaxString("Lol"))}));

    Variable* v = f.FindVariableById(10);
    qout << dynamic_cast<RelaxString*>(v->GetData())->GetData();
    v->SetData(new RelaxString("Kek"));
    Variable* v2 = f.FindVariableById(10);
    qout << dynamic_cast<RelaxString*>(v2->GetData())->GetData();
    return 0;
}
