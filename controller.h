#ifndef __CONTROLLER__H
#define __CONTROLLER__H
#include "cl_base.h"

/*
Объект пульта управления, для отработки нажатия кнопок (команд).
Объект после нажатия кнопки анализирует возможность его выполнения и выдает соответствующий сигнал.
Выдает сигнал если запрошенная для снятия сумма не кратна 100 или на карте нет достаточных средств.
*/

class controller: public cl_base
{
public:
    controller(cl_base* p_head_obj, string s_name);

    int number();
    void signal(string &message);
    void handler(string message);
};


#endif
