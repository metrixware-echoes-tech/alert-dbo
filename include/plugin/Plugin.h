#ifndef PLUGIN_H
#define PLUGIN_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "Value.h"
#include "HistoricalValue.h"
#include "Information.h"

class Value;
class HistoricalValue;
class Information2;

class Plugin
{
    public:
        Plugin();
        virtual ~Plugin();

        Wt::Dbo::collection<Wt::Dbo::ptr<Value>> values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue>> historicalValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<Information2>> informations;

        template<class Action>
        void persist(Action& a)
        {
            //User id as foreign key in other tables
            Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             "VPL");
            Wt::Dbo::hasMany(a,
                             historicalValues,
                             Wt::Dbo::ManyToOne,
                             "HPL");

            //TJ
            Wt::Dbo::hasMany(a,
                             informations,
                             Wt::Dbo::ManyToMany,
                             "TJ_INF_PLG");
       }
    protected:
    private:
};

#endif // PLUGIN_H
