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

#include "Table.h"
#include "dboSpecialization.h"
#include "MacroTrigram.h"


#include "User.h"
#include "UserHierarchy.h"
#include "UserProfile.h"
#include "UserRole.h"
#include "UserField.h"

#include "Constants.h"

#include "Unit.h"
#include "UserHierarchy.h"
#include "UserHistoricalAction.h"
#include "UserValue.h"
#include "UserAction.h"
#include "UserRight.h"
#include "Space.h"
#include "AccessControlList.h"

#include "Organization.h"
#include "OrganizationType.h"
#include "OrganizationValue.h"
#include "OrganizationField.h"

#include "Information.h"
#include "Value.h"
#include "HistoricalValue.h"

#include "Plugin.h"

#include "WidgetType.h"
#include "Widget.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
//#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "Alert.h"
#include "AlertAcknowledge.h"
#include "AlertCriteria.h"
#include "AlertType.h"
#include "AlertValue.h"
#include "AlertParam.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

#include "Asset.h"

#include "Search.h"
#include "SearchType.h"
#include "SearchParameter.h"
#include "SearchParameterValue.h"

#include "Syslog.h"

#include "Pack.h"
#include "Option.h"


            

#endif	/* MAININCLUDEFILE_H */

