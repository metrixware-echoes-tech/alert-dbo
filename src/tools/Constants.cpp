#include "tools/Constants.h"

using namespace std;

const char *Constants::T_USER_USR = "T_USER_" TRIGRAM_USER;
//TODO: TSA : do the same for each table
const char *Constants::T_USER_ROLE_URO = "T_USER_ROLE_URO";
const char *Constants::T_USER_RIGHT_URI = "T_USER_RIGHT_URI";
const char *Constants::T_SPACE_SPA = "T_SPACE_SPA";
const char *Constants::T_ACCESS_CONTROL_LIST_ACL = "T_ACCESS_CONTROL_LIST_ACL";
const char *Constants::T_USER_PROFILE_UPR = "T_USER_PROFILE_UPR";
const char *Constants::T_USER_FIELD_UFI = "T_USER_FIELD_UFI";
const char *Constants::T_USER_VALUE_UVA = "T_USER_VALUE_UVA";
const char *Constants::T_USER_HIERARCHY_UHI = "T_USER_HIERARCHY_UHI";
const char *Constants::T_USER_ACTION_UAC = "T_USER_ACTION_ACT";
const char *Constants::T_USER_HISTORICAL_ACTION_UHA = "T_USER_HISTORICAL_ACTION_UHA";
const char *Constants::T_ORGANIZATION_ORG = "T_ORGANIZATION_ORG";
const char *Constants::T_ORGANIZATION_TYPE_OTY = "T_ORGANIZATION_TYPE_OTY";
const char *Constants::T_ORGANIZATION_VALUE_OVA = "T_ORGANIZATION_VALUE_OVA";
const char *Constants::T_ORGANIZATION_FIELD_OFI = "T_ORGANIZATION_FIELD_OFI";
const char *Constants::T_PROBE_PRB = "T_PROBE_PRB";
const char *Constants::T_PROBE_PACKAGE_PPA = "T_PROBE_PACKAGE_PPA";
const char *Constants::T_PROBE_PACKAGE_PARAMETER_PPP = "T_PROBE_PACKAGE_PARAMETER_PPP";
const char *Constants::T_INFORMATION_VALUE_IVA = "T_INFORMATION_VALUE_IVA";
const char *Constants::T_INFORMATION_HISTORICAL_VALUE_IHV = "T_INFORMATION_HISTORICAL_VALUE_IHV";
const char *Constants::T_INFORMATION_INF = "T_INFORMATION_INF";
const char *Constants::T_PLUGIN_PLG = "T_PLUGIN_PLG";
const char *Constants::T_WIDGET_VALUE_WVA = "T_WIDGET_VALUE_WVA";
const char *Constants::T_INFORMATION_UNIT_UNT = "T_INFORMATION_UNIT_UNT";
const char *Constants::T_INFORMATION_SUB_UNIT_ISU = "T_INFORMATION_SUB_UNIT_ISU";
const char *Constants::T_INFORMATION_UNIT_TYPE_UTY = "T_INFORMATION_UNIT_TYPE_UTY";
const char *Constants::T_WIDGET_TYPE_WTY = "T_WIDGET_TYPE_WTY";
const char *Constants::T_WIDGET_WGT = "T_WIDGET_WGT";
const char *Constants::T_TAB_TAB = "T_TAB_TAB";
const char *Constants::T_TAB_VERSION_TVS = "T_TAB_VERSION_TVS";
//const char *Constants::T_TAB_WIDGET_TWG = "T_TAB_WIDGET_TWG";
const char *Constants::T_ADDON_ADO = "T_ADDON_ADO";
const char *Constants::T_ADDON_COMMON_PACKAGE_CPA = "T_ADDON_COMMON_PACKAGE_CPA";
const char *Constants::T_ADDON_COMMON_PACKAGE_PARAMETER_CPP = "T_ADDON_COMMON_PACKAGE_PARAMETER_CPP";
const char *Constants::T_ADDON_PACKAGE_APA = "T_ADDON_PACKAGE_APA";
const char *Constants::T_ADDON_PACKAGE_PARAMETER_APP = "T_ADDON_PACKAGE_PARAMETER_APP";
const char *Constants::T_ALERT_ALE = "T_ALERT_ALE";
const char *Constants::T_ALERT_ACKNOWLEDGE_ACK = "T_ALERT_ACKNOWLEDGE_ACK";
const char *Constants::T_ALERT_MEDIA_SPECIALIZATION_AMS = "T_ALERT_MEDIA_SPECIALIZATION_AMS";
const char *Constants::T_ALERT_MESSAGE_DEFINITION_AMD = "T_ALERT_MESSAGE_DEFINITION_AMD";
const char *Constants::T_ALERT_MESSAGE_ALIAS_ASSET_AAA = "T_ALERT_MESSAGE_ALIAS_ASSET_AAA";
const char *Constants::T_ALERT_MESSAGE_ALIAS_PLUGIN_AAP = "T_ALERT_MESSAGE_ALIAS_PLUGIN_AAP";
const char *Constants::T_ALERT_MESSAGE_ALIAS_INFORMATION_AAI = "T_ALERT_MESSAGE_ALIAS_INFORMATION_AAI";
const char *Constants::T_ALERT_MESSAGE_ALIAS_INFORMATION_CRITERIA_AIC = "T_ALERT_MESSAGE_ALIAS_INFORMATION_CRITERIA_AIC";
const char *Constants::T_ALERT_VALUE_AVA = "T_ALERT_VALUE_AVA";
const char *Constants::T_ALERT_PARAM_APA = "T_ALERT_PARAM_APA";
const char *Constants::T_ALERT_CRITERIA_ACR = "T_ALERT_CRITERIA_ACR";
const char *Constants::T_ALERT_SEQUENCE_ASE = "T_ALERT_SEQUENCE_ASE";
const char *Constants::T_ALERT_TRACKING_ATR = "T_ALERT_TRACKING_ATR";
const char *Constants::T_ALERT_TRACKING_EVENT_ATE = "T_ALERT_TRACKING_EVENT_ATE";
const char *Constants::T_ENGINE_ENG = "T_ENGINE_ENG";
const char *Constants::TJ_ENG_ORG = "TJ_ENG_ORG";
const char *Constants::T_SOURCE_SRC = "T_SOURCE_SRC";
const char *Constants::T_SOURCE_PARAMETER_SRP = "T_SOURCE_PARAMETER_SRP";
const char *Constants::T_SOURCE_PARAMETER_VALUE_SPV = "T_SOURCE_PARAMETER_VALUE_SPV";
const char *Constants::T_ASSET_AST = "T_ASSET_AST";
const char *Constants::T_ASSET_ARCHITECTURE_ASA = "T_ASSET_ARCHITECTURE_ASA";
const char *Constants::T_ASSET_DISTRIBUTION_ASD = "T_ASSET_DISTRIBUTION_ASD";
const char *Constants::T_ASSET_RELEASE_ASR = "T_ASSET_RELEASE_ASR";
const char *Constants::T_SYSLOG_SLO = "T_SYSLOG_SLO";
const char *Constants::T_SEARCH_SEA = "T_SEARCH_SEA";
const char *Constants::T_SEARCH_TYPE_STY = "T_SEARCH_TYPE_STY";
const char *Constants::T_SEARCH_PARAMETER_SEP = "T_SEARCH_PARAMETER_SEP";
const char *Constants::T_SEARCH_PARAMETER_VALUE_SEV = "T_SEARCH_PARAMETER_VALUE_SEV";
const char *Constants::T_SEARCH_UNIT_SEU = "T_SEARCH_UNIT_SEU";
const char *Constants::T_PACK_PCK = "T_PACK_PCK";
const char *Constants::T_PACK_OPTION_POP = "T_PACK_OPTION_POP";
const char *Constants::T_OPTION_VALUE_OPV = "T_OPTION_VALUE_OPV";
const char *Constants::T_OPTION_OPT = "T_OPTION_OPT";
const char *Constants::T_MEDIA_MED = "T_MEDIA_MED";
const char *Constants::T_MEDIA_VALUE_MEV = "T_MEDIA_VALUE_MEV";

Constants::Constants()
{
    //ctor
}

Constants::~Constants()
{
    //dtor
}
