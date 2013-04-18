#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <string>

// include Dbo
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "tools/MainIncludeFile.h"

class Organization : public Table
{
    public:
        Organization();
        virtual ~Organization();

        static std::string TRIGRAM;

        // attributes
        Wt::WString name;
        Wt::WString address;
        Wt::WString cp;
        Wt::WString city;
        Wt::WString token;
        // methods

        Wt::Dbo::collection<Wt::Dbo::ptr<User>> users;
        
        
        // dbo collections (This table id as foreign key in other tables)
        Wt::Dbo::collection<Wt::Dbo::ptr<User>> user;
        Wt::Dbo::collection<Wt::Dbo::ptr<Probe>> probes;
        Wt::Dbo::collection<Wt::Dbo::ptr<Asset>> assets;
        Wt::Dbo::ptr<Pack> pack;
        Wt::Dbo::ptr<OrganizationType> organizationType;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesStrings["ADR"]=&this->address;   
            mapClassAttributesStrings["CP"]=&this->cp;
            mapClassAttributesStrings["CITY"]=&this->city;
            mapClassAttributesStrings["TOKEN"]=&this->token;
            
            FIELD_FILLER();

            //User id as foreign key in other tables

            Wt::Dbo::hasMany(a,
                             user,
                             Wt::Dbo::ManyToMany,
                             "TJ" SEP TRIGRAM_USER SEP TRIGRAM_ORGANIZATION);
            Wt::Dbo::hasMany(a,
                             probes,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_PROBE SEP TRIGRAM_ORGANIZATION);
            Wt::Dbo::hasMany(a,
                             assets,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_ASSET SEP TRIGRAM_ORGANIZATION);
            Wt::Dbo::hasMany(a,
                            users,
                            Wt::Dbo::ManyToOne,
                            "CURRENT");            
            Wt::Dbo::belongsTo(a, pack, TRIGRAM_ORGANIZATION SEP TRIGRAM_PACK);
            Wt::Dbo::belongsTo(a, organizationType, TRIGRAM_ORGANIZATION SEP TRIGRAM_ORGANIZATION_TYPE);                  
       }
       virtual std::string toJSON();
};


#endif // ORGANIZATION_H
