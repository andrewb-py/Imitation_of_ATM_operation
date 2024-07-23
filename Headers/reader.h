#ifndef __READER__H
#define __READER__H
#include "cl_base.h"

/*
Объект для чтения команд и данных.
Считывает данные для подготовки и настройки банкомата.
После чтения очередной порции данных для настройки или данных команды, объект выдает сигнал с текстом полученных данных.
Все данные настройки и данные команды синтаксический корректны.
*/

class reader: public cl_base
{
public:
    reader(cl_base* p_head_obj, string s_name);

    int number();
    void signal(string &message); // метод сигнала
    void handler(string message); // метод обработчика
};


#endif