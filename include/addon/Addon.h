#ifndef ADDON_H
#define ADDON_H


class Addon;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<Addon> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ADO_ID";
            }
        };
    }  
}


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
