#include "User.h"

using namespace std;


string Table::TRIGRAM = "USR";
string Table::SHORT_NAME = "USER";
string Table::FULL_NAME = Table::TABLE_PREFIX + Table::SEP + Table::SHORT_NAME + Table::SEP + Table::TRIGRAM;

template<typename T>
struct testStruct
{
    T a;
    string b;
};


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

void User::test()
{
    string str("toto");
    QuiSuisJe(*this);
    QuiSuisJe(str); // "Je suis un <inconnu>"
    QuiSuisJe(1); // "Je suis un <int>"
    QuiSuisJe(1.23);

    testStruct<string> t1;
    t1.a = "toto";
    t1.b = "tata";

    testStruct<int> t2;
    t2.a = 42;
    t2.b = "titi";

    setFields(t1);
    setFields(t2);



}

