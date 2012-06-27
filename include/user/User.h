#ifndef USER_H
#define USER_H

//#include "Table.h"

#include <string>

#include <Wt/Dbo/Types>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>
#include <Wt/WGlobal>

#include "MainIncludeFile.h"

class UserRole;
class UserProfile;
class UserHierarchy;
class UserField;
class UserValue;
class UserHistoricalAction;
class Organization;

class User : public Table
{
    public:
        User();
        User(std::string firstName, std::string lastName, std::string eMail, std::string password);
        virtual ~User();

        static std::string TRIGRAM;

        std::string firstName;
        std::string lastName;
        std::string eMail;
        std::string password;

        static std::string getName();

        Wt::Dbo::ptr<UserRole> userRole;
        Wt::Dbo::ptr<UserProfile> userProfile;

        Wt::Dbo::collection<Wt::Dbo::ptr<UserValue> > userValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<UserHierarchy> > parents;
        Wt::Dbo::collection<Wt::Dbo::ptr<UserHierarchy> > children;
        Wt::Dbo::collection<Wt::Dbo::ptr<UserHistoricalAction> > historicalActions;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertAcknowledge> > alertAcks;

        Wt::Dbo::collection<Wt::Dbo::ptr<UserField> > userFields;
        Wt::Dbo::collection<Wt::Dbo::ptr<Organization> > organizations;

        template<class Action>
        void persist(Action& a)
        {
            
            mapClassAttributesStrings["FIRST_NAME"]=this->firstName;
            mapClassAttributesStrings["LAST_NAME"]=this->lastName;
            mapClassAttributesStrings["MAIL"]=this->eMail;
            mapClassAttributesStrings["PWD"]=this->password;
            
            FIELD_FILLER();
            
            //Other tables ids as foreign keys for user table

            Wt::Dbo::belongsTo(a, userRole, "USR_URO");
            Wt::Dbo::belongsTo(a, userProfile, "USR_UPR");

            //User id as foreign key in other tables

            Wt::Dbo::hasMany(a,
                             parents,
                             Wt::Dbo::ManyToOne,
                             "UHI_UPA");
            Wt::Dbo::hasMany(a,
                             children,
                             Wt::Dbo::ManyToOne,
                             "UHI_UCH");
            Wt::Dbo::hasMany(a,
                             userValues,
                             Wt::Dbo::ManyToOne,
                             "UVA_USR");
            Wt::Dbo::hasMany(a,
                             historicalActions,
                             Wt::Dbo::ManyToOne,
                             "UHA_USR");
            Wt::Dbo::hasMany(a,
                             alertAcks,
                             Wt::Dbo::ManyToOne,
                             "ACK_USR");
//
//
//            // join tables
            Wt::Dbo::hasMany(a,
                             userFields,
                             Wt::Dbo::ManyToMany,
                             "TJ_USR_UFI");

            Wt::Dbo::hasMany(a,
                             organizations,
                             Wt::Dbo::ManyToMany,
                             "TJ_USR_ORG");



        }
};

// Auth
typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

//DBO_EXTERN_TEMPLATES(User);

#endif // USER_H
