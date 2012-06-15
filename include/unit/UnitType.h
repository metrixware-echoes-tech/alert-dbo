#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"

class Unit;
class WidgetType;

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
