#ifndef WIDGETVALUE_H
#define WIDGETVALUE_H

#include <Wt/Dbo/Dbo>

//#include "WidgetValueId.h"
#include "Table.h"

class WidgetValue
{
    public:
        WidgetValue();
        virtual ~WidgetValue();
        
//        WidgetValueId pk;
        
        template<class Action>
        void persist(Action& a)
        {
//            Wt::Dbo::id(a, pk , "PRIMARY_KEY");
        }
    protected:
    private:
};

#endif // WIDGETVALUE_H
