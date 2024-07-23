#ifndef __GIVER__H
#define __GIVER__H
#include "cl_base.h"

/*
Объект, моделирующий устройства выдачи денег.
Выдает сигнал, содержащий количество купюр возвращаемой суммы или информацию о невозможности получить необходимый состав купюр.
*/

class giver: public cl_base
{
public:
    giver(cl_base* p_head_obj, string s_name);

    int number();
    void signal(string &message);
    void handler(string message);
};


#endif
