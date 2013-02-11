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
//        boost::optional<Wt::WString> distribName;
//        boost::optional<Wt::WString> distribRelease;
//        boost::optional<Wt::WString> architecture;
        
        Wt::Dbo::ptr<Probe> probe;
        
        Wt::Dbo::ptr<Organization> organization;
        
        Wt::Dbo::ptr<AssetArchitecture> assetArchitecture;
        Wt::Dbo::ptr<AssetDistribution> assetDistribution;
        Wt::Dbo::ptr<AssetRelease> assetRelease;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationValue> > values;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationHistoricalValue> > historicalValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
        
        template<class Action>
        void persist(Action& a)
        { 
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesBools["IS_HOST"]=&this->assetIsHost;
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a,probe,TRIGRAM_ASSET SEP TRIGRAM_PROBE);
            Wt::Dbo::belongsTo(a,organization, TRIGRAM_ASSET SEP TRIGRAM_ORGANIZATION);
            
            Wt::Dbo::belongsTo(a,assetArchitecture,TRIGRAM_ASSET SEP TRIGRAM_ASSET_ARCHITECTURE);
            Wt::Dbo::belongsTo(a,assetDistribution,TRIGRAM_ASSET SEP TRIGRAM_ASSET_DISTRIBUTION);
            Wt::Dbo::belongsTo(a,assetRelease,TRIGRAM_ASSET SEP TRIGRAM_ASSET_RELEASE);
            
            
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
