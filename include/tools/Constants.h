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


namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<User> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
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
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
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
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
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
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
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
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
                return 0;
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
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
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
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
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
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
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
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
                return "ORG_ID";
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
    protected:
    private:
};

#endif // CONSTANTS_H
