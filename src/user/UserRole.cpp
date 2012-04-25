#include "UserRole.h"

class UserRole;
namespace Wt
{
    namespace Dbo
    {

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
    }
}

#include "User.h"
#include "UserAction.h"
#include "UserValue.h"
#include "UserValueId.h"
#include "UserField.h"
#include "HistoricalAction.h"

UserRole::UserRole()
{
    //ctor
}

UserRole::~UserRole()
{
    //dtor
}
