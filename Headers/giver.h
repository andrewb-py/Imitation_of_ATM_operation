#ifndef __GIVER__H
#define __GIVER__H
#include "cl_base.h"

/*
������, ������������ ���������� ������ �����.
������ ������, ���������� ���������� ����� ������������ ����� ��� ���������� � ������������� �������� ����������� ������ �����.
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
