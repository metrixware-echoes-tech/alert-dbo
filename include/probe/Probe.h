#ifndef PROBE_H
#define PROBE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class Organization;
class Value;
class HistoricalValue;

class Probe : public Table
{
    public:
        Probe();
        virtual ~Probe();
        
       static std::string TRIGRAM;             
       std::string name;
       std::string key;
        
        Wt::Dbo::ptr<Organization> organization;

        Wt::Dbo::collection<Wt::Dbo::ptr<Syslog> > syslogs;
        Wt::Dbo::collection<Wt::Dbo::ptr<Asset> > assets;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;            
            mapClassAttributesStrings["KEY"]=this->key; 
            FIELD_FILLER();
            Wt::Dbo::belongsTo(a, organization, "PRB_ORG");

            Wt::Dbo::hasMany(a,
                             syslogs,
                             Wt::Dbo::ManyToOne,
                             "SLO_PRB");
            Wt::Dbo::hasMany(a,
                             assets,
                             Wt::Dbo::ManyToOne,
                             "AST_PRB");
                         
        };

    protected:
    private:
};

#endif // PROBE_H
