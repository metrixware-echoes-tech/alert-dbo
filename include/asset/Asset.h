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
        
        Wt::WString name;
        bool assetIsHost;
        
        Wt::WString distribName;
        Wt::WString distribRelease;
        Wt::WString architecture;
        
        Wt::Dbo::ptr<Probe> probe;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationValue> > values;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationHistoricalValue> > historicalValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
        
        template<class Action>
        void persist(Action& a)
        { 
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesBools["IS_HOST"]=&this->assetIsHost;
            mapClassAttributesStrings["DISTRIB_NAME"]=&this->distribName;
            mapClassAttributesStrings["DISTRIB_RELEASE"]=&this->distribRelease;
            mapClassAttributesStrings["ARCHITECTURE"]=&this->architecture;
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a,probe,TRIGRAM_ASSET SEP TRIGRAM_PROBE);
            
            Wt::Dbo::hasMany(a, values, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_ASSET);
            Wt::Dbo::hasMany(a, historicalValues, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_ASSET);
            
            //TJ
            Wt::Dbo::hasMany(a, plugins, Wt::Dbo::ManyToMany, "TJ" SEP TRIGRAM_ASSET SEP TRIGRAM_PLUGIN);
            Wt::Dbo::hasMany(a, alerts, Wt::Dbo::ManyToMany, "TJ" SEP TRIGRAM_ASSET SEP TRIGRAM_ALERT);
       }
        
    protected:
    private:
};

#endif // ASSET_H
