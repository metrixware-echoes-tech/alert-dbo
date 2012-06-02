#ifndef ALERTHISTO_H
#define ALERTHISTO_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Alert.h"
#include "AlertValue.h"
#include "AlertCriteria.h"

class Alert;

class AlertHisto : public Table
{
    public:
        AlertHisto();
        virtual ~AlertHisto();
        Wt::Dbo::ptr<Alert> alert;
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, alert, "ALH");
        }
        
    protected:
    private:
};

#endif // ALERTHISTO_H
