#ifndef ALERTVALUE_H
#define ALERTVALUE_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class Alert;

class AlertValue : public Table
{
    public:
        AlertValue();
        virtual ~AlertValue();
        
        Wt::Dbo::ptr<Alert> alert;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::id(a,alert,"ALE_ID");
            
        }
    protected:
    private:
};

#endif // ALERTVALUE_H
