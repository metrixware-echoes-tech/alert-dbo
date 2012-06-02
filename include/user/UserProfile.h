#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "UserRole.h"
#include "User.h"
#include "Unit.h"

#include "HistoricalAction.h"

#include "UserAction.h"
#include "UserField.h"
#include "Hierarchy.h"
#include "UserValue.h"
#include "UserValueId.h"

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

//class User;

class UserProfile
{
public:
    UserProfile();
    virtual ~UserProfile();

    Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

    template<class Action>
    void persist(Action& a)
    {
        //Wt::Dbo::belongsTo(a, user, User::getName().c_str());
        Wt::Dbo::hasMany(a,
                         users,
                         Wt::Dbo::ManyToOne,
                         "UPR");
    }

};




#endif // USERPROFILE_H
