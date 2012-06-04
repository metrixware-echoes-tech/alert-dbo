#ifndef ACTION_H
#define ACTION_H

#include "Table.h"
#include <string>

// include Dbo
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "Hierarchy.h"
#include "Unit.h"
#include "UserRole.h"

#include "UserField.h"
#include "UserProfile.h"
#include "User.h"
#include "UserValue.h"
#include "UserValueId.h"
#include "HistoricalAction.h"

#include "Organization.h"

#include "Probe.h"

#include "Plugin.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "WidgetType.h"
#include "Widget.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

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
        
    }
}
        


#endif // ACTION_H
