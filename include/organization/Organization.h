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
        // methods

        //RHI : manque lien avec PACK et ORGANISATION VALUE et TYPE
        
        
        // dbo collections (This table id as foreign key in other tables)
        Wt::Dbo::collection<Wt::Dbo::ptr<User> > user;
        Wt::Dbo::collection<Wt::Dbo::ptr<Probe> > probes;
        Wt::Dbo::ptr<Pack> pack;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesStrings["ADR"]=this->address;   
            mapClassAttributesStrings["CP"]=this->cp;
            mapClassAttributesStrings["CITY"]=this->city;
            
            FIELD_FILLER();

            //User id as foreign key in other tables

            Wt::Dbo::hasMany(a,
                             user,
                             Wt::Dbo::ManyToMany,
                             "TJ_USR_ORG");
            Wt::Dbo::hasMany(a,
                             probes,
                             Wt::Dbo::ManyToOne,
                             "PRB_ORG");
            Wt::Dbo::belongsTo(a, pack, "ORG_PCK");
                              
       }
};


#endif // ORGANIZATION_H
