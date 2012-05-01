#include "Probe.h"
#include "ProbeId.h"

#include "Widget.h"

class Widget;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<Widget> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "WGT_ID";
            }
        };
    }  
}

#include "Unit.h"
#include "UnitType.h"

#include "HistoricalValue.h"
#include "Value.h"
#include "Information.h"

#include "Plugin.h"

#include "Organization.h"

#include "WidgetType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

Widget::Widget()
{
    //ctor
}

Widget::~Widget()
{
    //dtor
}
