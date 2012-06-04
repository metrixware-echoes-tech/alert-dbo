#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Table.h"

#include <string>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Probe.h"
#include "UserValueId.h"

#include "UserField.h"
#include "UserRole.h"
#include "UserProfile.h"
#include "User.h"

#include "Unit.h"

#include "Hierarchy.h"
#include "HistoricalAction.h"
#include "UserAction.h"
#include "UserValue.h"
#include "UserValueId.h"
#include "HistoricalAction.h"

#include "Plugin.h"

#include "Information.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"


#include "Probe.h"

#include "Organization.h"

#include "WidgetType.h"
#include "Widget.h"
#include "WidgetValueId.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "Alert.h"
#include "AlertHisto.h"
#include "AlertValue.h"
#include "AlertParam.h"
#include "AlertType.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"


class Constants
{
    public:
        Constants();
        virtual ~Constants();
        static const char *T_USER_USR;
        static const char *T_USER_ROLE_URO;
        static const char *T_HIERARCHY_HRC;
        static const char *T_USER_PROFILE_UPR;
        static const char *T_USER_VALUE_UVA;
        static const char *T_USER_FIELD_UFI;
        static const char *T_HISTORICAL_ACTION_HAC;
        static const char *T_ACTION_ACT;
        static const char *T_ORGANIZATION_ORG;
        static const char *T_PROBE_PRB;
        static const char *T_VALUE_VAL;
        static const char *T_HISTORICAL_VALUE_HVA;
        static const char *T_INFORMATION_INF;
        static const char *T_PLUGIN_PLG;
        static const char *T_UNIT_UNT;
        static const char *T_UNIT_TYPE_UTY;
        static const char *T_WIDGET_VALUE_WVA;
        static const char *T_WIDGET_TYPE_WTY;
        static const char *T_WIDGET_WGT;
        static const char *T_TAB_TAB;
        static const char *T_TAB_VERSION_TVS;
        static const char *T_TAB_WIDGET_TWG;
        static const char *T_ADDON_ADO;
        static const char *T_ALERT_ALE;
        static const char *T_ALERT_HISTO_AHI;
        static const char *T_ALERT_VALUE_AVA;
        static const char *T_ALERT_PARAM_APA;
        static const char *T_ALERT_TYPE_ATY;
        static const char *T_ALERT_CRITERIA_ACR;
        static const char *T_SOURCE_SRC;
        static const char *T_SOURCE_PARAMETER_SRP;
        static const char *T_SOURCE_PARAMETER_VALUE_SPV;
    protected:
    private:
};

#endif // CONSTANTS_H
