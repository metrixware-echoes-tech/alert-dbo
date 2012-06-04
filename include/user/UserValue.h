#ifndef USERVALUE_H
#define USERVALUE_H

#include "Table.h"

#include <Wt/Dbo/Dbo>

#include "UserProfile.h"
#include "UserRole.h"
#include "UserField.h"
#include "User.h"
#include "Unit.h"
#include "HistoricalAction.h"

#include "UserValueId.h"
#include "UserAction.h"
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

#include "UserValueId.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

//class User;
//class UserField;

class UserValue : public Table
{
    public:
        UserValue();
        virtual ~UserValue();
        
        static std::string TRIGRAM;
        
        UserValueId uvid;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::id(a,uvid,"PK_TEST");
        }
    protected:
    private:
};


#endif // USERVALUE_H
