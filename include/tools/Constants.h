#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>


class User;
class UserRole;
class UserProfile;
class UserField;
class UserValue;
class Hierarchy;
class HistoricalAction;
class Action;
class Organization;
class Probe;
class Value;
class HistoricalValue;
class Information2;
class Plugin;


namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<User> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "USR_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<UserRole> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "URO_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<UserProfile> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UPR_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<UserField> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UFI_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<UserValue> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                //changed to test, return0.
                return "UVA_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<Hierarchy> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                //changed to test, return0.
                //return "HRC_ID";
                return 0;
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<HistoricalAction> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "HAC_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<Action> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ACT_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<Organization> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ORG_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<Probe> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "PRB_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<Value> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return 0;
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<HistoricalValue> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return 0;
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<Information2> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "INF_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<Plugin> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "PLG_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
    }
}


class Constants
{
    public:
        Constants();
        virtual ~Constants();
        static const char *T_USER_USR;
        static const char *T_USER_ROLE_URO;
        static const char *T_HIERARCHY_HRC;
        static const char *T_USER_PROFILE_UPR;
        static const char *T_USER_VALUE_UVA;
        static const char *T_USER_FIELD_UFI;
        static const char *T_HISTORICAL_ACTION_HAC;
        static const char *T_ACTION_ACT;
        static const char *T_ORGANIZATION_ORG;
        static const char *T_PROBE_PRB;
        static const char *T_VALUE_VAL;
        static const char *T_HISTORICAL_VALUE_VAL;
        static const char *T_INFORMATION_INF;
        static const char *T_PLUGIN_PLG;
    protected:
    private:
};

#endif // CONSTANTS_H
