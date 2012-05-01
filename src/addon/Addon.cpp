#include "Probe.h"
#include "ProbeId.h"

#include "Addon.h"

class Addon;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<Addon> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ADO_ID";
            }
        };
    }  
}


#include "Plugin.h"

#include "Value.h"
#include "Information.h"
#include "Plugin.h"
#include "HistoricalValue.h"

#include "Unit.h"
#include "UnitType.h"

#include "Organization.h"

#include "WidgetType.h"
#include "Widget.h"

#include "Tab.h"
#include "TabWidgetAssociation.h"
#include "TabVersion.h"

Addon::Addon()
{
    //ctor
}

Addon::~Addon()
{
    //dtor
}
