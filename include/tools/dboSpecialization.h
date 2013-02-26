/* 
 * File:   dboSpecialization.h
 * Author: tom
 *
 * Created on 4 mai 2012, 18:15
 */

#ifndef DBOSPECIALIZATION_H
#define	DBOSPECIALIZATION_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/SqlTraits>

class Table;

class UserField;
class UserRole;
class UserRight;
class Space;
class AccessControlList;
class InformationUnit;
class InformationSubUnit;
class InformationUnitType;
class User;
class UserProfile;
class UserValue;
class UserAction;
class UserHistoricalAction;
class AlertValue;
class Alert;
class AlertAcknowledge;
class AlertCriteria;
class AlertMediaSpecialization;
class AlertMessageDefinition;
class AlertMessageAliasAsset;
class AlertMessageAliasPlugin;
class AlertMessageAliasInformation;
class AlertMessageAliasInformationCriteria;
class AlertSequence;
class AlertTracking;
class AlertTrackingEvent;
class Engine;
//class WidgetValue;
//class WidgetType;
class Addon;
//class Tab;
//class TabVersion;
//class TabWidgetAssociation;
//class Widget;
class InformationValue;
class Plugin;
class Organization;
class OrganizationType;
class OrganizationValue;
class OrganizationField;
class Information2;
class InformationValue;
class InformationHistoricalValue;
class Probe;
class ProbePackage;
class ProbePackageParameter;
class SourceParameter;
class Asset;
class AssetArchitecture;
class AssetDistribution;
class AssetRelease;
class Syslog;
class SyslogHistory;
class SearchType;
class SearchParameter;
class SearchUnit;
class Pack;
class PackOption;
class OptionValue;
class Option;
class Media;
class MediaValue;

//class Source;

#include "tools/MacroTrigram.h"


namespace Wt
{
    namespace Dbo
    {   
       
        
        TEMPLATE_TRIGRAM(UserField,TRIGRAM_USER_FIELD ID)
        TEMPLATE_TRIGRAM(UserRole,TRIGRAM_USER_ROLE ID)
        TEMPLATE_TRIGRAM(UserRight,TRIGRAM_USER_RIGHT ID)  
        TEMPLATE_TRIGRAM(Space,TRIGRAM_SPACE ID)         

        TEMPLATE_TRIGRAM(InformationUnit,TRIGRAM_INFORMATION_UNIT ID)
        TEMPLATE_TRIGRAM(InformationSubUnit,TRIGRAM_INFORMATION_SUB_UNIT ID)
        TEMPLATE_TRIGRAM(InformationUnitType,TRIGRAM_INFORMATION_UNIT_TYPE ID)
        TEMPLATE_TRIGRAM(User,TRIGRAM_USER ID)
        TEMPLATE_TRIGRAM(UserHistoricalAction, TRIGRAM_USER_HISTORICAL_ACTION ID)
        TEMPLATE_TRIGRAM(UserProfile, TRIGRAM_USER_PROFILE ID)
        TEMPLATE_TRIGRAM(Alert,TRIGRAM_ALERT ID)
        TEMPLATE_TRIGRAM(UserAction,TRIGRAM_USER_ACTION ID)
        TEMPLATE_TRIGRAM(Addon,TRIGRAM_ADDON ID)
        TEMPLATE_TRIGRAM(AlertAcknowledge,TRIGRAM_ALERT_ACKNOWLEDGE ID)
        TEMPLATE_TRIGRAM(AlertSequence,TRIGRAM_ALERT_SEQUENCE ID)
        TEMPLATE_TRIGRAM(AlertTracking,TRIGRAM_ALERT_TRACKING ID)
        TEMPLATE_TRIGRAM(AlertTrackingEvent,TRIGRAM_ALERT_TRACKING_EVENT ID)
        
        TEMPLATE_TRIGRAM(Engine,TRIGRAM_ENGINE ID)

        TEMPLATE_TRIGRAM(InformationValue,TRIGRAM_INFORMATION_VALUE ID)
        TEMPLATE_TRIGRAM(Plugin,TRIGRAM_PLUGIN ID)
        TEMPLATE_TRIGRAM(Organization,TRIGRAM_ORGANIZATION ID)
        TEMPLATE_TRIGRAM(OrganizationType,TRIGRAM_ORGANIZATION_TYPE ID)
        TEMPLATE_TRIGRAM(OrganizationField,TRIGRAM_ORGANIZATION_FIELD ID)        
        TEMPLATE_TRIGRAM(InformationHistoricalValue,TRIGRAM_INFORMATION_HISTORICAL_VALUE ID)
        TEMPLATE_TRIGRAM(AlertCriteria,TRIGRAM_ALERT_CRITERIA ID)
                
        TEMPLATE_TRIGRAM(Probe,TRIGRAM_PROBE ID)
        TEMPLATE_TRIGRAM(ProbePackage,TRIGRAM_PROBE_PACKAGE ID)
        TEMPLATE_TRIGRAM(ProbePackageParameter,TRIGRAM_PROBE_PACKAGE_PARAMETER ID)
                
        TEMPLATE_TRIGRAM(SourceParameter,TRIGRAM_SOURCE_PARAMETER ID)
        TEMPLATE_TRIGRAM(Asset,TRIGRAM_ASSET ID)
        TEMPLATE_TRIGRAM(AssetArchitecture,TRIGRAM_ASSET_ARCHITECTURE ID)
        TEMPLATE_TRIGRAM(AssetDistribution,TRIGRAM_ASSET_DISTRIBUTION ID)
        TEMPLATE_TRIGRAM(AssetRelease,TRIGRAM_ASSET_RELEASE ID)
        TEMPLATE_TRIGRAM(Syslog,TRIGRAM_SYSLOG ID)
        TEMPLATE_TRIGRAM(SyslogHistory,TRIGRAM_SYSLOG_HISTORY ID)
        TEMPLATE_TRIGRAM(SearchType,TRIGRAM_SEARCH_TYPE ID)
        TEMPLATE_TRIGRAM(SearchParameter,TRIGRAM_SEARCH_PARAMETER ID)
//        TEMPLATE_TRIGRAM(SearchUnit,TRIGRAM_SEARCH_UNIT ID)        
        TEMPLATE_TRIGRAM(Pack,TRIGRAM_PACK ID)
//        TEMPLATE_TRIGRAM(PackOption,TRIGRAM_PACK_OPTION ID)
//        TEMPLATE_TRIGRAM(OptionValue,TRIGRAM_OPTION_VALUE ID)        
        TEMPLATE_TRIGRAM(Option,TRIGRAM_OPTION ID)
        TEMPLATE_TRIGRAM(Media,TRIGRAM_MEDIA ID)
        TEMPLATE_TRIGRAM(MediaValue,TRIGRAM_MEDIA_VALUE ID)
        TEMPLATE_TRIGRAM(AlertValue, TRIGRAM_ALERT_VALUE ID)
        TEMPLATE_TRIGRAM(AlertMediaSpecialization, TRIGRAM_ALERT_MEDIA_SPECIALIZATION ID)

    }
}


        


#endif	/* DBOSPECIALIZATION_H */

