#include "cl_base.h"


cl_base::cl_base(cl_base* p_head_obj, string s_name)
{
    /*
    Описание: параметризированный конструктор
    Параметры:
        p_head_obj - указатель на головной объект
        s_name - имя узла дерева
    */

    this -> s_name = s_name;
    this -> p_head_obj = p_head_obj;

    if (p_head_obj)
        p_head_obj -> p_sub_objects.push_back(this);
}


bool cl_base::set_name(string s_new_name)
{
    /*
    Описание: метод редактирования имени объекта
    Параметры:
        s_new_name - новое имя узла дерева
        */

    if (this -> p_head_obj)
        for (int i{0}; i < p_head_obj -> p_sub_objects.size(); i++)
            if (p_head_obj -> p_sub_objects[i] -> get_name() == s_new_name)
                return false;
    this -> s_name = s_new_name;
    return true;
}


string cl_base:: get_name()
{
    return s_name;
}


cl_base* cl_base:: get_head_obj()
{
    return p_head_obj;
}


cl_base::~cl_base()
{
    for (int i{0}; i < p_sub_objects.size(); i++)
        delete p_sub_objects[i];
}


cl_base* cl_base::get_sub_object(string s_name)
{
    /*
        Описание: получение указателя на непосредственно подчиненный объект по имени
        Параметры:
            s_name - имя искомого объекта
        */
    for (int i{0}; i < p_sub_objects.size(); i++)
        if (p_sub_objects[i] -> get_name() == s_name)
            return p_sub_objects[i];
    return nullptr;
}


void cl_base::print_tree(int n)
{
    /*
        Описание: вывод дерева иерархии объектов
        */

    for (auto p_sub : this->p_sub_objects)
    {
        cout << '\n';
        for (int i{0}; i < n; i++)
            cout << ' ';
        cout << p_sub->get_name();
        if (p_sub->p_sub_objects.size() > 0)
            p_sub->print_tree(n + 4);
    }
}


void cl_base::print_tree1(int n)
{
    /*
        Описание: вывод дерева иерархии объектов с состояниями
        */

    cout << '\n';
    for (int i{0}; i < n - 4; i++)
        cout << ' ';
    cout << this->get_name();
    if (this->status != 0)
        cout << " is ready";
    else
        cout << " is not ready";

    for (auto p_sub : this->p_sub_objects)
    {
        if (p_sub->p_sub_objects.size() > 0)
        {
            p_sub->print_tree1(n + 4);
            continue;
        }
        cout << '\n';
        for (int i{0}; i < n; i++)
            cout << " ";
        cout << p_sub->get_name();
        if (p_sub->status != 0)
            cout << " is ready";
        else
            cout << " is not ready";
    }
}


cl_base* cl_base::search_current(string s_name)
{
    /*
        Описание: поиск объекта по имени в поддереве.
        Параметры:
            s_name - имя искомого объекта
        */

    cl_base* p_found = nullptr;
    queue<cl_base*> q;

    q.push(this);

    while(!q.empty())
    {
        cl_base* p_front = q.front();
        q.pop();
        if (p_front->get_name() == s_name)
            if (p_found == nullptr)
                p_found = p_front;
            else
                return nullptr;

        for (auto p_sub : p_front->p_sub_objects)
            q.push(p_sub);
    }
    return p_found;
}


cl_base* cl_base:: search_tree(string s_name)
{
    /*
            Описание: поиск объекта по имени во всем дереве.
            Параметры:
                s_name - имя искомого объекта
        */
    cl_base* p_root = this;
    while (p_root->get_head_obj() != nullptr)
        p_root = p_root->get_head_obj();

    return p_root->search_current(s_name);
}


void cl_base:: set_state(int state)
{

    if (state != 0)
    {
        cl_base* p_root = this;
        this->status = state;
        while (p_root -> get_head_obj() != nullptr)
        {
            p_root = p_root->get_head_obj();
            if (p_root->status == 0)
                this -> status = 0;
        }
    }
    else
    {
        this->status = 0;
        if (p_sub_objects.size() != 0)
        {
            for (int i{0}; i < p_sub_objects.size(); i++)
                p_sub_objects[i]->set_state(0);
        }
    }
}


cl_base* cl_base:: find_obj_by_coord(string s_coord)
{
    /*
        Описание: поиск объекта по координате.
        Параметры:
            s_coord - координата искомого объекта
        */
    cl_base* p_root = this;
    int i_slash_2 = 0;
    string s_name;
    cl_base* p_obj;

    if (s_coord == "/")
    {
        while (p_root->get_head_obj() != nullptr)
            p_root = p_root->get_head_obj();
        return p_root;
    }

    if (s_coord == ".")
        return this;

    if (s_coord[0] == '/' && s_coord[1] == '/')
        return this->search_tree(s_coord.substr(2));

    if (s_coord[0] == '.')
        return this->search_current(s_coord.substr(1));

    i_slash_2 = s_coord.find("/", 1);
    if (s_coord[0] == '/')
    {
        while (p_root->get_head_obj() != nullptr)
            p_root = p_root->get_head_obj();
        if (i_slash_2 != -1)
        {
            s_name = s_coord.substr(1, i_slash_2 - 1);
            p_obj = p_root->get_sub_object(s_name);
            if (p_obj != nullptr)
                return p_obj -> find_obj_by_coord(s_coord.substr(i_slash_2 + 1));
            else
                return p_obj;
        }
        else
        {
            return p_root->get_sub_object(s_coord.substr(1));
        }
    }
    else
    {
        if (i_slash_2 != -1)
        {
            s_name = s_coord.substr(0, i_slash_2);
            p_obj = this->get_sub_object(s_name);
            if (p_obj != nullptr)
                return p_obj -> find_obj_by_coord(s_coord.substr(i_slash_2 + 1));
            else
                return p_obj;
        }
        else
        {
            return this->get_sub_object(s_coord);
        }
    }

    return nullptr;
}


void cl_base:: delete_sub_object(string s_name)
{
    /*
        Описание: удаление подчиненного объекта по имени.
        Параметры:
            s_name - имя удаляемого объекта
        */
    for (int i = 0; i < p_sub_objects.size(); i++)
    {
        if (p_sub_objects[i]->get_name() == s_name)
        {
            p_sub_objects.erase(p_sub_objects.begin() + i);
            i--;
        }
    }
}


bool cl_base:: set_head_obj(cl_base* p_new_head)
{
    /*
        Описание: переопределение головного объекта.
        Параметры:
            p_new_head - имя нового головного объекта
        */
    cl_base* p_temp = p_new_head;

    if (this->get_head_obj() == nullptr)
        return false;

    if (p_new_head == nullptr)
        return false;

    if (p_new_head->get_sub_object(this->get_name()) != nullptr)
        return false;

    while (p_temp != nullptr)
        if (p_temp == this)
            return false;
        else
            p_temp = p_temp->get_head_obj();

    this->get_head_obj()->delete_sub_object(this->get_name());
    this->p_head_obj = p_new_head;
    this->p_head_obj->p_sub_objects.push_back(this);
    return true;
}


void cl_base:: set_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER p_handler)
{
    o_sh* p_value;
    for (int i{0}; i < connects.size(); i++)
        if (connects[i]->p_signal == p_signal &&
            connects[i]->p_target == p_target &&
            connects[i]->p_handler == p_handler)
            return;

    p_value = new o_sh();

    p_value->p_signal = p_signal;
    p_value->p_target = p_target;
    p_value->p_handler = p_handler;

    connects.push_back(p_value);
}


void cl_base:: delete_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER p_handler)
{
    for (int i{0}; i < connects.size(); ++i)
    {
        if (connects[i]->p_signal == p_signal && connects[i]->p_target == p_target && connects[i]->p_handler == p_handler)
        {
            delete connects[i];
            connects.erase(connects.begin() + i);
            return;
        }
    }
}


void cl_base:: emit_signal(TYPE_SIGNAL p_signal, string s_message, cl_base* p_target)
{
    if (this->status == 0)
        return;
    (this->*p_signal)(s_message);
    for (int i{0}; i < connects.size(); i++)
    {
        if (connects[i]->p_signal == p_signal && connects[i]->p_target == p_target)
        {
            TYPE_HANDLER p_handler = connects[i]->p_handler;
            cl_base* target_ptr = connects[i]->p_target;
            if (target_ptr->status != 0)
                (target_ptr->*p_handler)(s_message);
        }
    }
}


string cl_base:: abs_coordinate()
{
    string path;
    stack<string> buf;
    cl_base* p_root = this;
    while (p_root->get_head_obj() != nullptr)
    {
        buf.push(p_root->get_name());
        p_root = p_root->get_head_obj();
    }
    while (!buf.empty())
    {
        path += "/" + buf.top();
        buf.pop();
    }
    if (path.empty())
        return "/";
    return path;
}


int cl_base:: number()
{
    return 0;
}


void cl_base:: set_ready_all(int state)
{
    if (get_head_obj() != nullptr && get_head_obj()->status == 0)
        return;
    set_state(state);
    for (int i{0}; i < p_sub_objects.size(); i++)
        p_sub_objects[i]->set_ready_all(state);
}
