#ifndef ASSET_H
#define ASSET_H

#include "Table.h"

#include <Wt/Dbo/Dbo>

#include "Plugin.h"

class Plugin;

class Asset : public Table
{
    public:
        Asset();
        virtual ~Asset();
        
        static std::string TRIGRAM;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;
        
        template<class Action>
        void persist(Action& a)
        {         
            //TJ
            Wt::Dbo::hasMany(a,
                             plugins,
                             Wt::Dbo::ManyToMany,
                             "TJ_AST_PLG");
       }
        
    protected:
    private:
};

#endif // ASSET_H
