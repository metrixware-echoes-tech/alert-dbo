#ifndef TAB_H
#define TAB_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "ProbeId.h"
#include "Probe.h"

#include "WidgetType.h"
#include "Widget.h"

#include "Unit.h"
#include "UnitType.h"

#include "HistoricalValue.h"
#include "Value.h"
#include "Plugin.h"
#include "Information.h"

#include "Organization.h"

#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

class Widget;
class TabVersion;
class TabWidgetAssociation;

class Tab : public Table
{
    public:
        Tab();
        virtual ~Tab();
        Wt::Dbo::ptr<Widget> widget;
        Wt::Dbo::ptr<TabWidgetAssociation> tabWidgetAssociation;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Widget> > widgets;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<TabVersion> > tabVersions;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, widget, "WGT");
            
            Wt::Dbo::belongsTo(a,tabWidgetAssociation,"TWG2");
            
            Wt::Dbo::hasMany(a,
                             tabVersions,
                             Wt::Dbo::ManyToOne,
                             "TAB");
            //TJ
            Wt::Dbo::hasMany(a,
                             widgets,
                             Wt::Dbo::ManyToMany,
                             "TJ_TAB_WGT");
        }
    protected:
    private:
};

#endif // TAB_H
