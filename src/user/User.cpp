#include "User.h"

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
                return "USR_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
    }  
}

#include "Constants.h"
#include "Hierarchy.h"
#include "HistoricalAction.h"
#include "UserProfile.h"
#include "UserAction.h"
#include "UserRole.h"
#include "UserField.h"
#include "UserValue.h"
#include "UserValueId.h"
#include "HistoricalAction.h"

#include "Organization.h"

#include "Probe.h"
#include "ProbeId.h"

#include "Plugin.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "Unit.h"
#include "UnitType.h"

#include <string>
#include <Wt/Dbo/Impl>
#include <Wt/Auth/Dbo/AuthInfo>

DBO_INSTANTIATE_TEMPLATES(User);

std::string User::TRIGRAM = "USR";

User::User() : Table()
{

}

User::User(std::string firstName, std::string lastName, std::string eMail, std::string password) : Table()
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->eMail = eMail;
    this->password = password;
}
User::~User()
{
    //dtor
}

/*template<>
void QuiSuisJe<User>(const User & x)
{
    cout << "Je suis un <User>" << endl;
}*/

std::string User::getName()
{
    return Constants::T_USER_USR;
}

void User::test()
{


}

