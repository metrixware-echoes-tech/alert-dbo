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
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Information2> > informations;
        Wt::Dbo::ptr<InformationUnitType> unitType;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesStrings["LONG_NAME"]=&this->longName;
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a, unitType, "UNT_UTY");
            
            Wt::Dbo::hasMany(a,
                             informations,
                             Wt::Dbo::ManyToOne,
                             "INF_UNT");
            
            
            
        }
    protected:
    private:
};

#endif // UNIT_H
