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
class Unit;
class UnitType;
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
//class WidgetValue;
class WidgetType;
class Addon;
class Tab;
class TabVersion;
//class TabWidgetAssociation;
class Widget;
class Value;
class Plugin;
class Organization;
class Information2;
class HistoricalValue;
class Probe;
class SourceParameter;
class Asset;
class Syslog;
class SearchType;
class SearchParameter;

#include "MacroTrigram.h"

namespace Wt
{
    namespace Dbo
    {   
        // TSA : i'd like to know why this doesn't work ?!
        /*template<typename T>
        struct dbo_traits<T*> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                std::string res = T::TRIGRAM + T::SEP + "ID";
                return res.c_str();
            }
        };*/
        
        
        TEMPLATE_TRIGRAM(UserField,TRIGRAM_USER_FIELD ID);
        TEMPLATE_TRIGRAM(UserRole,TRIGRAM_USER_ROLE ID);
        TEMPLATE_TRIGRAM(WidgetType,TRIGRAM_WIDGET_TYPE ID);
        TEMPLATE_TRIGRAM(Unit,TRIGRAM_UNIT ID);
        TEMPLATE_TRIGRAM(User,TRIGRAM_USER ID);
        TEMPLATE_TRIGRAM(UserHistoricalAction, TRIGRAM_USER_HISTORICAL_ACTION ID);
        TEMPLATE_TRIGRAM(UserProfile, TRIGRAM_USER_PROFILE ID);
        TEMPLATE_TRIGRAM(AlertParam, TRIGRAM_ALERT_PARAM ID);
        TEMPLATE_TRIGRAM(Alert,TRIGRAM_ALERT ID);
        TEMPLATE_TRIGRAM(AlertType,TRIGRAM_ALERT_TYPE ID);
        TEMPLATE_TRIGRAM(UnitType,TRIGRAM_UNIT_TYPE ID);
        TEMPLATE_TRIGRAM(UserAction,TRIGRAM_USER_ACTION ID);
        TEMPLATE_TRIGRAM(Addon,TRIGRAM_ADDON ID);
        TEMPLATE_TRIGRAM(AlertAcknowledge,TRIGRAM_ACKNOWLEDGE ID);
        TEMPLATE_TRIGRAM(Tab,TRIGRAM_TAB ID);
        TEMPLATE_TRIGRAM(TabVersion,TRIGRAM_TAB_VERSION ID);
        TEMPLATE_TRIGRAM(Widget,TRIGRAM_WIDGET ID);
        TEMPLATE_TRIGRAM(Value,TRIGRAM_VALUE ID);
        TEMPLATE_TRIGRAM(Plugin,TRIGRAM_PLUGIN ID);
        TEMPLATE_TRIGRAM(Organization,TRIGRAM_ORGANIZATION ID);
        TEMPLATE_TRIGRAM(HistoricalValue,TRIGRAM_HISTORICAL_VALUE ID);
        TEMPLATE_TRIGRAM(AlertCriteria,TRIGRAM_ALERT_CRITERIA ID);
        TEMPLATE_TRIGRAM(Probe,TRIGRAM_PROBE ID);
        TEMPLATE_TRIGRAM(SourceParameter,TRIGRAM_SOURCE_PARAMETER ID);
        TEMPLATE_TRIGRAM(Asset,TRIGRAM_ASSET ID);
        TEMPLATE_TRIGRAM(Syslog,TRIGRAM_SYSLOG ID);
        TEMPLATE_TRIGRAM(SearchType,TRIGRAM_SEARCH_TYPE ID);
        TEMPLATE_TRIGRAM(SearchParameter,TRIGRAM_SEARCH_PARAMETER ID);
        TEMPLATE_TRIGRAM(AlertValue, 0);

    }
}


        


#endif	/* DBOSPECIALIZATION_H */

