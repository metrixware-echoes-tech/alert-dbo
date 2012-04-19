#ifndef INFORMATION_H
#define INFORMATION_H

#include "Value.h"
#include "HistoricalValue.h"
#include "Plugin.h"

class Value;
class HistoricalValue;
class Plugin;


class Information2 : public Table
{
    public:
        Information2();
        virtual ~Information2();

        Wt::Dbo::collection<Wt::Dbo::ptr<Value>> values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue>> historicalValues;
        //TJ
        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin>> plugins;


        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             "VIN");
            Wt::Dbo::hasMany(a,
                             historicalValues,
                             Wt::Dbo::ManyToOne,
                             "HIN");

            //TJ

            Wt::Dbo::hasMany(a,
                             plugins,
                             Wt::Dbo::ManyToMany,
                             "TJ_INF_PLG");

        }
    protected:
    private:
};

#endif // INFORMATION_H
