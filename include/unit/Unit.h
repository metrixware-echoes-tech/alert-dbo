#ifndef UNIT_H
#define UNIT_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "UserField.h"
#include "UserProfile.h"
#include "UserRole.h"
#include "User.h"

#include "Constants.h"
#include "Hierarchy.h"
#include "HistoricalAction.h"
#include "UserAction.h"
#include "UserValue.h"
#include "UserValueId.h"
#include "HistoricalAction.h"

#include "Organization.h"

#include "Probe.h"
#include "ProbeId.h"

#include "Plugin.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "WidgetType.h"
#include "Widget.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

class Information2;
class UnitType;

class Unit : public Table
{
    public:
        Unit();
        virtual ~Unit();
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Information2> > informations;
        Wt::Dbo::ptr<UnitType> unitType;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, unitType, "UUN");
            
            Wt::Dbo::hasMany(a,
                             informations,
                             Wt::Dbo::ManyToOne,
                             "UIN");
            
        }
    protected:
    private:
};

#endif // UNIT_H
