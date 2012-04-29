#ifndef UNIT_H
#define UNIT_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class Information2;
class UnitType;

class Unit : public Table
{
    public:
        Unit();
        virtual ~Unit();
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Information2> > informations;
        Wt::Dbo::ptr<UnitType> unitType;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, unitType, "UUN");
            
            Wt::Dbo::hasMany(a,
                             informations,
                             Wt::Dbo::ManyToOne,
                             "UIN");
            
        }
    protected:
    private:
};

#endif // UNIT_H
