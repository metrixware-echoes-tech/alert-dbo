#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "tools/MainIncludeFile.h"

#include "tools/MacroTrigram.h"

#include <string>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "primaryKeys/UserValueId.h"

#include "primaryKeys/WidgetValueId.h"


class Constants
{
    public:
        Constants();
        virtual ~Constants();
        static const char *T_USER_USR;
        static const char *T_USER_ROLE_URO;
        static const char *T_USER_RIGHT_URI;   
        static const char *T_SPACE_SPA;
        static const char *T_ACCESS_CONTROL_LIST_ACL;        
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
        static const char *T_PROBE_PACKAGE_PPA;
        static const char *T_PROBE_PACKAGE_PARAMETER_PPP;
        static const char *T_INFORMATION_VALUE_IVA;
        static const char *T_INFORMATION_HISTORICAL_VALUE_IHV;
        static const char *T_INFORMATION_INF;
        static const char *T_PLUGIN_PLG;
        static const char *T_INFORMATION_UNIT_UNT;
        static const char *T_INFORMATION_SUB_UNIT_ISU;
        static const char *T_INFORMATION_UNIT_TYPE_UTY;
        static const char *T_WIDGET_VALUE_WVA;
        static const char *T_WIDGET_TYPE_WTY;
        static const char *T_WIDGET_WGT;
        static const char *T_TAB_TAB;
        static const char *T_TAB_VERSION_TVS;
//        static const char *T_TAB_WIDGET_TWG;
        static const char *T_ADDON_ADO;
        static const char *T_ALERT_ALE;
        static const char *T_ALERT_ACKNOWLEDGE_ACK;
        static const char *T_ALERT_MEDIA_SPECIALIZATION_AMS;
        static const char *T_ALERT_MESSAGE_DEFINITION_AMD;
        static const char *T_ALERT_MESSAGE_ALIAS_ASSET_AAA;
        static const char *T_ALERT_MESSAGE_ALIAS_PLUGIN_AAP;
        static const char *T_ALERT_MESSAGE_ALIAS_INFORMATION_AAI;
        static const char *T_ALERT_MESSAGE_ALIAS_INFORMATION_CRITERIA_AIC;
        static const char *T_ALERT_VALUE_AVA;
        static const char *T_ALERT_PARAM_APA;
        static const char *T_ALERT_SEQUENCE_ASE;
        static const char *T_ALERT_CRITERIA_ACR;
        static const char *T_ALERT_TRACKING_ATR;
        static const char *T_ALERT_TRACKING_EVENT_ATE;
        static const char *T_ENGINE_ENG;
        static const char *T_SOURCE_SRC;
        static const char *T_SOURCE_PARAMETER_SRP;
        static const char *T_SOURCE_PARAMETER_VALUE_SPV;
        static const char *T_ASSET_AST;
        static const char *T_ASSET_ARCHITECTURE_ASA;
        static const char *T_ASSET_DISTRIBUTION_ASD;
        static const char *T_ASSET_RELEASE_ASR;
        static const char *T_SYSLOG_SLO;
        static const char *T_SYSLOG_HISTORY_SLH;
        static const char *T_SEARCH_SEA;
        static const char *T_SEARCH_TYPE_STY;
        static const char *T_SEARCH_PARAMETER_SEP;
        static const char *T_SEARCH_PARAMETER_VALUE_SEV;
        static const char *T_SEARCH_UNIT_SEU;
        static const char *T_PACK_PCK;
        static const char *T_PACK_OPTION_POP;
        static const char *T_OPTION_VALUE_OPV;        
        static const char *T_OPTION_OPT;
        static const char *T_MEDIA_MED;
        static const char *T_MEDIA_VALUE_MEV;
    protected:
    private:
};

#endif // CONSTANTS_H
