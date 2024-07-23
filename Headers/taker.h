#ifndef __TAKER__H
#define __TAKER__H
#include "cl_base.h"

/*
������, ������������ ���������� ������ �����.
����� �������� ��������� ������ ��������� ���.
��� �������� ����� ������ ���������� ������������.
������ ������, ���������� ����� ��������� ����� ��� ����������� �� �����.
*/

class taker: public cl_base
{
public:
    taker(cl_base* p_head_obj, string s_name);

    int number();
    void signal(string &message);
    void handler(string message);
};

#endif
