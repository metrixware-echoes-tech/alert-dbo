#ifndef PROBE_H
#define PROBE_H

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"

class Organization;
class Value;
class HistoricalValue;

class Probe : public Table
{
    public:
        Probe();
        virtual ~Probe();
   

//        ProbeId pk;
        
       Wt::WDateTime deleteTag;
       static std::string TRIGRAM;             
       std::string name;
       std::string key;
        
        Wt::Dbo::ptr<Organization> organization;

        Wt::Dbo::collection<Wt::Dbo::ptr<Value> > values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue> > historicalValues;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Syslog> > syslogs;

        template<class Action>
        void persist(Action& a)
        {
//            Wt::Dbo::id (a, pk, "PRIMARY_KEY");
            Wt::Dbo::belongsTo(a, organization, "ORG");

            Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             "VPR");
            Wt::Dbo::hasMany(a,
                             historicalValues,
                             Wt::Dbo::ManyToOne,
                             "HPR");
            Wt::Dbo::hasMany(a,
                             syslogs,
                             Wt::Dbo::ManyToOne,
                             "PRB");
            mapClassAttributesDates["DELETE"]=this->deleteTag;
            mapClassAttributesStrings["NAME"]=this->name;            
            mapClassAttributesStrings["KEY"]=this->key;              
        };

    protected:
    private:
};

#endif // PROBE_H
