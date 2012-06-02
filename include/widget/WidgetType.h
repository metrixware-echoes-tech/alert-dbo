#ifndef WIDGETTYPE_H
#define WIDGETTYPE_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "User.h"

#include "UnitType.h"
#include "Unit.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "Plugin.h"

#include "Organization.h"

#include "Widget.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

class UnitType;
class Widget;

class WidgetType : public Table
{
    public:
        WidgetType();
        virtual ~WidgetType();
        
        Wt::Dbo::ptr<Widget> widget;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<UnitType> > unitTypes;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, widget, "WGT");
            //TJ
            Wt::Dbo::hasMany(a,
                             unitTypes,
                             Wt::Dbo::ManyToMany,
                             "TJ_WTY_UTY");
        }
    protected:
    private:
};

#endif // WIDGETTYPE_H
