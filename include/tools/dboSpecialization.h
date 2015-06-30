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

namespace Echoes {
    namespace Dbo {

        class Table;

        class UserField;
        class UserRole;
        class UserRight;
        class Space;
        class AccessControlList;
        class Information;
        class InformationUnit;
        class InformationUnitType;
        class InformationData;
        class User;
        class UserProfile;
        class UserValue;
        class UserActionType;
        class UserHistoricalAction;
        class AlertValue;
        class Alert;
        class AlertAcknowledge;
        class AlertCriteria;
        class AlertMediaSpecialization;
        class AlertMessageAliasAsset;
        class AlertMessageAliasPlugin;
        class AlertMessageAliasInformation;
        class AlertMessageAliasInformationCriteria;
        class AlertTrackingEvent;
        class AlertStatus;
        class AlertSequence;
        class AlertTimeSlot;
        
        class Message;
        class MessageTrackingEvent;
        class MessageStatus;
        
        class Engine;
        class EngOrg;
        //class WidgetValue;
        //class WidgetType;
        class Addon;
        class AddonCommonPackage;
        class AddonCommonPackageParameter;
        class AddonPackage;
        class AddonPackageParameter;
        //class Tab;
        //class TabVersion;
        //class TabWidgetAssociation;
        //class Widget;
        class InformationValue;
        
        class Plugin;
        class PluginReference;
        class PluginData;
        
        class Filter;
        class FilterType;
        class FilterParameter;
        
        class Organization;
        class OrganizationType;
        class OrganizationValue;
        class OrganizationField;
        
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
        class Source;
        class Search;
        class SearchType;
        class SearchParameter;
        class Pack;
        class PackOption;
        class Option;
        class OptionType;
        class MediaType;
        class Media;
    }
}

#include "tools/MacroTrigram.h"

namespace Wt {
    namespace Dbo {

        TEMPLATE_TRIGRAM(Echoes::Dbo::UserField, TRIGRAM_USER_FIELD ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::UserRole, TRIGRAM_USER_ROLE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::UserRight, TRIGRAM_USER_RIGHT ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::Space, TRIGRAM_SPACE ID)

        TEMPLATE_TRIGRAM(Echoes::Dbo::InformationUnit, TRIGRAM_INFORMATION_UNIT ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::InformationUnitType, TRIGRAM_INFORMATION_UNIT_TYPE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::User, TRIGRAM_USER ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::UserHistoricalAction, TRIGRAM_USER_HISTORICAL_ACTION ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::UserProfile, TRIGRAM_USER_PROFILE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::Alert, TRIGRAM_ALERT ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::UserActionType, TRIGRAM_USER_ACTION_TYPE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::Addon, TRIGRAM_ADDON ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AddonCommonPackage, TRIGRAM_ADDON_COMMON_PACKAGE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AddonCommonPackageParameter, TRIGRAM_ADDON_COMMON_PACKAGE_PARAMETER ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AddonPackage, TRIGRAM_ADDON_PACKAGE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AddonPackageParameter, TRIGRAM_ADDON_PACKAGE_PARAMETER ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AlertAcknowledge, TRIGRAM_ALERT_ACKNOWLEDGE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AlertSequence, TRIGRAM_ALERT_SEQUENCE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AlertTimeSlot, TRIGRAM_ALERT_TIMESLOT ID)

        TEMPLATE_TRIGRAM(Echoes::Dbo::Message, TRIGRAM_MESSAGE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::MessageTrackingEvent, TRIGRAM_MESSAGE_TRACKING_EVENT ID)
                
        TEMPLATE_TRIGRAM(Echoes::Dbo::Engine, TRIGRAM_ENGINE ID)

        TEMPLATE_TRIGRAM(Echoes::Dbo::Information, TRIGRAM_INFORMATION ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::InformationValue, TRIGRAM_INFORMATION_VALUE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::InformationData, TRIGRAM_INFORMATION_DATA ID)
                
        TEMPLATE_TRIGRAM(Echoes::Dbo::Plugin, TRIGRAM_PLUGIN ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::PluginReference, TRIGRAM_PLUGIN_REFERENCE ID)
                
        TEMPLATE_TRIGRAM(Echoes::Dbo::Filter, TRIGRAM_FILTER ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::FilterType, TRIGRAM_FILTER_TYPE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::FilterParameter, TRIGRAM_FILTER_PARAMETER ID)
                
        TEMPLATE_TRIGRAM(Echoes::Dbo::Organization, TRIGRAM_ORGANIZATION ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::OrganizationType, TRIGRAM_ORGANIZATION_TYPE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::OrganizationField, TRIGRAM_ORGANIZATION_FIELD ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::InformationHistoricalValue, TRIGRAM_INFORMATION_HISTORICAL_VALUE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AlertCriteria, TRIGRAM_ALERT_CRITERIA ID)

        TEMPLATE_TRIGRAM(Echoes::Dbo::Probe, TRIGRAM_PROBE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::ProbePackage, TRIGRAM_PROBE_PACKAGE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::ProbePackageParameter, TRIGRAM_PROBE_PACKAGE_PARAMETER ID)

        TEMPLATE_TRIGRAM(Echoes::Dbo::Source, TRIGRAM_SOURCE ID)        
        TEMPLATE_TRIGRAM(Echoes::Dbo::SourceParameter, TRIGRAM_SOURCE_PARAMETER ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::Asset, TRIGRAM_ASSET ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AssetArchitecture, TRIGRAM_ASSET_ARCHITECTURE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AssetDistribution, TRIGRAM_ASSET_DISTRIBUTION ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AssetRelease, TRIGRAM_ASSET_RELEASE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::Syslog, TRIGRAM_SYSLOG ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::SyslogHistory, TRIGRAM_SYSLOG_HISTORY ID)
        
        TEMPLATE_TRIGRAM(Echoes::Dbo::Search, TRIGRAM_SEARCH ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::SearchType, TRIGRAM_SEARCH_TYPE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::SearchParameter, TRIGRAM_SEARCH_PARAMETER ID)
                
        TEMPLATE_TRIGRAM(Echoes::Dbo::Pack, TRIGRAM_PACK ID)
        //        TEMPLATE_TRIGRAM(Echoes::Dbo::PackOption,TRIGRAM_PACK_OPTION ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::Option,TRIGRAM_OPTION ID)        
        TEMPLATE_TRIGRAM(Echoes::Dbo::OptionType, TRIGRAM_OPTION_TYPE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::MediaType, TRIGRAM_MEDIA_TYPE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::Media, TRIGRAM_MEDIA ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AlertValue, TRIGRAM_ALERT_VALUE ID)
        TEMPLATE_TRIGRAM(Echoes::Dbo::AlertMediaSpecialization, TRIGRAM_ALERT_MEDIA_SPECIALIZATION ID)

    }
}


#endif	/* DBOSPECIALIZATION_H */

//
