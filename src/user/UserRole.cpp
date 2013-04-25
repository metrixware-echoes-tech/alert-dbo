#include "user/UserRole.h"

std::string UserRole::TRIGRAM(TRIGRAM_USER_ROLE);

UserRole::UserRole()
{
    this->jsonName = "user_role";
    //ctor
}

UserRole::~UserRole()
{

}

std::string UserRole::toJSON()
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->users, "users", false);
    
    res += "\t}";
    return res;
}