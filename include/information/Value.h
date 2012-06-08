#ifndef VALUE_H
#define VALUE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Table.h"

#include "Unit.h"


#include "Probe.h"

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

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

#include "Asset.h"

#include "Syslog.h"

#include "InformationId.h"

class Plugin;
class Probe;
class Asset;
class Syslog;
//class Information2;



class Value : public Table
{
    public:
        Value();
        virtual ~Value();
        
        static std::string TRIGRAM;
        
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<Syslog> syslog;
        InformationId informationId;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::field(a, informationId.searchId.id, "SEA_ID");
            Wt::Dbo::field(a, informationId.searchId.sourceId.id, "SRC_ID");
            Wt::Dbo::field(a, informationId.searchId.sourceId.plugin, "PLG_ID");
            Wt::Dbo::belongsTo(a, asset, "VAL_AST");
            Wt::Dbo::belongsTo(a, syslog, "VAL_SLO");
        }

    protected:
    private:
};

#endif // VALUE_H
