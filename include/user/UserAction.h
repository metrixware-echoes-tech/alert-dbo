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
        
        std::string name;

	// attributes
	Wt::WDateTime deleteTag;


	// methods


	// dbo pointers (Other tables ids as foreign keys for this table)
        Wt::Dbo::ptr<HistoricalAction> historicalAction;

        template<class Action>
        void persist(Action& a) 
        {
            std::map <std::string,std::string> mapClassAttributesStrings;

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

            Wt::Dbo::belongsTo(a, historicalAction, "ACT");
            mapClassAttributesStrings["NAME"]=this->name;            
        }
};
namespace Wt {
    namespace Dbo {
        
    }
}
        


#endif // ACTION_H
