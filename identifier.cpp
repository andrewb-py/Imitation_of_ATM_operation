#include "identifier.h"

identifier::identifier(cl_base* p_head_obj, string s_name): cl_base(p_head_obj, s_name) {}


void identifier:: signal(string &message)
{
    if (message.substr(0, 14) == "Identification")
        message = "Enter the PIN code";
    else if (message.substr(0, 8) == "PIN-code")
        message = "Select the command";
}


void identifier:: handler(string message)
{
    TYPE_SIGNAL signal = SIGNAL_D(identifier::signal);
    cl_base* system = search_tree("system");

    if (message.substr(0, 14) == "Identification")
    {
        string card_number = message.substr(15);
        for (int i{0}; i < system->numbers.size(); i++)
        {
            if (system->numbers[i] == card_number)
            {
                system->current_card = i;
                system->mode = 3;
                emit_signal(signal, message, search_tree("printer"));
            }
        }
    }
    else if (message.substr(0, 8) == "PIN-code")
    {
        if (message.substr(9) == system->pins[system->current_card])
        {
            system->mode = 4;
            emit_signal(signal, message, search_tree("printer"));
        }
    }
}


int identifier:: number()
{
    return 3;
}