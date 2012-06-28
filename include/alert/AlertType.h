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
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertCriteria> > alertCriterias;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;
            
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             alerts,
                             Wt::Dbo::ManyToOne,
                             "ALE_ATY");
            Wt::Dbo::hasMany(a,
                             alertCriterias,
                             Wt::Dbo::ManyToMany,
                             "TJ_ATY_ACR");
            
        }
        
    protected:
    private:
};

#endif // ALERTTYPE_H
