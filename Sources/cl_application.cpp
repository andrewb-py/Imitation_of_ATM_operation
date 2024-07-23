#include "cl_application.h"

cl_application::cl_application(cl_base* p_head_obj): cl_base(p_head_obj)
{}


void cl_application:: signal(string &message)
{}

void cl_application:: build_tree_objects()
{
    /*
    Описание: метод построения системы объектов.
    */
    this->set_name("system");
    new reader(this, "reader");
    new controller(this, "controller");
    new identifier(this, "identifier");
    new giver(this, "giver");
    new taker(this, "taker");
    new printer(this, "printer");

    search_tree("system")->set_connection((TYPE_SIGNAL)(&reader::signal), search_tree("reader"), (TYPE_HANDLER)(&reader::handler));
    search_tree("system")->set_connection((TYPE_SIGNAL)(&cl_application::signal), search_tree("printer"), (TYPE_HANDLER)(&printer::handler));

    search_tree("reader")->set_connection((TYPE_SIGNAL)(&reader::signal), search_tree("controller"), (TYPE_HANDLER)(&controller::handler));
    search_tree("reader")->set_connection((TYPE_SIGNAL)(&reader::signal), search_tree("printer"), (TYPE_HANDLER)(&printer::handler));


    search_tree("controller")->set_connection((TYPE_SIGNAL)(&controller::signal), search_tree("identifier"), (TYPE_HANDLER)(&identifier::handler));
    search_tree("controller")->set_connection((TYPE_SIGNAL)(&controller::signal), search_tree("giver"), (TYPE_HANDLER)(&giver::handler));
    search_tree("controller")->set_connection((TYPE_SIGNAL)(&controller::signal), search_tree("taker"), (TYPE_HANDLER)(&taker::handler));
    search_tree("controller")->set_connection((TYPE_SIGNAL)(&controller::signal), search_tree("printer"), (TYPE_HANDLER)(&printer::handler));

    search_tree("identifier")->set_connection((TYPE_SIGNAL)(&identifier::signal), search_tree("printer"), (TYPE_HANDLER)(&printer::handler));

    search_tree("taker")->set_connection((TYPE_SIGNAL)(&taker::signal), search_tree("printer"), (TYPE_HANDLER)(&printer::handler));

    search_tree("giver")->set_connection((TYPE_SIGNAL)(&giver::signal), search_tree("printer"), (TYPE_HANDLER)(&printer::handler));
}

int cl_application:: exec_app()
{
    cash = {0, 0, 0, 0, 0};
    current_cash = {0, 0, 0, 0, 0};
    string line;

    do
    {
        getline(cin, line);
        search_tree("system")->emit_signal((TYPE_SIGNAL)(&reader::signal), line, search_tree("reader"));
    }
    while (line != "End money loading");

    do
    {
        getline(cin, line);
        search_tree("system")->emit_signal((TYPE_SIGNAL)(&reader::signal), line, search_tree("reader"));
    }
    while (line != "Turn off the ATM" || line != "SHOWTREE");


    return 0;
}


int cl_application:: number()
{
    return 1;
}
