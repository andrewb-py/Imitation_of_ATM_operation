#ifndef __READER__H
#define __READER__H
#include "cl_base.h"

/*
������ ��� ������ ������ � ������.
��������� ������ ��� ���������� � ��������� ���������.
����� ������ ��������� ������ ������ ��� ��������� ��� ������ �������, ������ ������ ������ � ������� ���������� ������.
��� ������ ��������� � ������ ������� �������������� ���������.
*/

class reader: public cl_base
{
public:
    reader(cl_base* p_head_obj, string s_name);

    int number();
    void signal(string &message); // ����� �������
    void handler(string message); // ����� �����������
};


#endif