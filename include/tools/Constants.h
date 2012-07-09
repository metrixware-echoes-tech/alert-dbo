#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "MainIncludeFile.h"

#include "MacroTrigram.h"

#include <string>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "UserValueId.h"

#include "WidgetValueId.h"


class Constants
{
    public:
        Constants();
        virtual ~Constants();
        static const char *T_USER_USR;
        static const char *T_USER_ROLE_URO;
        static const char *T_USER_HIERARCHY_UHI;
        static const char *T_USER_PROFILE_UPR;
        static const char *T_USER_VALUE_UVA;
        static const char *T_USER_FIELD_UFI;
        static const char *T_USER_HISTORICAL_ACTION_UHA;
        static const char *T_USER_ACTION_UAC;
        static const char *T_ORGANIZATION_ORG;
        static const char *T_ORGANIZATION_TYPE_OTY;
        static const char *T_ORGANIZATION_VALUE_OVA;  
        static const char *T_ORGANIZATION_FIELD_OFI;         
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
//        static const char *T_TAB_WIDGET_TWG;
        static const char *T_ADDON_ADO;
        static const char *T_ALERT_ALE;
        static const char *T_ALERT_ACKNOWLEDGE_ACK;
        static const char *T_ALERT_VALUE_AVA;
        static const char *T_ALERT_PARAM_APA;
        static const char *T_ALERT_TYPE_ATY;
        static const char *T_ALERT_CRITERIA_ACR;
        static const char *T_SOURCE_SRC;
        static const char *T_SOURCE_PARAMETER_SRP;
        static const char *T_SOURCE_PARAMETER_VALUE_SPV;
        static const char *T_ASSET_AST;
        static const char *T_SYSLOG_SLO;
        static const char *T_SEARCH_SEA;
        static const char *T_SEARCH_TYPE_STY;
        static const char *T_SEARCH_PARAMETER_SEP;
        static const char *T_SEARCH_PARAMETER_VALUE_SEV;
        static const char *T_PACK_PCK;
        static const char *T_OPTION_OPT;
    protected:
    private:
};

#endif // CONSTANTS_H
