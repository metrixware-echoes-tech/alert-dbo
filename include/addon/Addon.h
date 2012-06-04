#ifndef ADDON_H
#define ADDON_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Unit.h"


#include "Probe.h"

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

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

class Plugin;

class Addon : public Table
{
    public:
        Addon();
        virtual ~Addon();
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Source> > sources;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             sources,
                             Wt::Dbo::ManyToOne,
                             "SRC"); 
        }
    protected:
    private:
};

#endif // ADDON_H
