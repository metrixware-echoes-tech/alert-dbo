#ifndef USER_H
#define USER_H

//#include "Table.h"

#include <string>

#include <Wt/Dbo/Types>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>
#include <Wt/WGlobal>
#include <Wt/Auth/AbstractUserDatabase>
#include <Wt/Auth/Dbo/AuthInfo>

#include "tools/MainIncludeFile.h"

class UserRole;
class UserProfile;
class UserHierarchy;
class UserField;
class UserValue;
class UserHistoricalAction;
class Organization;
class MediaValue;

class User;
typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;
typedef Wt::Dbo::collection< Wt::Dbo::ptr<User> > Users;

class User : public Table, public Wt::Dbo::Dbo<User>
{
    public:
        User() : Table() {};
        User(std::string firstName, std::string lastName, std::string eMail, std::string password) : Table()
        {
            this->firstName = firstName;
            this->lastName = lastName;
            this->eMail = eMail;
            this->password = password;
        };
        virtual ~User();

        static std::string TRIGRAM;

        Wt::WString firstName;
        Wt::WString lastName;
        Wt::WString eMail;
        Wt::WString password;

        static std::string getName();

        Wt::Dbo::ptr<UserRole> userRole;
        Wt::Dbo::ptr<UserProfile> userProfile;

        Wt::Dbo::collection<Wt::Dbo::ptr<UserValue> > userValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<UserHierarchy> > parents;
        Wt::Dbo::collection<Wt::Dbo::ptr<UserHierarchy> > children;
        Wt::Dbo::collection<Wt::Dbo::ptr<UserHistoricalAction> > historicalActions;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertAcknowledge> > alertAcks;
        Wt::Dbo::collection<Wt::Dbo::ptr<MediaValue> > mediaValues;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<UserField> > userFields;
        Wt::Dbo::collection<Wt::Dbo::ptr<Organization> > organizations;
        
        
        //link to auth_info table
        Wt::Dbo::collection< Wt::Dbo::ptr<AuthInfo> > authInfos;
        
        

        template<class Action>
        void persist(Action& a)
        {
            
            mapClassAttributesStrings["FIRST_NAME"]=&this->firstName;
            mapClassAttributesStrings["LAST_NAME"]=&this->lastName;
            mapClassAttributesStrings["MAIL"]=&this->eMail;
            mapClassAttributesStrings["PWD"]=&this->password;
            
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
            Wt::Dbo::hasMany(a,
                             mediaValues,
                             Wt::Dbo::ManyToOne,
                             "MEV_USR");
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
            
            
            Wt::Dbo::hasMany(a, authInfos, Wt::Dbo::ManyToOne, "user");


        }
};

// Auth
//typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

DBO_EXTERN_TEMPLATES(User);

#endif // USER_H
