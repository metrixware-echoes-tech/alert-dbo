#ifndef USERFIELD_H
#define USERFIELD_H

#include "Table.h"
#include <Wt/Dbo/Dbo>

#include "Hierarchy.h"
#include "HierarchyId.h"
#include "HistoricalAction.h"
#include "User.h"
#include "UserProfile.h"
#include "UserRole.h"
#include "UserValue.h"
#include "UserValueId.h"
#include "UserAction.h"

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

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

#include "Asset.h"

class User;
class UserValue;

class UserField : public Table
{
    public:
        UserField();
        virtual ~UserField();
        
        static std::string TRIGRAM;

        Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

        Wt::Dbo::collection<Wt::Dbo::ptr<UserValue> > userValues;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             users,
                             Wt::Dbo::ManyToMany,
                             "TJ_USR_UFI");

            Wt::Dbo::hasMany(a,
                             userValues,
                             Wt::Dbo::ManyToOne,
                             "UVA_UFI");
        }
};

#endif // USERFIELD_H
