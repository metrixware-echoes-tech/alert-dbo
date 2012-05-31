#ifndef ALERTPARAM_H
#define ALERTPARAM_H

#include "Table.h"

#include "AlertValue.h"

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class AlertValue;
class AlertCriteria;

class AlertParam : public Table
{
    public:
        AlertParam();
        virtual ~AlertParam();
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertCriteria> > alertCriterias;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             alertValues,
                             Wt::Dbo::ManyToOne,
                             "APA");
            Wt::Dbo::hasMany(a,
                             alertCriterias,
                             Wt::Dbo::ManyToMany,
                             "TJ_ACR_APA");
        }
        
    protected:
    private:
};

#endif // ALERTPARAM_H
