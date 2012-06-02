#ifndef UNITTYPE_H
#define UNITTYPE_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "ProbeId.h"
#include "Probe.h"

#include "Unit.h"

#include "HistoricalValue.h"
#include "Value.h"
#include "Plugin.h"
#include "Information.h"

#include "Organization.h"

#include "WidgetType.h"
#include "Widget.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

class Unit;
class WidgetType;

class UnitType : public Table
{
    public:
        UnitType();
        virtual ~UnitType();
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Unit> > units;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<WidgetType> > widgetTypes;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             units,
                             Wt::Dbo::ManyToOne,
                             "UUN");
            

            //TJ
            Wt::Dbo::hasMany(a,
                             widgetTypes,
                             Wt::Dbo::ManyToMany,
                             "TJ_WTY_UTY");

            
        }
    protected:
    private:
};

#endif // UNITTYPE_H
