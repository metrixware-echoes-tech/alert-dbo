#include "User.h"
#include "Constants.h"

using namespace std;

string User::TRIGRAM = "USR";

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

template<>
void QuiSuisJe<User>(const User & x)
{
    cout << "Je suis un <User>" << endl;
}

string User::formatColumnName(string value)
{
    return User::TRIGRAM + Constants::SEP + value;
}

/*string User::formatColumnName()
{
    return User::TRIGRAM + Constants::SEP + value;
}*/

string User::getName()
{
    return Constants::T_USER_USR;
}


void User::test()
{
    string str("toto");
    QuiSuisJe(*this);
    QuiSuisJe(str); // "Je suis un <inconnu>"
    QuiSuisJe(1); // "Je suis un <int>"
    QuiSuisJe(1.23);

    //testStruct<string> t1;
    //t1.a = "toto";
    //t1.b = "tata";

    //testStruct<int> t2;
    //t2.a = 42;
    //t2.b = "titi";

    //setFields(t1);
    //setFields(t2);



}

