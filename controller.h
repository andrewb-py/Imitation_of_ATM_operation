#ifndef __CONTROLLER__H
#define __CONTROLLER__H
#include "cl_base.h"

/*
������ ������ ����������, ��� ��������� ������� ������ (������).
������ ����� ������� ������ ����������� ����������� ��� ���������� � ������ ��������������� ������.
������ ������ ���� ����������� ��� ������ ����� �� ������ 100 ��� �� ����� ��� ����������� �������.
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
