#ifndef ADDON_H
#define ADDON_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class Plugin;

class Addon : public Table
{
    public:
        Addon();
        virtual ~Addon();
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;
        
        template<class Action>
        void persist(Action& a)
        {
            //TJ
            Wt::Dbo::hasMany(a,
                             plugins,
                             Wt::Dbo::ManyToMany,
                             "TJ_ADO_PLG"); 
        }
    protected:
    private:
};

#endif // ADDON_H
