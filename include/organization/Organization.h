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
        // methods

        Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;
        
        
        // dbo collections (This table id as foreign key in other tables)
        Wt::Dbo::collection<Wt::Dbo::ptr<User> > user;
        Wt::Dbo::collection<Wt::Dbo::ptr<Probe> > probes;
        Wt::Dbo::ptr<Pack> pack;
        Wt::Dbo::ptr<OrganizationType> organizationType;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesStrings["ADR"]=&this->address;   
            mapClassAttributesStrings["CP"]=&this->cp;
            mapClassAttributesStrings["CITY"]=&this->city;
            
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
            Wt::Dbo::hasMany(a,
                            users,
                            Wt::Dbo::ManyToOne,
                            "CURRENT");            
            Wt::Dbo::belongsTo(a, pack, "ORG_PCK");
            Wt::Dbo::belongsTo(a, organizationType, "ORG_OTY");                  
       }
};


#endif // ORGANIZATION_H
