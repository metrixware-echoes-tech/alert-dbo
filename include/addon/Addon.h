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

#include "Asset.h"

class Plugin;

class Addon : public Table
{
    public:
        Addon();
        virtual ~Addon();
        
        static std::string TRIGRAM;
        
        std::string name;
        Wt::WDateTime deleteTag;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Source> > sources;
        Wt::Dbo::collection<Wt::Dbo::ptr<SourceParameter> > sourceParameters;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             sources,
                             Wt::Dbo::ManyToOne,
                             "SRC"); 
            
            //TJ
            Wt::Dbo::hasMany(a,
                             sourceParameters,
                             Wt::Dbo::ManyToMany,
                             "TJ_ADO_SRP"); 
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesDates["DELETE"]=this->deleteTag;
        }
    protected:
    private:
};

#endif // ADDON_H
