#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

class cl_base;

#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f)
#define HANDLER_D(handler_f)(TYPE_HANDLER)(&handler_f)

typedef void (cl_base:: *TYPE_SIGNAL)(string& msg);
typedef void (cl_base:: *TYPE_HANDLER)(string msg);

struct o_sh
{
    TYPE_SIGNAL p_signal;
    cl_base* p_target;
    TYPE_HANDLER p_handler;
};


class cl_base
{
    string s_name;
    cl_base* p_head_obj;
    vector<cl_base*> p_sub_objects;
    vector<o_sh*> connects;
    int status{1};

public:
    cl_base(cl_base* p_head_obj, string s_name="Base object");
    bool set_name(string s_new_name);
    string get_name();
    cl_base* get_head_obj();
    cl_base* get_sub_object(string s_name);

    ~cl_base();
    cl_base* search_current(string);
    cl_base* search_tree(string);
    void set_state(int);
    void print_tree(int n=0);
    void print_tree1(int n=0);

    cl_base* find_obj_by_coord(string);
    void delete_sub_object(string);
    bool set_head_obj(cl_base*);

    void set_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER p_handler);
    void delete_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER p_handler);
    void emit_signal(TYPE_SIGNAL p_signal, string s_message, cl_base* p_target);
    string abs_coordinate();
    virtual int number();
    void set_ready_all(int state);

    vector<string> numbers; // ������ ����
    vector<string> pins; // ���-���� ����
    vector<int> accounts; // ����� ����
    vector<int> cash; // ���-�� ����� � ��������� - 5000, 2000, 1000, 500, 100
    vector<int> current_cash; // �������� ������ 5000, 2000, 1000, 500, 100
    int current_card; // ����� �����, � ������� �������� ������� � ������ ������
    int mode = 0;
    /*mode - ����� � ������� �������� ��������
    0 - �������� ��������� ����
    1 - �������� ��������� �����
    2 - �������� �������������
    3 - �������� ����� ���-����
    4 - ������ � ������������������ ������
    5 - ����� �����
    */
};

#endif
