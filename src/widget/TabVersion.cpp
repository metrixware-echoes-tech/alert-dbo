#include "Probe.h"
#include "ProbeId.h"

#include "TabVersion.h"

class TabVersion;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<TabVersion> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "TVS_ID";
            }
        };
    }  
}

#include "Tab.h"
#include "TabWidgetAssociation.h"

#include "WidgetType.h"
#include "Widget.h"

#include "Unit.h"
#include "UnitType.h"

#include "Value.h"
#include "Information.h"
#include "Plugin.h"
#include "HistoricalValue.h"

#include "Organization.h"

TabVersion::TabVersion()
{
    //ctor
}

TabVersion::~TabVersion()
{
    //dtor
}
