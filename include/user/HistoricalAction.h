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

class HistoricalAction : public Table
{
    public:
        HistoricalAction();
        virtual ~HistoricalAction();

        static std::string TRIGRAM;
        
	// attributes
        Wt::WDateTime dateTime;
        Wt::WDateTime deleteTag;
    
        int actionBefore;
        int actionAfter;
        int actionRelative;

	// methods


	// dbo pointers (Other tables ids as foreign keys for this table)
        Wt::Dbo::ptr<User> user;

	// dbo collections (This table id as foreign key in other tables)
        Wt::Dbo::collection<Wt::Dbo::ptr<UserAction> > actions;

        template<class Action>
        void persist(Action& a)
        {
            std::map <std::string,std::string> mapClassAttributesStrings;
            //mapClassAttributesStrings["ATTR"]=this->attr;

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

            Wt::Dbo::belongsTo(a, user, "UHA");

            //User id as foreign key in other tables

            Wt::Dbo::hasMany(a,
                             actions,
                             Wt::Dbo::ManyToOne,
                             "ACT");
            mapClassAttributesDates["DATETIME"]=this->dateTime;            
            mapClassAttributesDates["DELETE"]=this->deleteTag;
            //mapClassAttributesInts["DEFORE"]=this->actionBefore;
           // mapClassAttributesInts["AFTER"]=this->actionAfter;
           // mapClassAttributesInts["RELATIVE"]=this->actionRelative;
            

        }
};





#endif // HISTORICALACTION_H
