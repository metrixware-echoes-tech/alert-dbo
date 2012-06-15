#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <string>

// include Dbo
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "MainIncludeFile.h"

class Organization : public Table
{
    public:
        Organization();
        virtual ~Organization();

        static std::string TRIGRAM;

        // attributes
        std::string name;
        std::string address;
        std::string cp;
        std::string city;
        
        Wt::WDateTime deleteTag;


        // methods

        //RHI : manque lien avec PACK et ORGANISATION VALUE et TYPE
        
        
        // dbo collections (This table id as foreign key in other tables)
        Wt::Dbo::collection<Wt::Dbo::ptr<User> > user;
        Wt::Dbo::collection<Wt::Dbo::ptr<Probe> > probes;

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

            //User id as foreign key in other tables

            Wt::Dbo::hasMany(a,
                             user,
                             Wt::Dbo::ManyToMany,
                             "TJ_USR_ORG");
            Wt::Dbo::hasMany(a,
                             probes,
                             Wt::Dbo::ManyToOne,
                             "ORG_ID");
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesStrings["ADR"]=this->address;   
            mapClassAttributesStrings["CP"]=this->cp;
            mapClassAttributesStrings["CITY"]=this->city;                  
       }
};


#endif // ORGANIZATION_H
