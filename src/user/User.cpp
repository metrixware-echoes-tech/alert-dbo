#include "User.h"
//#include "Constants.h"
#include <string>

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
