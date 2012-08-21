#ifndef UNIT_H
#define UNIT_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class Information2;
class InformationUnitType;

class InformationUnit : public Table
{
    public:
        InformationUnit();
        virtual ~InformationUnit();
        
        static std::string TRIGRAM;
        
        Wt::WString name;
        Wt::WString longName;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<MediaValue> > mediaValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<Information2> > informations;
        Wt::Dbo::ptr<InformationUnitType> unitType;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesStrings["LONG_NAME"]=&this->longName;
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a, unitType, TRIGRAM_INFORMATION_UNIT SEP TRIGRAM_INFORMATION_UNIT_TYPE);
            
            Wt::Dbo::hasMany(a,
                             informations,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_INFORMATION SEP TRIGRAM_INFORMATION_UNIT);
            
            Wt::Dbo::hasMany(a,mediaValues,Wt::Dbo::ManyToMany, "TJ" SEP TRIGRAM_ALERT_CRITERIA SEP TRIGRAM_INFORMATION_UNIT);
            
            
            
        }
    protected:
    private:
};

#endif // UNIT_H
