#ifndef USERFIELD_H
#define USERFIELD_H

#include <Wt/Dbo/Dbo>

#include "UserAction.h"
#include "Hierarchy.h"
#include "HierarchyId.h"
#include "HistoricalAction.h"
#include "User.h"
#include "UserProfile.h"
#include "UserRole.h"
#include "UserValue.h"
#include "UserValueId.h"


#include "Organization.h"

#include "Probe.h"
#include "ProbeId.h"

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


class User;
class UserValue;

class UserField
{
    public:
        UserField();
        virtual ~UserField();

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
