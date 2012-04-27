#ifndef HISTORICALVALUE_H
#define HISTORICALVALUE_H

#include <Wt/Dbo/Dbo>

#include "Table.h"

class Plugin;
//class Probe;
class Information2;

class HistoricalValue : public Table
{
    public:
        HistoricalValue();
        virtual ~HistoricalValue();

        Wt::Dbo::ptr<Plugin> plugin;
//        Wt::Dbo::ptr<Probe> probe;
        Wt::Dbo::ptr<Information2> information;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, plugin, "HOR");
//            Wt::Dbo::belongsTo(a, probe, "HPR");
            Wt::Dbo::belongsTo(a, information, "HIN");
        }

    protected:
    private:
};

#endif // HISTORICALVALUE_H
