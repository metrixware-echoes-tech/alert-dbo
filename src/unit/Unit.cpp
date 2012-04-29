#include "Unit.h"

class Unit;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<Unit> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UNT_ID";
            }
        };
    }  
}

#include "Constants.h"
#include "User.h"
#include "Hierarchy.h"
#include "HistoricalAction.h"
#include "UserProfile.h"
#include "UserAction.h"
#include "UserRole.h"
#include "UserField.h"
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

#include "UnitType.h"

Unit::Unit()
{
    //ctor
}

Unit::~Unit()
{
    //dtor
}
