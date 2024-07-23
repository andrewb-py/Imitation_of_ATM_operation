#ifndef __IDENTIFIER__H
#define __IDENTIFIER__H
#include "cl_base.h"

/*
Объект, моделирующий устройства идентификации банковской карты.
Выдает сигнал, содержащий текст результата идентификации.
*/

class identifier: public cl_base
{
public:
    identifier(cl_base* p_head_obj, string s_name);

    int number();
    void signal(string &message);
    void handler(string message);
};

#endif
