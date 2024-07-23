#include "taker.h"

taker::taker(cl_base* p_head_obj, string s_name): cl_base(p_head_obj, s_name) {}

void taker:: signal(string &message)
{
    cl_base* system = search_tree("system");

    if (message == "Deposit money to the card")
    {
        message = "Card balance " + to_string(system->accounts[system->current_card]);
    }

    else if (message.substr(0, 13) == "Deposit money")
    {
        int sum_current_cash = system->current_cash[0] * 5000 + system->current_cash[1] * 2000 + system->current_cash[2] * 1000 + system->current_cash[3] * 500 + system->current_cash[4] * 100;
        message = "The amount: " + to_string(sum_current_cash);
    }
}

void taker:: handler(string message)
{
    cl_base* system = search_tree("system");
    TYPE_SIGNAL signal = SIGNAL_D(taker::signal);


    if ((message) == "Deposit money to the card")
    {
        for (int i{0}; i < 5; i++)
        {
            system->cash[i] += system->current_cash[i]; // добавление купюр в банкомат
        }

        // запись на карту
        system->accounts[system->current_card] += (system->current_cash[0] * 5000 + system->current_cash[1] * 2000 + system->current_cash[2] * 1000 + system->current_cash[3] * 500 + system->current_cash[4] * 100);

        for (int i{0}; i < 5; i++)
        {
            system->current_cash[i] = 0; // очистка приемника
        }

        system->mode = 4; // перевод системы в режим работы с картой
        emit_signal(signal, message, search_tree("printer"));
    }

    else if (message.substr(0, 13) == "Deposit money")
    {
        int banknote = stoi(message.substr(14)); // значение вносимой купюры
        if (banknote == 5000 || banknote == 2000 || banknote == 1000 || banknote == 500 || banknote == 100)
        {
            if (banknote == 5000)
                system->current_cash[0]++;
            else if (banknote == 2000)
                system->current_cash[1]++;
            else if (banknote == 1000)
                system->current_cash[2]++;
            else if (banknote == 500)
                system->current_cash[3]++;
            else if (banknote == 100)
                system->current_cash[4]++;

            emit_signal(signal, message, search_tree("printer"));
        }
    }

    else if (message == "return money") // введена другая команда => вернуть уже внесенные деньги
    {
        for (int i{0}; i < 5; i++)
        {
            system->current_cash[i] = 0;
        }
        system->mode = 4;
    }
}


int taker:: number()
{
    return 4;
}