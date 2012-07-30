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
#define FIELD_FILLER() mapClassAttributesDates["DELETE"]=this->deleteTag; \
            std::map<std::string,std::string>::iterator itStrings; \
            for(itStrings = mapClassAttributesStrings.begin(); itStrings != mapClassAttributesStrings.end(); ++itStrings) \
            { \
                Wt::Dbo::field(a, (*itStrings).second, formatColumnName(*this,(*itStrings).first)); \
            } \
            std::map<std::string,Wt::WDateTime>::iterator itDates; \
            for(itDates = mapClassAttributesDates.begin(); itDates != mapClassAttributesDates.end(); ++itDates) \
            { \
                Wt::Dbo::field(a, (*itDates).second, formatColumnName(*this,(*itDates).first)); \
            } \
            std::map<std::string,bool>::iterator itBools; \
            for(itBools = mapClassAttributesBools.begin(); itBools != mapClassAttributesBools.end(); ++itBools) \
            { \
                Wt::Dbo::field(a, (*itBools).second, formatColumnName(*this,(*itBools).first)); \
            } \
            std::map<std::string,int>::iterator itInts; \
            for(itInts = mapClassAttributesInts.begin(); itInts != mapClassAttributesInts.end(); ++itInts) \
            { \
                Wt::Dbo::field(a, (*itInts).second, formatColumnName(*this,(*itInts).first)); \
            }
/* END FIELD_FILLER */

#include "tools/Table.h"
#include "tools/dboSpecialization.h"
#include "tools/MacroTrigram.h"


#include "user/User.h"
#include "user/UserHierarchy.h"
#include "user/UserProfile.h"
#include "user/UserRole.h"
#include "user/UserField.h"

#include "tools/Constants.h"

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

//#include "widget/Tab.h"
//#include "widget/TabVersion.h"
//#include "TabWidgetAssociation.h"

#include "addon/Addon.h"

#include "alert/Alert.h"
#include "alert/AlertAcknowledge.h"
#include "alert/AlertCriteria.h"
#include "alert/AlertType.h"
#include "alert/AlertValue.h"
#include "alert/AlertParam.h"
#include "alert/AlertTracking.h"
#include "alert/AlertTrackingEvent.h"

#include "plugin/Source.h"
#include "plugin/SourceParameter.h"
#include "plugin/SourceParameterValue.h"

#include "asset/Asset.h"

#include "plugin/Search.h"
#include "plugin/SearchType.h"
#include "plugin/SearchParameter.h"
#include "plugin/SearchParameterValue.h"

#include "information/Syslog.h"

#include "pack/Pack.h"
#include "pack/Option.h"

#include "probe/Probe.h"

#include "media/Media.h"
#include "media/MediaValue.h"


            

#endif	/* MAININCLUDEFILE_H */

