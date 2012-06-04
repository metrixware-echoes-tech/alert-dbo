#ifndef USERROLE_H
#define USERROLE_H

#include "Table.h"

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/WtSqlTraits>

#include "UserProfile.h"
#include "User.h"
#include "UserField.h"
#include "HistoricalAction.h"

#include "UserAction.h"
#include "UserValue.h"
#include "Unit.h"
#include "UserValueId.h"
#include "Hierarchy.h"

#include "Organization.h"


#include "Probe.h"

#include "Plugin.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "Widget.h"
#include "WidgetType.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

//class User;

class UserRole : public Table
{
public:
    UserRole();
    virtual ~UserRole();
    
    static std::string TRIGRAM;

    Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

    template<class Action>
    void persist(Action& a)
    {
        //Wt::Dbo::belongsTo(a, user, User::getName().c_str());
        Wt::Dbo::hasMany(a,
                         users,
                         Wt::Dbo::ManyToOne,
                         "URO");
    }



};


#endif // USERROLE_H
