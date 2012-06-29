#ifndef HISTORICALACTION_H
#define HISTORICALACTION_H

#include <string>

// include Dbo
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "MainIncludeFile.h"

//class User;
//class UserAction;

class UserHistoricalAction : public Table
{
    public:
        UserHistoricalAction();
        virtual ~UserHistoricalAction();

        static std::string TRIGRAM;
        
	// attributes
        Wt::WDateTime dateTime;
    
        int actionBefore;
        int actionAfter;
        int actionRelative;

	// methods


	// dbo pointers (Other tables ids as foreign keys for this table)
        Wt::Dbo::ptr<User> user;

	// dbo collections (This table id as foreign key in other tables)
        Wt::Dbo::collection<Wt::Dbo::ptr<UserAction> > userActions;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesDates["DATETIME"]=this->dateTime;            
            mapClassAttributesInts["BEFORE"]=this->actionBefore;
            mapClassAttributesInts["AFTER"]=this->actionAfter;
            mapClassAttributesInts["RELATIVE"]=this->actionRelative;
            FIELD_FILLER();
            //Other tables ids as foreign keys for user table

            Wt::Dbo::belongsTo(a, user, "UHA_USR");

            //User id as foreign key in other tables

            Wt::Dbo::hasMany(a,
                             userActions,
                             Wt::Dbo::ManyToOne,
                             "UAC_UHA");
            
            
            

        }
};





#endif // HISTORICALACTION_H
