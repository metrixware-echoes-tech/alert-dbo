
#include "Table.h"
#include <string>

// include Dbo
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

class  : public Table
{
    public:
        ();
        virtual ~();

        static std::string TRIGRAM;

	// attributes


	// methods


	// dbo pointers (Other tables ids as foreign keys for this table)
        Wt::Dbo::ptr<> ;

	// dbo collections (This table id as foreign key in other tables)
        Wt::Dbo::collection<Wt::Dbo::ptr<>> ;

        template<class Action>
        void persist(Action& a)
        {
            std::map <std::string,std::string> mapClassAttributesStrings;
            mapClassAttributesStrings["ATTR"]=this->attr;

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

            Wt::Dbo::belongsTo(a, , "");

            //User id as foreign key in other tables

            Wt::Dbo::hasMany(a,
                             ,
                             Wt::Dbo::ManyToOne,
                             "");

        }
};

