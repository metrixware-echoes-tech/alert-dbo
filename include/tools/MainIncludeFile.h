/* 
 * File:   MainIncludeFile.h
 * Author: tsa
 *
 * Created on 15 juin 2012, 10:57
 */

#ifndef MAININCLUDEFILE_H
#define	MAININCLUDEFILE_H

#define TAMACRO() std::map<std::string,std::string>::iterator itStrings; \
            for(itStrings = mapClassAttributesStrings.begin(); itStrings != mapClassAttributesStrings.end(); ++itStrings) \
            { \
                Wt::Dbo::field(a, (*itStrings).second, formatColumnName(*this,(*itStrings).first)); \
            } \
 \
            std::map<std::string,Wt::WDateTime>::iterator itDates; \
            for(itDates = mapClassAttributesDates.begin(); itDates != mapClassAttributesDates.end(); ++itDates) \
            { \
                Wt::Dbo::field(a, (*itDates).second, formatColumnName(*this,(*itDates).first)); \
            } 

#include "Table.h"

#include "dboSpecialization.h"
#include "Hierarchy.h"
#include "UserProfile.h"
#include "UserRole.h"
#include "User.h"
#include "UserField.h"

#include "Constants.h"

#include "Unit.h"
#include "Hierarchy.h"
#include "HistoricalAction.h"
#include "UserValue.h"
#include "UserAction.h"

#include "Organization.h"

//#include "PostgresConnector.h"
//#include "AuthApplication.h"
//#include "Session.h"

#include "Information.h"
#include "Value.h"
#include "HistoricalValue.h"

#include "Plugin.h"

#include "WidgetType.h"
#include "Widget.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "Alert.h"
#include "AlertHisto.h"
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


            

#endif	/* MAININCLUDEFILE_H */

