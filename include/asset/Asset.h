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
        
        std::string name;
      //  bool assetIsHost;
        Wt::WDateTime deleteTag;
        
        //RHI: foreign key probe_id to add.
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Value> > values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue> > historicalValues;
        
        template<class Action>
        void persist(Action& a)
        { 
            Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             "VAL_AST");
            Wt::Dbo::hasMany(a,
                             historicalValues,
                             Wt::Dbo::ManyToOne,
                             "HVA_AST");
            
            //TJ
            Wt::Dbo::hasMany(a,
                             plugins,
                             Wt::Dbo::ManyToMany,
                             "TJ_AST_PLG");
            mapClassAttributesStrings["NAME"]=this->name;
     //     mapClassAttributesBools["IS_HOST"]=this->assetIsHost;
            mapClassAttributesDates["DELETE"]=this->deleteTag;
            
            
       }
        
    protected:
    private:
};

#endif // ASSET_H
