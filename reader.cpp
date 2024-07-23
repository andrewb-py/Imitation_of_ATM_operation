#include "reader.h"

reader::reader(cl_base* p_head_obj, string s_name): cl_base(p_head_obj, s_name) {}

void reader:: signal(string &message)
{
    if (message == "ready")
    {
        message = "Ready to work";
    }
}

void reader:: handler(string message)
{
    TYPE_SIGNAL signal = SIGNAL_D(reader::signal);
    cl_base* system = search_tree("system");

    if (message == "SHOWTREE" || message == "Turn off the ATM")
    {
        emit_signal(signal, message, search_tree("printer"));
    }

    if (system->mode == 0) // начальная настройка карт
    {
        if (message != "End card loading")
        {
            system->numbers.push_back(message.substr(0, 19));
            system->pins.push_back(message.substr(20, 4));
            system->accounts.push_back(stoi(message.substr(25)));
        }

        else
        {
            system->mode = 1;
        }
    }

    else if (system->mode == 1) // начальная настройка купюр
    {
        if (message != "End money loading")
        {
            istringstream iss(message);
            for (int i{0}; i < 5; i++)
            {
                iss>>system->cash[i];
            }
        }

        else
        {
            system->mode = 2;
            emit_signal(signal, "ready", search_tree("printer"));
        }
    }

    else if (system->mode == 2) // ожидание идентификации карты
    {
        if (message.substr(0, 14) == "Identification") // игнорирование других команд
        {
            system->mode = 2;
            emit_signal(signal, message, search_tree("controller"));
        }

        else
        {
            emit_signal(signal, "ready", search_tree("printer"));
        }
    }

    else if (system->mode == 3) // ожидание пин-кода
    {
        if (message.substr(0, 8) == "PIN-code")
        {
            emit_signal(signal, message, search_tree("controller"));
        }

        else if (message.substr(0, 14) == "Identification")
        {
            system->mode = 2;
            emit_signal(signal, message, search_tree("controller"));
        }

        else
        {
            emit_signal(signal, "ready", search_tree("printer"));
        }
    }

    else if (system->mode == 4 || system->mode == 5) // работа с картой
    {
        emit_signal(signal, message, search_tree("controller"));
    }
}

int reader:: number()
{
    return 1;
}