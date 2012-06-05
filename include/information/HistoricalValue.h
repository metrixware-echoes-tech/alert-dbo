#ifndef HISTORICALVALUE_H
#define HISTORICALVALUE_H

#include <Wt/Dbo/Dbo>

#include "Table.h"


#include "Probe.h"

#include "Information.h"
#include "Plugin.h"
#include "Value.h"

#include "Organization.h"

#include "Widget.h"
#include "WidgetType.h"

#include "Unit.h"
#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

#include "Asset.h"

class Plugin;
class Probe;
class Information2;

class HistoricalValue : public Table
{
    public:
        HistoricalValue();
        virtual ~HistoricalValue();
        
        static std::string TRIGRAM;

        Wt::Dbo::ptr<Probe> probe;
        Wt::Dbo::ptr<Information2> information;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, probe, "HPR");
            Wt::Dbo::belongsTo(a, information, "HIN");
        }

    protected:
    private:
};

#endif // HISTORICALVALUE_H
