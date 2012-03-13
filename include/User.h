#ifndef USER_H
#define USER_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "UserRole.h"
#include "UserProfile.h"
#include "UserField.h"
#include "UserValue.h"
#include "Hierarchy.h"
#include "Table.h"

class UserRole;
class UserProfile;
class Hierarchy;
class userField;

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

    Wt::Dbo::ptr<UserRole> userRole;

    Wt::Dbo::ptr<UserProfile> userProfile;

    Wt::Dbo::collection<Wt::Dbo::ptr<UserField>> userFields;

    Wt::Dbo::collection<Wt::Dbo::ptr<UserValue>> userValues;

    Wt::Dbo::collection<Wt::Dbo::ptr<Hierarchy>> parents;

    Wt::Dbo::collection<Wt::Dbo::ptr<Hierarchy>> children;




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

        Wt::Dbo::belongsTo(a, userRole, "URO");

        Wt::Dbo::belongsTo(a, userProfile, "UPR");

        Wt::Dbo::hasMany(a,
                         parents,
                         Wt::Dbo::ManyToOne,
                         "UPA");

        Wt::Dbo::hasMany(a,
                         children,
                         Wt::Dbo::ManyToOne,
                         "UCH");

        Wt::Dbo::hasMany(a,
                         userValues,
                         Wt::Dbo::ManyToOne,
                         "UVA_UFI");

        Wt::Dbo::hasMany(a,
                         userFields,
                         Wt::Dbo::ManyToMany,
                         "TJ_USR_UFI");

    }
    void test();
};



#endif // USER_H
