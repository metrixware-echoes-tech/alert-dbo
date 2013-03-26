#ifndef ALERTCRITERIA_H
#define ALERTCRITERIA_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class AlertCriteria : public Table
{
    public:
        AlertCriteria();
        virtual ~AlertCriteria();
        
        static std::string TRIGRAM;
        Wt::WString name;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationUnitType> > informationUnitTypes;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,alertValues,Wt::Dbo::ManyToOne, TRIGRAM_ALERT_VALUE SEP TRIGRAM_ALERT_CRITERIA);
            
            Wt::Dbo::hasMany(a,informationUnitTypes,Wt::Dbo::ManyToMany, "TJ" SEP TRIGRAM_ALERT_CRITERIA SEP TRIGRAM_INFORMATION_UNIT_TYPE);
            
        }
        
        virtual std::string toJSON();
        
        
    protected:
    private:
};

#endif // ALERTCRITERIA_H
