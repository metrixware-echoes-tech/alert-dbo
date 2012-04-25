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

//#include "Constants.h"
//#include "ProbeId.h"
//#include "Probe.h"
//#include "Session.h"
//#include "Value.h"
//#include "Plugin.h"
//#include "Constants.h"
//#include "Information.h"
#include "UserAction.h"
//#include "Hierarchy.h"
#include "HistoricalAction.h"
#include "User.h"
//#include "UserProfile.h"
#include "UserRole.h"
#include "UserValue.h"
#include "UserValueId.h"
//#include "HistoricalValue.h"
//#include "Organization.h"


UserField::UserField()
{
    //ctor
}

UserField::~UserField()
{
    //dtor
}
