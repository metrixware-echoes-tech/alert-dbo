#ifndef USER_H
#define USER_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "UserRole.h"
#include "Table.h"

class UserRole;

class User : public Table
{

private:
    std::string formatColumnName(std::string value);
public:
    User();
    User(std::string firstName, std::string lastName, std::string eMail, std::string password);
    virtual ~User();

    static std::string TRIGRAM;

    std::string firstName;
    std::string lastName;
    std::string eMail;
    std::string password;
    Wt::WDateTime deleteTag;

    static std::string getName();

    Wt::Dbo::collection<Wt::Dbo::ptr<UserRole>> roles;

    /*
    int myint[] = {1,2,3,4};
    for (int& i : myint)
    {
        cout << i << endl;
    }
    */

    template<class Action>
    void persist(Action& a)
    {
        std::map <std::string,std::string> mapClassAttributesStrings;
        mapClassAttributesStrings["FIRST_NAME"]=this->firstName;
        mapClassAttributesStrings["LAST_NAME"]=this->lastName;
        mapClassAttributesStrings["MAIL"]=this->eMail;
        mapClassAttributesStrings["PWD"]=this->password;

        std::map <std::string,Wt::WDateTime> mapClassAttributesDates;
        mapClassAttributesDates["DELETE"]=this->deleteTag;

        std::map<std::string,std::string>::iterator itStrings;
        for(itStrings = mapClassAttributesStrings.begin(); itStrings != mapClassAttributesStrings.end(); ++itStrings)
        {
            Wt::Dbo::field(a, (*itStrings).second, formatColumnName((*itStrings).first));
        }

        std::map<std::string,Wt::WDateTime>::iterator itDates;
        for(itDates = mapClassAttributesDates.begin(); itDates != mapClassAttributesDates.end(); ++itDates)
        {
            Wt::Dbo::field(a, (*itDates).second, formatColumnName((*itDates).first));
        }

        Wt::Dbo::hasMany(a,
                         roles,
                         Wt::Dbo::ManyToOne,
                         Constants::T_USER_USR);


        //Wt::Dbo::field(a, this->deleteTag,     this->formatColumnName("DELETE"));
        //Wt::Dbo::field(a, password, this->formatColumnName("PASSWORD"));
    }

    void test();
};



#endif // USER_H
