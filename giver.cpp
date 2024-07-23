#include "giver.h"

giver::giver(cl_base* p_head_obj, string s_name): cl_base(p_head_obj, s_name) {}


void giver:: signal(string &message)
{
    if (message == "no money")
    {
        message = "There is not enough money in the ATM";
    }
    else
    {
        istringstream iss(message);
        int count5000, count2000, count1000, count500, count100;
        iss >> count5000 >> count2000 >> count1000 >> count500 >> count100;
        message = "Take the money: 5000 * " + to_string(count5000) + " rub., 2000 * " + to_string(count2000) + " rub., 1000 * " + to_string(count1000) + " rub., 500 * " + to_string(count500) + " rub., 100 * " + to_string(count100) + " rub.";
    }
}

void giver:: handler(string message)
{
    TYPE_SIGNAL signal = SIGNAL_D(giver::signal);

    cl_base* system = search_tree("system");
    int amount = stoi(message.substr(15)); // запрошенная сумма для снятия
    vector<int> cash_to_give = {0, 0, 0, 0, 0}; // купюры для выдачи

    int withdraw5000 = min(amount / 5000, system->cash[0]);
    amount -= withdraw5000 * 5000;

    int withdraw2000 = min(amount / 2000, system->cash[1]);
    amount -= withdraw2000 * 2000;

    int withdraw1000 = min(amount / 1000, system->cash[2]);
    amount -= withdraw1000 * 1000;

    int withdraw500 = min(amount / 500, system->cash[3]);
    amount -= withdraw500 * 500;

    int withdraw100 = min(amount / 100, system->cash[4]);
    amount -= withdraw100 * 100;

    if (amount == 0)
    {
        string line = to_string(withdraw5000) + " " + to_string(withdraw2000) + " " + to_string(withdraw1000) + " " + to_string(withdraw500) + " " + to_string(withdraw100);
        system->accounts[system->current_card] -= (withdraw5000 * 5000 + withdraw2000 * 2000 + withdraw1000 * 1000 + withdraw500 * 500 + withdraw100 * 100);
        emit_signal(signal, line, search_tree("printer"));
    }

    else
    {
        emit_signal(signal, "no money", search_tree("printer"));
    }
}


int giver:: number()
{
    return 5;
}