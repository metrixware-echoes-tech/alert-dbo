#include "Constants.h"

using namespace std;

const char *Constants::T_USER_USR = "T_USER_" TRIGRAM_USER;
//TODO: TSA : do the same for each table
const char *Constants::T_USER_ROLE_URO = "T_USER_ROLE_URO";
const char *Constants::T_USER_PROFILE_UPR = "T_USER_PROFILE_UPR";
const char *Constants::T_USER_FIELD_UFI = "T_USER_FIELD_UFI";
const char *Constants::T_USER_VALUE_UVA = "T_USER_VALUE_UVA";
const char *Constants::T_USER_HIERARCHY_UHI = "T_USER_HIERARCHY_UHI";
const char *Constants::T_USER_ACTION_UAC = "T_USER_ACTION_ACT";
const char *Constants::T_USER_HISTORICAL_ACTION_UHA = "T_USER_HISTORICAL_ACTION_UHA";
const char *Constants::T_ORGANIZATION_ORG = "T_ORGANIZATION_ORG";
const char *Constants::T_ORGANIZATION_TYPE_OTY = "T_ORGANIZATION_TYPE_OTY";
const char *Constants::T_PROBE_PRB = "T_PROBE_PRB";
const char *Constants::T_VALUE_VAL = "T_VALUE_VAL";
const char *Constants::T_HISTORICAL_VALUE_HVA = "T_HISTORICAL_VALUE_HVA";
const char *Constants::T_INFORMATION_INF = "T_INFORMATION_INF";
const char *Constants::T_PLUGIN_PLG = "T_PLUGIN_PLG";
const char *Constants::T_WIDGET_VALUE_WVA = "T_WIDGET_VALUE_WVA";
const char *Constants::T_UNIT_UNT = "T_UNIT_UNT";
const char *Constants::T_UNIT_TYPE_UTY = "T_UNIT_TYPE_UTY";
const char *Constants::T_WIDGET_TYPE_WTY = "T_WIDGET_TYPE_WTY";
const char *Constants::T_WIDGET_WGT = "T_WIDGET_WGT";
const char *Constants::T_TAB_TAB = "T_TAB_TAB";
const char *Constants::T_TAB_VERSION_TVS = "T_TAB_VERSION_TVS";
//const char *Constants::T_TAB_WIDGET_TWG = "T_TAB_WIDGET_TWG";
const char *Constants::T_ADDON_ADO = "T_ADDON_ADO";
const char *Constants::T_ALERT_ALE = "T_ALERT_ALE";
const char *Constants::T_ALERT_ACKNOWLEDGE_ACK = "T_ALERT_ACKNOWLEDGE_ACK";
const char *Constants::T_ALERT_VALUE_AVA = "T_ALERT_VALUE_AVA";
const char *Constants::T_ALERT_PARAM_APA = "T_ALERT_PARAM_APA";
const char *Constants::T_ALERT_TYPE_ATY = "T_ALERT_TYPE_ATY";
const char *Constants::T_ALERT_CRITERIA_ACR = "T_ALERT_CRITERIA_ACR";
const char *Constants::T_SOURCE_SRC = "T_SOURCE_SRC";
const char *Constants::T_SOURCE_PARAMETER_SRP = "T_SOURCE_PARAMETER_SRP";
const char *Constants::T_SOURCE_PARAMETER_VALUE_SPV = "T_SOURCE_PARAMETER_VALUE_SPV";
const char *Constants::T_ASSET_AST = "T_ASSET_AST";
const char *Constants::T_SYSLOG_SLO = "T_SYSLOG_SLO";
const char *Constants::T_SEARCH_SEA = "T_SEARCH_SEA";
const char *Constants::T_SEARCH_TYPE_STY = "T_SEARCH_TYPE_STY";
const char *Constants::T_SEARCH_PARAMETER_SEP = "T_SEARCH_PARAMETER_SEP";
const char *Constants::T_SEARCH_PARAMETER_VALUE_SEV = "T_SEARCH_PARAMETER_VALUE_SEV";
const char *Constants::T_PACK_PCK = "T_PACK_PCK";
const char *Constants::T_OPTION_OPT = "T_OPTION_OPT";

Constants::Constants()
{
    //ctor
}

Constants::~Constants()
{
    //dtor
}
