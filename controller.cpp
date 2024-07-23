#include "controller.h"

controller::controller(cl_base* p_head_obj, string s_name): cl_base(p_head_obj, s_name) {}


void controller:: signal(string &message)
{
    if (message == "End the session")
    {
        message = "Ready to work";
    }

    if (message == "not 100")
    {
        message = "The amount is not a multiple of 100";
    }

    if (message == "no money")
    {
        message = "There is not enough money on the card";
    }
}


void controller:: handler(string message)
{
    TYPE_SIGNAL signal = SIGNAL_D(controller::signal);
    cl_base* system = search_tree("system");

    if (message.substr(0, 13) != "Deposit money" && search_tree("system")->mode == 5) // если прием денег сбивается другой командой
    {
        emit_signal(signal, "return money", search_tree("taker"));
    }


    if (message == "End the session")
    {
        search_tree("system")->mode = 2;
        emit_signal(signal, message, search_tree("printer"));
    }

    if (message.substr(0, 14) == "Identification")
    {
        emit_signal(signal, message, search_tree("identifier"));
    }

    if (message.substr(0, 8) == "PIN-code")
    {
        emit_signal(signal, message, search_tree("identifier"));
    }

    if (message.substr(0, 13) == "Deposit money")
    {
        search_tree("system")->mode = 5;
        emit_signal(signal, message, search_tree("taker"));
    }

    if (message.substr(0, 14) == "Withdraw money")
    {
        int amount = stoi(message.substr(15)); // запрошенная сумма для снятия

        if (amount % 100 != 0)
        {
            emit_signal(signal, "not 100", search_tree("printer"));
        }

        else if (system->accounts[system->current_card] < amount)
        {
            emit_signal(signal, "no money", search_tree("printer"));
        }

        else
        {
            emit_signal(signal, message, search_tree("giver"));
        }
    }
}


int controller:: number()
{
    return 2;
}