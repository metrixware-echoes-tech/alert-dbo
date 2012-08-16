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
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationUnit> > informationUnits;
        
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesDates["DELETE"]=&this->deleteTag;
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,informationUnits,Wt::Dbo::ManyToMany, "TJ" SEP TRIGRAM_ALERT_CRITERIA SEP TRIGRAM_INFORMATION_UNIT);
        }
    protected:
    private:
};

#endif // ALERTCRITERIA_H
