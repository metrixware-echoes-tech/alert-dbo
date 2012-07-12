#ifndef ASSET_H
#define ASSET_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class Plugin;
class Probe;

class Asset : public Table
{
    public:
        Asset();
        virtual ~Asset();
        
        static std::string TRIGRAM;
        
        std::string name;
        bool assetIsHost;
        
        Wt::Dbo::ptr<Probe> probe;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Value> > values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue> > historicalValues;
        
        template<class Action>
        void persist(Action& a)
        { 
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesBools["IS_HOST"]=this->assetIsHost;
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a,probe,"AST_PRB");
            
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
            
            
            
       }
        
    protected:
    private:
};

#endif // ASSET_H
