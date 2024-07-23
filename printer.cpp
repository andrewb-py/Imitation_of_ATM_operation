#include "printer.h"

printer::printer(cl_base* p_head_obj, string s_name): cl_base(p_head_obj, s_name) {}

int printer:: number()
{
    return 6;
}

void printer:: handler(string message)
{
    if (message == "SHOWTREE")
    {
        search_tree("system")->print_tree1(4);
        exit(0);
    }

    else if(message == "Turn off the ATM")
    {
        cout << message;
        exit(0);
    }

    else
    {
        cout << message << endl;
    }
}