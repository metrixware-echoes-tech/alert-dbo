#include "ProbeId.h"
#include "Probe.h"

#include "Tab.h"

class Tab;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<Tab> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "TAB_ID";
            }
        };
    }  
}

#include "WidgetType.h"
#include "Widget.h"

#include "Unit.h"
#include "UnitType.h"

#include "HistoricalValue.h"
#include "Value.h"
#include "Plugin.h"
#include "Information.h"

#include "Organization.h"

#include "TabVersion.h"
#include "TabWidgetAssociation.h"

Tab::Tab()
{
    //ctor
}

Tab::~Tab()
{
    //dtor
}
