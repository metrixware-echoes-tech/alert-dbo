#ifndef UNITTYPE_H
#define UNITTYPE_H

class Unit;

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class UnitType : public Table
{
    public:
        UnitType();
        virtual ~UnitType();
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Unit> > units;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<WidgetType> > widgetTypes;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             units,
                             Wt::Dbo::ManyToOne,
                             "UUN");
            

            //TJ
            Wt::Dbo::hasMany(a,
                             widgetTypes,
                             Wt::Dbo::ManyToMany,
                             "TJ_WTY_UTY");

            
        }
    protected:
    private:
};

#endif // UNITTYPE_H
