/* 
 * File:   TabWidgetAssociation.cpp
 * Author: tom
 * 
 * Created on 30 avril 2012, 19:29
 */

#include "Probe.h"
#include "ProbeId.h"
#include "TabWidgetAssociation.h"

class TabWidgetAssociation;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<TabWidgetAssociation> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "TWG_ID";
            }
        };
    }  
}

#include "Tab.h"
#include "TabVersion.h"

#include "Widget.h"
#include "WidgetType.h"

#include "Unit.h"
#include "UnitType.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "Plugin.h"

#include "Organization.h"

TabWidgetAssociation::TabWidgetAssociation()
{
}

TabWidgetAssociation::~TabWidgetAssociation()
{
}

