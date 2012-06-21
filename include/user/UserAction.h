#ifndef ACTION_H
#define ACTION_H

#include <string>

// include Dbo
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "MainIncludeFile.h"

//class HistoricalAction;

class UserAction : public Table
{
    public:
        UserAction();
        virtual ~UserAction();

        static std::string TRIGRAM;
	// attributes
        std::string name;
	// methods

	// dbo pointers (Other tables ids as foreign keys for this table)
        Wt::Dbo::ptr<UserHistoricalAction> historicalAction;

        template<class Action>
        void persist(Action& a) 
        {
            mapClassAttributesStrings["NAME"]=this->name;
            
            FIELD_FILLER();

            //Other tables ids as foreign keys for user table
            Wt::Dbo::belongsTo(a, historicalAction, "ACT");
                     
        }
};
        


#endif // ACTION_H
