#include "UserRole.h"

class UserRole;
namespace Wt
{
    namespace Dbo
    {

        template<>
        struct dbo_traits<UserRole> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "URO_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
    }
}

#include "User.h"
#include "UserProfile.h"
#include "UserAction.h"
#include "UserValue.h"
#include "UserValueId.h"
#include "UserField.h"
#include "HistoricalAction.h"
#include "Hierarchy.h"

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

UserRole::UserRole()
{
    //ctor
}

UserRole::~UserRole()
{
    //dtor
}
