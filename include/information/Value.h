#ifndef VALUE_H
#define VALUE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Table.h"

#include "Unit.h"

#include "Probe.h"
#include "ProbeId.h"

#include "Information.h"
#include "Plugin.h"
#include "HistoricalValue.h"

#include "Organization.h"

#include "WidgetType.h"
#include "Widget.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

class Plugin;
class Probe;
class Information2;

class Value : public Table
{
    public:
        Value();
        virtual ~Value();

        Wt::Dbo::ptr<Plugin> plugin;
        Wt::Dbo::ptr<Probe> probe;
        Wt::Dbo::ptr<Information2> information;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, plugin, "VOR");
            Wt::Dbo::belongsTo(a, probe, "VPR");
            Wt::Dbo::belongsTo(a, information, "VIN");
        }

    protected:
    private:
};

#endif // VALUE_H
