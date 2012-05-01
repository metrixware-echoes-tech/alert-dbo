#ifndef ALERT_H
#define ALERT_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class AlertHisto;
class AlertValue;

class Alert : public Table
{
    public:
        Alert();
        virtual ~Alert();
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertHisto> > alertHistos;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             alertHistos,
                             Wt::Dbo::ManyToOne,
                             "ALH");
            Wt::Dbo::hasMany(a,
                             alertValues,
                             Wt::Dbo::ManyToOne,
                             "ALE_ID");
        }
    protected:
    private:
};

#endif // ALERT_H
