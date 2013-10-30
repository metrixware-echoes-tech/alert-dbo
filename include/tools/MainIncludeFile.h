/* 
 * File:   MainIncludeFile.h
 * Author: tsa
 *
 * Created on 15 juin 2012, 10:57
 */

#ifndef MAININCLUDEFILE_H
#define	MAININCLUDEFILE_H


/**
 * Automagically fill the field of the database. 
 * Must be used after the field definition.
 **/


/* FIELD_FILLER */
#define FIELD_FILLER() mapClassAttributesDates["DELETE"]=&this->deleteTag; \
    std::map<std::string,Wt::WString*>::iterator itStrings; \
    for(itStrings = mapClassAttributesStrings.begin(); itStrings != mapClassAttributesStrings.end(); ++itStrings) \
    { \
        Wt::Dbo::field(a, *itStrings->second, formatColumnName(*this,(*itStrings).first)); \
    } \
    std::map<std::string,Wt::WDateTime*>::iterator itDates; \
    for(itDates = mapClassAttributesDates.begin(); itDates != mapClassAttributesDates.end(); ++itDates) \
    { \
        Wt::Dbo::field(a, *itDates->second, formatColumnName(*this,(*itDates).first)); \
    } \
    std::map<std::string,bool*>::iterator itBools; \
    for(itBools = mapClassAttributesBools.begin(); itBools != mapClassAttributesBools.end(); ++itBools) \
    { \
        Wt::Dbo::field(a, *itBools->second, formatColumnName(*this,(*itBools).first)); \
    } \
    std::map<std::string,int*>::iterator itInts; \
    for(itInts = mapClassAttributesInts.begin(); itInts != mapClassAttributesInts.end(); ++itInts) \
    { \
        Wt::Dbo::field(a, *itInts->second, formatColumnName(*this,(*itInts).first)); \
    } \
    std::map<std::string,short*>::iterator itShorts; \
    for(itShorts = mapClassAttributesShorts.begin(); itShorts != mapClassAttributesShorts.end(); ++itShorts) \
    { \
        Wt::Dbo::field(a, *itShorts->second, formatColumnName(*this,(*itShorts).first)); \
    } \
    std::map<std::string,boost::optional<Wt::WString>* >::iterator itStringsNn; \
    for(itStringsNn = mapClassAttributesStringsNn.begin(); itStringsNn != mapClassAttributesStringsNn.end(); ++itStringsNn) \
    { \
        Wt::Dbo::field(a, *itStringsNn->second, formatColumnName(*this,(*itStringsNn).first)); \
    } \
    std::map<std::string,boost::optional<int>* >::iterator itIntsNn; \
    for(itIntsNn = mapClassAttributesIntsNn.begin(); itIntsNn != mapClassAttributesIntsNn.end(); ++itIntsNn) \
    { \
        Wt::Dbo::field(a, *itIntsNn->second, formatColumnName(*this,(*itIntsNn).first)); \
    } \
    std::map<std::string,long long* >::iterator itSerials; \
    for(itSerials = mapClassAttributesSerials.begin(); itSerials != mapClassAttributesSerials.end(); ++itSerials) \
    { \
        Wt::Dbo::field(a, *itSerials->second, formatColumnName(*this,(*itSerials).first)); \
    }



/* END FIELD_FILLER */


#include <Wt/Auth/User>

#include "tools/Table.h"
#include "tools/dboSpecialization.h"
#include "tools/MacroTrigram.h"


#include "user/User.h"
#include "user/UserHierarchy.h"
#include "user/UserProfile.h"
#include "user/UserRole.h"
#include "user/UserField.h"

#include "tools/Constants.h"
//#include "tools/SessionPool.h"

#include "unit/InformationUnit.h"
#include "user/UserHierarchy.h"
#include "user/UserHistoricalAction.h"
#include "user/UserValue.h"
#include "user/UserAction.h"
#include "user/UserRight.h"
#include "user/Space.h"
#include "user/AccessControlList.h"

#include "organization/Organization.h"
#include "organization/OrganizationType.h"
#include "organization/OrganizationValue.h"
#include "organization/OrganizationField.h"

#include "information/Information.h"
#include "information/InformationHistoricalValue.h"
#include "information/InformationValue.h"

#include "plugin/Plugin.h"

//#include "widget/WidgetType.h"
//#include "widget/Widget.h"

#include "unit/InformationUnitType.h"
#include "unit/InformationSubUnit.h"

//#include "widget/Tab.h"
//#include "widget/TabVersion.h"
//#include "TabWidgetAssociation.h"

#include "addon/Addon.h"

#include "alert/Alert.h"
#include "alert/AlertAcknowledge.h"
#include "alert/AlertCriteria.h"
#include "alert/AlertMediaSpecialization.h"
#include "alert/AlertValue.h"
#include "alert/AlertSequence.h"
#include "alert/AlertTracking.h"
#include "alert/AlertTrackingEvent.h"
#include "alert/AlertMessageDefinition.h"
#include "alert/AlertMessageAliasAsset.h"
#include "alert/AlertMessageAliasPlugin.h"
#include "alert/AlertMessageAliasInformation.h"
#include "alert/AlertMessageAliasInformationCriteria.h"

#include "engine/Engine.h"
#include "engine/EngOrg.h"

#include "plugin/Source.h"
#include "plugin/SourceParameter.h"
#include "plugin/SourceParameterValue.h"

#include "asset/Asset.h"
#include "asset/AssetArchitecture.h"
#include "asset/AssetDistribution.h"
#include "asset/AssetRelease.h"

#include "plugin/Search.h"
#include "plugin/SearchType.h"
#include "plugin/SearchParameter.h"
#include "plugin/SearchParameterValue.h"
#include "plugin/SearchUnit.h"

#include "information/Syslog.h"

#include "pack/Pack.h"
#include "pack/Option.h"
#include "pack/PackOption.h"
#include "pack/OptionValue.h"

#include "probe/Probe.h"
#include "probe/ProbePackage.h"
#include "probe/ProbePackageParameter.h"

#include "media/Media.h"
#include "media/MediaValue.h"

#endif	/* MAININCLUDEFILE_H */

