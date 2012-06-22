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
class TabWidgetAssociation;
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

//#include "WidgetValueId.h"
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
        
        template<>
        struct dbo_traits<UserField> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return TRIGRAM_USER_FIELD;
            }
        };
        template<>
        struct dbo_traits<WidgetType> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "WTY_ID";
            }
        };
        
        template<>
        struct dbo_traits<UserRole> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "URO_ID";
            }
        };
        template<>
        struct dbo_traits<Unit> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UNT_ID";
            }
        };
        template<>
        struct dbo_traits<User> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "USR_ID";
            }
        };
        template<>
        struct dbo_traits<UserHistoricalAction> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "HAC_ID";
            }
        };
        template<>
        struct dbo_traits<UserProfile> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UPR_ID";
            }
        };
        template<>
        struct dbo_traits<AlertParam> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "APA_ID";
            }
        };      
        template<>
        struct dbo_traits<Alert> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ALE_ID";
            }
        };
        template<>
        struct dbo_traits<AlertType> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ATY_ID";
            }
        };
        template<>
        struct dbo_traits<UnitType> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UTY_ID";
            }
        };
        template<>
        struct dbo_traits<UserAction> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ACT_ID";
            }
        };
        template<>
        struct dbo_traits<Addon> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ADO_ID";
            }
        };
        template<>
        struct dbo_traits<AlertAcknowledge> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ACK_ID";
            }
        };
        template<>
        struct dbo_traits<Tab> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "TAB_ID";
            }
        };
        template<>
        struct dbo_traits<TabVersion> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "TVS_ID";
            }
        };
        template<>
        struct dbo_traits<TabWidgetAssociation> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "TWG_ID";
            }
        };
        template<>
        struct dbo_traits<Widget> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "WGT_ID";
            }
        };
        template<>
        struct dbo_traits<Value> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "VAL_ID";
            }
        };
        template<>
        struct dbo_traits<Plugin> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "PLG_ID";
            }
        };
        template<>
        struct dbo_traits<Organization> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ORG_ID";
            }
        };
        template<>
        struct dbo_traits<HistoricalValue> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "HVA_ID";
            }
        };
        template<>
        struct dbo_traits<AlertCriteria> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ACR_ID";
            }
        };
        template<>
        struct dbo_traits<Probe> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "PRB_ID";
            }
        };
        template<>
        struct dbo_traits<SourceParameter> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "SRP_ID";
            }
        };
        template<>
        struct dbo_traits<Asset> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "AST_ID";
            }
        };
        template<>
        struct dbo_traits<Syslog> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "SLO_ID";
            }
        };
        template<>
        struct dbo_traits<SearchType> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "STY_ID";
            }
        };
        template<>
        struct dbo_traits<SearchParameter> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "SEP_ID";
            }
        };
        template<>
        struct dbo_traits<AlertValue> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return 0;
            }
        };
//        template<>
//        struct dbo_traits<WidgetValue> : public dbo_default_traits
//        {
//            typedef WidgetValueId IdType;
//            static IdType invalidId() { return WidgetValueId(); }
//            static const char *surrogateIdField() { return 0; }
//        };
    }
}


        


#endif	/* DBOSPECIALIZATION_H */

