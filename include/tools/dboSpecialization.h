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
class InformationUnitType;
class User;
class UserProfile;
class UserValue;
class UserAction;
class UserHistoricalAction;
class AlertParam;
class AlertValue;
class Alert;
class AlertAcknowledge;
class AlertType;
class AlertCriteria;
class AlertTracking;
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
class SourceParameter;
class Asset;
class Syslog;
class SearchType;
class SearchParameter;
class Pack;
class Option;
class Media;
class MediaValue;

//class Source;

#include "tools/MacroTrigram.h"


namespace Wt
{
    namespace Dbo
    {   
       
        
        TEMPLATE_TRIGRAM(UserField,TRIGRAM_USER_FIELD ID);
        TEMPLATE_TRIGRAM(UserRole,TRIGRAM_USER_ROLE ID);
        TEMPLATE_TRIGRAM(UserRight,TRIGRAM_USER_RIGHT ID);  
        TEMPLATE_TRIGRAM(Space,TRIGRAM_SPACE ID);         

        TEMPLATE_TRIGRAM(InformationUnit,TRIGRAM_INFORMATION_UNIT ID);
        TEMPLATE_TRIGRAM(InformationUnitType,TRIGRAM_INFORMATION_UNIT_TYPE ID);
        TEMPLATE_TRIGRAM(User,TRIGRAM_USER ID);
        TEMPLATE_TRIGRAM(UserHistoricalAction, TRIGRAM_USER_HISTORICAL_ACTION ID);
        TEMPLATE_TRIGRAM(UserProfile, TRIGRAM_USER_PROFILE ID);
        TEMPLATE_TRIGRAM(AlertParam, TRIGRAM_ALERT_PARAM ID);
        TEMPLATE_TRIGRAM(Alert,TRIGRAM_ALERT ID);
        TEMPLATE_TRIGRAM(AlertType,TRIGRAM_ALERT_TYPE ID);    
        TEMPLATE_TRIGRAM(UserAction,TRIGRAM_USER_ACTION ID);
        TEMPLATE_TRIGRAM(Addon,TRIGRAM_ADDON ID);
        TEMPLATE_TRIGRAM(AlertAcknowledge,TRIGRAM_ALERT_ACKNOWLEDGE ID);
        TEMPLATE_TRIGRAM(AlertTracking,TRIGRAM_ALERT_TRACKING ID);

        TEMPLATE_TRIGRAM(InformationValue,TRIGRAM_INFORMATION_VALUE ID);
        TEMPLATE_TRIGRAM(Plugin,TRIGRAM_PLUGIN ID);
        TEMPLATE_TRIGRAM(Organization,TRIGRAM_ORGANIZATION ID);
        TEMPLATE_TRIGRAM(OrganizationType,TRIGRAM_ORGANIZATION_TYPE ID);
        TEMPLATE_TRIGRAM(OrganizationField,TRIGRAM_ORGANIZATION_FIELD ID);        
        TEMPLATE_TRIGRAM(InformationHistoricalValue,TRIGRAM_INFORMATION_HISTORICAL_VALUE ID);
        TEMPLATE_TRIGRAM(AlertCriteria,TRIGRAM_ALERT_CRITERIA ID);
        TEMPLATE_TRIGRAM(Probe,TRIGRAM_PROBE ID);
        TEMPLATE_TRIGRAM(SourceParameter,TRIGRAM_SOURCE_PARAMETER ID);
        TEMPLATE_TRIGRAM(Asset,TRIGRAM_ASSET ID);
        TEMPLATE_TRIGRAM(Syslog,TRIGRAM_SYSLOG ID);
        TEMPLATE_TRIGRAM(SearchType,TRIGRAM_SEARCH_TYPE ID);
        TEMPLATE_TRIGRAM(SearchParameter,TRIGRAM_SEARCH_PARAMETER ID);
        TEMPLATE_TRIGRAM(Pack,TRIGRAM_PACK ID);
        TEMPLATE_TRIGRAM(Option,TRIGRAM_OPTION ID);
        TEMPLATE_TRIGRAM(Media,TRIGRAM_MEDIA ID);
        TEMPLATE_TRIGRAM(MediaValue,TRIGRAM_MEDIA_VALUE ID);
        TEMPLATE_TRIGRAM(AlertValue, 0);

    }
}


        


#endif	/* DBOSPECIALIZATION_H */

