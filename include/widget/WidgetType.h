#ifndef WIDGETTYPE_H
#define WIDGETTYPE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"

class UnitType;
class Widget;

class WidgetType : public Table
{
    public:
        WidgetType();
        virtual ~WidgetType();
        
        Wt::Dbo::ptr<Widget> widget;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<UnitType> > unitTypes;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, widget, "WGT");
            //TJ
            Wt::Dbo::hasMany(a,
                             unitTypes,
                             Wt::Dbo::ManyToMany,
                             "TJ_WTY_UTY");
        }
    protected:
    private:
};

#endif // WIDGETTYPE_H
