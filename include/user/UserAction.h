#ifndef ACTION_H
#define ACTION_H

#include <string>

// include Dbo
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "tools/MainIncludeFile.h"

//class HistoricalAction;

class UserAction : public Table
{
    public:
        UserAction();
        virtual ~UserAction();

        static std::string TRIGRAM;
	// attributes
        Wt::WString name;
	// methods


        
         Wt::Dbo::collection<Wt::Dbo::ptr<UserHistoricalAction> > userHistoricalActions;

        template<class Action>
        void persist(Action& a) 
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             userHistoricalActions,
                             Wt::Dbo::ManyToOne,
                             "UHA_UAC");

                     
        }
};
        


#endif // ACTION_H
