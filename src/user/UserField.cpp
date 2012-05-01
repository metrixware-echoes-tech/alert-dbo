#include "UserField.h"

namespace Wt
{
    namespace Dbo
    {        
        template<>
        struct dbo_traits<UserField> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UFI_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
    }
}

#include "UserAction.h"
#include "Hierarchy.h"
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

UserField::UserField()
{
    //ctor
}

UserField::~UserField()
{
    //dtor
}
