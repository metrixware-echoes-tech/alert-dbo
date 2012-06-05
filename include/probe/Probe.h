#ifndef PROBE_H
#define PROBE_H

#include "Table.h"
#include <Wt/Dbo/Dbo>

#include "Probe.h"


#include "Unit.h"
#include "Organization.h"

#include "Plugin.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "WidgetType.h"
#include "Widget.h"
#include "WidgetValueId.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

#include "Asset.h"

#include "Syslog.h"

class Organization;
class Value;
class HistoricalValue;

class Probe : public Table
{
    public:
        Probe();
        virtual ~Probe();

//        ProbeId pk;
        
        Wt::Dbo::ptr<Organization> organization;

        Wt::Dbo::collection<Wt::Dbo::ptr<Value> > values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue> > historicalValues;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Syslog> > syslogs;

        template<class Action>
        void persist(Action& a)
        {
//            Wt::Dbo::id (a, pk, "PRIMARY_KEY");
            Wt::Dbo::belongsTo(a, organization, "ORG");

            Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             "VPR");
            Wt::Dbo::hasMany(a,
                             historicalValues,
                             Wt::Dbo::ManyToOne,
                             "HPR");
            Wt::Dbo::hasMany(a,
                             syslogs,
                             Wt::Dbo::ManyToOne,
                             "PRB");
        };

    protected:
    private:
};

#endif // PROBE_H
