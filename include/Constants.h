#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class User;
class UserRole;
class Hierarchy;

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
    }
}

class Constants
{
    public:
        Constants();
        virtual ~Constants();
        static std::string SEP;
        static std::string TABLE_PREFIX;
        static const char *T_USER_USR;
        static const char *T_USER_ROLE_URO;
        static const char *T_HIERARCHY_HRC;
    protected:
    private:
};

#endif // CONSTANTS_H
