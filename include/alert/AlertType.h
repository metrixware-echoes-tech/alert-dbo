#ifndef ALERTTYPE_H
#define ALERTTYPE_H

#include "Table.h"

#include <Wt/Dbo/Dbo>

#include "Alert.h"
#include "AlertCriteria.h"

class Alert;
class AlertCriteria;

class AlertType : public Table
{
    public:
        AlertType();
        virtual ~AlertType();
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
        }
        
    protected:
    private:
};

#endif // ALERTTYPE_H
