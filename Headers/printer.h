#ifndef __PRINTER__H
#define __PRINTER__H
#include "cl_base.h"

/*
������ ��� ������ ��������� ��� ���������� �������� ��������� �� �������.
*/

class printer: public cl_base
{
public:
    printer(cl_base* p_head_obj, string s_name);

    int number();
    void handler(string message);
};


#endif
