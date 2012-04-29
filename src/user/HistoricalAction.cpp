#include "HistoricalAction.h"

namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<HistoricalAction> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "HAC_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
    }
}
#include "Hierarchy.h"
#include "UserAction.h"
#include "UserProfile.h"
#include "UserRole.h"
#include "UserField.h"
#include "UserValue.h"
#include "UserValueId.h"
#include "User.h"

#include "Organization.h"

#include "Probe.h"
#include "ProbeId.h"

#include "Plugin.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "Unit.h"
#include "UnitType.h"

std::string HistoricalAction::TRIGRAM = "UHA";

HistoricalAction::HistoricalAction()
{
    //ctor
}

HistoricalAction::~HistoricalAction()
{
    //dtor
}
