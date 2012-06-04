#ifndef TABVERSION_H
#define TABVERSION_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>


#include "Probe.h"

#include "Tab.h"
#include "TabWidgetAssociation.h"

#include "WidgetType.h"
#include "Widget.h"

#include "Unit.h"
#include "UnitType.h"

#include "Value.h"
#include "Information.h"
#include "Plugin.h"
#include "HistoricalValue.h"

#include "Organization.h"

#include "Addon.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

class Tab;
class UnitType;
class TabWidgetAssociation;

class TabVersion : public Table
{
    public:
        TabVersion();
        virtual ~TabVersion();
        
        Wt::Dbo::ptr<Tab> tab;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<TabWidgetAssociation> > tabWidgetAssociations;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, tab, "TAB");
            
            //TJ
            Wt::Dbo::hasMany(a,
                             tabWidgetAssociations,
                             Wt::Dbo::ManyToMany,
                             "TJ_TWG_TVS");
        }
    protected:
    private:
};

#endif // TABVERSION_H
