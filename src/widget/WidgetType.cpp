#include "Probe.h"
#include "ProbeId.h"

#include "WidgetType.h"

class WidgetType;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<WidgetType> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "WTY_ID";
            }
        };
    }  
}

#include "UnitType.h"
#include "Unit.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "Plugin.h"

#include "Organization.h"

#include "Widget.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

WidgetType::WidgetType()
{
    //ctor
}

WidgetType::~WidgetType()
{
    //dtor
}
