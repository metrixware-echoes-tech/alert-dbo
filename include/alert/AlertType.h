#ifndef ALERTTYPE_H
#define ALERTTYPE_H

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"

class Alert;
class AlertCriteria;

class AlertType : public Table
{
    public:
        AlertType();
        virtual ~AlertType();
        
        static std::string TRIGRAM;
        
        std::string name;
        Wt::WDateTime deleteTag;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertCriteria> > alertCriterias;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             alerts,
                             Wt::Dbo::ManyToOne,
                             "ATY");
            Wt::Dbo::hasMany(a,
                             alertCriterias,
                             Wt::Dbo::ManyToMany,
                             "TJ_ATY_ACR");
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesDates["DELETE"]=this->deleteTag;
        }
        
    protected:
    private:
};

#endif // ALERTTYPE_H
