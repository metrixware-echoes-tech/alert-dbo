#ifndef INFORMATION_H
#define INFORMATION_H

#include "Table.h"

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Probe.h"
#include "ProbeId.h"

#include "HistoricalValue.h"
#include "Value.h"
#include "Plugin.h"

#include "Organization.h"

#include "Widget.h"
#include "WidgetType.h"

#include "Unit.h"
#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

class Value;
class HistoricalValue;
class Plugin;
class Unit;


class Information2 : public Table
{
    public:
        Information2();
        virtual ~Information2();
        
        Wt::Dbo::ptr<Unit> unit;

        Wt::Dbo::collection<Wt::Dbo::ptr<Value> > values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue> > historicalValues;
        //TJ
        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;


        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, unit, "UIN");
            
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
