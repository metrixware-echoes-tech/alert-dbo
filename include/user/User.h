#ifndef USER_H
#define USER_H

#include "Table.h"

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

#include "Widget.h"
#include "WidgetType.h"

#include "Unit.h"
#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include <string>

#include <Wt/Dbo/Types>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>
#include <Wt/WGlobal>

//class UserRole;
//class UserProfile;
class Hierarchy;
//class UserField;
//class UserValue;
//class HistoricalAction;
//class Organization;

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
        Wt::WDateTime deleteTag;

        static std::string getName();

        Wt::Dbo::ptr<UserRole> userRole;
        Wt::Dbo::ptr<UserProfile> userProfile;

        Wt::Dbo::collection<Wt::Dbo::ptr<UserField> > userFields;
        Wt::Dbo::collection<Wt::Dbo::ptr<UserValue> > userValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<Hierarchy> > parents;
        Wt::Dbo::collection<Wt::Dbo::ptr<Hierarchy> > children;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalAction> > historicalActions;

        Wt::Dbo::collection<Wt::Dbo::ptr<Organization> > organizations;

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
                Wt::Dbo::field(a, (*itStrings).second, formatColumnName(*this,(*itStrings).first));
            }

            std::map<std::string,Wt::WDateTime>::iterator itDates;
            for(itDates = mapClassAttributesDates.begin(); itDates != mapClassAttributesDates.end(); ++itDates)
            {
                Wt::Dbo::field(a, (*itDates).second, formatColumnName(*this,(*itDates).first));
            }

            //Other tables ids as foreign keys for user table

            Wt::Dbo::belongsTo(a, userRole, "URO");
            Wt::Dbo::belongsTo(a, userProfile, "UPR");

            //User id as foreign key in other tables

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
                             historicalActions,
                             Wt::Dbo::ManyToOne,
                             "UHA");
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
        void test();
};

// Auth
typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

//DBO_EXTERN_TEMPLATES(User);

#endif // USER_H
