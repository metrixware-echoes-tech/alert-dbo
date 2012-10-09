#ifndef UNIT_H
#define UNIT_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class InformationUnitType;
class Search;

class InformationUnit : public Table
{
    public:
        InformationUnit();
        virtual ~InformationUnit();
        
        static std::string TRIGRAM;
        
        Wt::WString name;
        Wt::WString longName;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<MediaValue> > mediaValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<SearchUnit> > searchUnits;
        Wt::Dbo::ptr<InformationUnitType> unitType;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesStrings["LONG_NAME"]=&this->longName;
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a, unitType, TRIGRAM_INFORMATION_UNIT SEP TRIGRAM_INFORMATION_UNIT_TYPE);
            
            Wt::Dbo::hasMany(a,
                             searchUnits,
                             Wt::Dbo::ManyToOne,
                             "SEU_INU");
         
        }
    protected:
    private:
};

#endif // UNIT_H
