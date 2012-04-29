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
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             units,
                             Wt::Dbo::ManyToOne,
                             "UUN");
            
        }
    protected:
    private:
};

#endif // UNITTYPE_H
