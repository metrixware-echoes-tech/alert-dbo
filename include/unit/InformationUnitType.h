#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class InformationUnit;
//class WidgetType;

class InformationUnitType : public Table
{
    public:
        InformationUnitType();
        virtual ~InformationUnitType();
        
        static std::string TRIGRAM;
        
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationUnit> > units;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertCriteria> > alertCriterias;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             units,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_INFORMATION_UNIT SEP TRIGRAM_INFORMATION_UNIT_TYPE);
            

            //TJ
            Wt::Dbo::hasMany(a, alertCriterias, Wt::Dbo::ManyToMany,"TJ" SEP TRIGRAM_ALERT_CRITERIA SEP TRIGRAM_INFORMATION_UNIT_TYPE);

            
        }
    protected:
    private:
};

#endif // UNITTYPE_H
