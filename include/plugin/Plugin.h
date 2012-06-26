#ifndef PLUGIN_H
#define PLUGIN_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "MainIncludeFile.h"

class Source;
class Asset;

class Plugin : public Table
{
    public:
        Plugin();
        virtual ~Plugin();

        static std::string TRIGRAM;
        std::string name;
        std::string desc;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Source> > sources;
        Wt::Dbo::collection<Wt::Dbo::ptr<Asset> > assets;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;            
            mapClassAttributesStrings["DESC"]=this->desc;            
            FIELD_FILLER();
            //Plugin id as foreign key in other tables
            Wt::Dbo::hasMany(a,
                             sources,
                             Wt::Dbo::ManyToOne,
                             "SRC_PLG");
            
            //TJ
            Wt::Dbo::hasMany(a,
                             assets,
                             Wt::Dbo::ManyToMany,
                             "TJ_AST_PLG");
       }
    protected:
    private:
};

#endif // PLUGIN_H
