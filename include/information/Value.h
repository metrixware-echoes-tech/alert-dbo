#ifndef VALUE_H
#define VALUE_H

#include "Table.h"

class Plugin;
class Probe;
class Information2;

class Value : public Table
{
    public:
        Value();
        virtual ~Value();

        Wt::Dbo::ptr<Plugin> plugin;
        Wt::Dbo::ptr<Probe> probe;
        Wt::Dbo::ptr<Information2> information;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, plugin, "VOR");
            Wt::Dbo::belongsTo(a, probe, "VPR");
            Wt::Dbo::belongsTo(a, information, "VIN");
        }

    protected:
    private:
};

#endif // VALUE_H
