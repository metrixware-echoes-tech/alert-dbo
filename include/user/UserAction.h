#ifndef ACTION_H
#define ACTION_H

#include "Table.h"
#include <string>

// include Dbo
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

class HistoricalAction;

class UserAction : public Table
{
    public:
        UserAction();
        virtual ~UserAction();

        static std::string TRIGRAM;

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

        }
};
namespace Wt {
    namespace Dbo {
        template<>
        struct dbo_traits<UserAction> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ACT_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
    }
}
        


#endif // ACTION_H
