#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class User;

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
    protected:
    private:
};

#endif // CONSTANTS_H
