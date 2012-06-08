#ifndef PLUGIN_H
#define PLUGIN_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "Table.h"

#include "Unit.h"


#include "Probe.h"

#include "Organization.h"

#include "HistoricalValue.h"
#include "Value.h"
#include "Information.h"

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

class Source;
class Asset;

class Plugin : public Table
{
    public:
        Plugin();
        virtual ~Plugin();

        Wt::Dbo::collection<Wt::Dbo::ptr<Source> > sources;
        Wt::Dbo::collection<Wt::Dbo::ptr<Asset> > assets;

        template<class Action>
        void persist(Action& a)
        {
            //Plugin id as foreign key in other tables
            Wt::Dbo::hasMany(a,
                             sources,
                             Wt::Dbo::ManyToOne,
                             "SRC_PLG");
            
            //TJ
            Wt::Dbo::hasMany(a,
                             assets,
                             Wt::Dbo::ManyToMany,
                             "TJ_AST_PLG");
       }
    protected:
    private:
};

#endif // PLUGIN_H
