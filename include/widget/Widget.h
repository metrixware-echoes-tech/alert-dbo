#ifndef WIDGET_H
#define WIDGET_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>


#include "Probe.h"

#include "Unit.h"
#include "UnitType.h"

#include "HistoricalValue.h"
#include "Value.h"
#include "Information.h"

#include "Plugin.h"

#include "Organization.h"

#include "WidgetType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

class WidgetType;
class Tab;
class TabWidgetAssociation;

class Widget : public Table
{
    public:
        Widget();
        virtual ~Widget();
        Wt::Dbo::ptr<TabWidgetAssociation> tabWidgetAssociation;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<WidgetType> > widgetTypes;
        Wt::Dbo::collection<Wt::Dbo::ptr<Tab> > tabs;
        
        template<class Action>
        void persist(Action& a)
        {   
            Wt::Dbo::belongsTo(a,tabWidgetAssociation,"TWG1");
            Wt::Dbo::hasMany(a,
                             widgetTypes,
                             Wt::Dbo::ManyToOne,
                             "WGT");
            //TJ
            Wt::Dbo::hasMany(a,
                             tabs,
                             Wt::Dbo::ManyToMany,
                             "TJ_TAB_WGT");
        }
    protected:
    private:
};

#endif // WIDGET_H
