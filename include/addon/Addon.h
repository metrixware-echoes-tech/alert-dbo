#ifndef ADDON_H
#define ADDON_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Unit.h"

#include "Probe.h"
#include "ProbeId.h"

#include "Plugin.h"

#include "Value.h"
#include "Information.h"
#include "Plugin.h"
#include "HistoricalValue.h"

#include "UnitType.h"

#include "Organization.h"

#include "WidgetType.h"
#include "Widget.h"

#include "Tab.h"
#include "TabWidgetAssociation.h"
#include "TabVersion.h"

class Plugin;

class Addon : public Table
{
    public:
        Addon();
        virtual ~Addon();
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;
        
        template<class Action>
        void persist(Action& a)
        {
            //TJ
            Wt::Dbo::hasMany(a,
                             plugins,
                             Wt::Dbo::ManyToMany,
                             "TJ_ADO_PLG"); 
        }
    protected:
    private:
};

#endif // ADDON_H
