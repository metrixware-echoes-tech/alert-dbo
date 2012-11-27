#ifndef UNIT_H
#define UNIT_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"
#include "InformationSubUnit.h"

class InformationUnitType;
class Search;

class InformationUnit : public Table
{
    public:
        InformationUnit();
        virtual ~InformationUnit();
        
        static std::string TRIGRAM;
        
        Wt::WString name; 
       
        Wt::Dbo::collection<Wt::Dbo::ptr<SearchUnit> > searchUnits;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationSubUnit> > informationSubUnits;
        Wt::Dbo::ptr<InformationUnitType> unitType;
        
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a, unitType, TRIGRAM_INFORMATION_UNIT SEP TRIGRAM_INFORMATION_UNIT_TYPE);
            
            Wt::Dbo::hasMany(a,
                             searchUnits,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_SEARCH_UNIT SEP TRIGRAM_INFORMATION_UNIT);
            
            Wt::Dbo::hasMany(a,
                             informationSubUnits,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_INFORMATION_SUB_UNIT SEP TRIGRAM_INFORMATION_UNIT);
         
        }
    protected:
    private:
};

#endif // UNIT_H
