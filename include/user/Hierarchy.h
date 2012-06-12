#ifndef HIERARCHY_H
#define HIERARCHY_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "User.h"

#include "UserAction.h"
#include "UserProfile.h"
#include "UserRole.h"
#include "UserField.h"
#include "UserValue.h"

#include "HistoricalAction.h"

#include "Organization.h"


#include "Probe.h"

#include "Plugin.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "Widget.h"
#include "WidgetType.h"

#include "Unit.h"
#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "UserValueId.h"
#include "HierarchyId.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

#include "Asset.h"
//class User;

class Hierarchy : public Table
{
    public:
        Hierarchy();
        virtual ~Hierarchy();
        
        static std::string TRIGRAM;
        
        Wt::WDateTime deleteTag;
        //RHI : PK/FK USR_ID and USR_ID_CHILD to add

        HierarchyId pk;

        template<class Action>
        void persist(Action& a)
        {

            Wt::Dbo::id (a, pk, "PRIMARY_KEY");
            mapClassAttributesDates["DELETE"]=this->deleteTag;
        }
    protected:
    private:
};

#endif // HIERARCHY_H
