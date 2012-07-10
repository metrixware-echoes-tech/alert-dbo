/* 
 * File:   MacroTrigram.h
 * Author: tsa
 *
 * Created on 21 juin 2012, 20:20
 */

#ifndef MACROTRIGRAM_H
#define	MACROTRIGRAM_H

#define ID "_ID"

#define TRIGRAM_USER_FIELD "UFI"
#define TRIGRAM_WIDGET_TYPE "WTY"
#define TRIGRAM_USER_ROLE "URO"
#define TRIGRAM_USER_RIGHT "URI"
#define TRIGRAM_SPACE "SPA"
#define TRIGRAM_ACCESS_CONTROL_LIST "ACL"
#define TRIGRAM_UNIT "UNT"
#define TRIGRAM_UNIT_TYPE "UTY"
#define TRIGRAM_USER "USR"
#define TRIGRAM_USER_HISTORICAL_ACTION "UHA"
#define TRIGRAM_USER_HIERARCHY "UHI"
#define TRIGRAM_USER_PROFILE "UPR"
#define TRIGRAM_USER_VALUE "UVA"
#define TRIGRAM_ALERT_PARAM "APA"
#define TRIGRAM_ALERT "ALE"
#define TRIGRAM_ALERT_TYPE "ATY"
#define TRIGRAM_USER_ACTION "UAC"
#define TRIGRAM_ADDON "ADO"
#define TRIGRAM_ALERT_ACKNOWLEDGE "ACK"
#define TRIGRAM_ALERT_VALUE "AVA"
#define TRIGRAM_TAB "TAB"
#define TRIGRAM_TAB_VERSION "TVS"
#define TRIGRAM_WIDGET "WGT"
#define TRIGRAM_VALUE "VAL"
#define TRIGRAM_PLUGIN "PLG"
#define TRIGRAM_ORGANIZATION "ORG"
#define TRIGRAM_ORGANIZATION_TYPE "OTY"
#define TRIGRAM_ORGANIZATION_VALUE "OVA"
#define TRIGRAM_ORGANIZATION_FIELD "OFI"
#define TRIGRAM_INFORMATION "INF"
#define TRIGRAM_HISTORICAL_VALUE "HVA"
#define TRIGRAM_ALERT_CRITERIA "ACR"
#define TRIGRAM_PROBE "PRB"
#define TRIGRAM_SOURCE "SRC"
#define TRIGRAM_SOURCE_PARAMETER "SRP"
#define TRIGRAM_SOURCE_PARAMETER_VALUE "SPV"
#define TRIGRAM_ASSET "AST"
#define TRIGRAM_SYSLOG "SLO"
#define TRIGRAM_SEARCH "SEA"
#define TRIGRAM_SEARCH_TYPE "STY"
#define TRIGRAM_SEARCH_PARAMETER "SEP"
#define TRIGRAM_SEARCH_PARAMETER_VALUE "SEV"
#define TRIGRAM_PACK "PCK"
#define TRIGRAM_OPTION "OPT"

#define TEMPLATE_TRIGRAM(CLASS, TRIGRAM) template<> \
        struct dbo_traits<CLASS> : public dbo_default_traits \
        { \
            static const char *surrogateIdField() \
            { \
                return TRIGRAM; \
            } \
        };
        
                
        
        
 /*      
        template<>
        struct dbo_traits<UserAction> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ACT";
            }
        };
        template<>
        struct dbo_traits<Addon> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ADO";
            }
        };
        template<>
        struct dbo_traits<AlertAcknowledge> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ACK";
            }
        };
        template<>
        struct dbo_traits<Tab> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "TAB";
            }
        };
        template<>
        struct dbo_traits<TabVersion> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "TVS";
            }
        };
        template<>
        struct dbo_traits<TabWidgetAssociation> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "TWG";
            }
        };
        template<>
        struct dbo_traits<Widget> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "WGT";
            }
        };
        template<>
        struct dbo_traits<Value> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "VAL";
            }
        };
        template<>
        struct dbo_traits<Plugin> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "PLG";
            }
        };
        template<>
        struct dbo_traits<Organization> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ORG";
            }
        };
        template<>
        struct dbo_traits<HistoricalValue> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "HVA";
            }
        };
        template<>
        struct dbo_traits<AlertCriteria> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ACR";
            }
        };
        template<>
        struct dbo_traits<Probe> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "PRB";
            }
        };
        template<>
        struct dbo_traits<SourceParameter> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "SRP";
            }
        };
        template<>
        struct dbo_traits<Asset> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "AST";
            }
        };
        template<>
        struct dbo_traits<Syslog> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "SLO";
            }
        };
        template<>
        struct dbo_traits<SearchType> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "STY";
            }
        };
        template<>
        struct dbo_traits<SearchParameter> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "SEP";

  */ 

#endif	/* MACROTRIGRAM_H */

