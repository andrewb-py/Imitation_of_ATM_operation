#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include "cl_base.h"
#include "reader.h"
#include "controller.h"
#include "identifier.h"
#include "taker.h"
#include "giver.h"
#include "printer.h"

/*
Объект «система».
*/

class cl_application: public cl_base
{
public:
    cl_application(cl_base* p_head_obj);
    int exec_app();

    int number();
    void signal(string &message);
    void build_tree_objects();
};

#endif
