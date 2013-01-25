/* 
 * File:   AssetDistribution.h
 * Author: tsa
 *
 * Created on 25 janvier 2013, 15:58
 */

#ifndef ASSETDISTRIBUTION_H
#define	ASSETDISTRIBUTION_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

class AssetDistribution : public Table {
public:
    AssetDistribution();
    AssetDistribution(const AssetDistribution& orig);
    virtual ~AssetDistribution();
    
    static std::string TRIGRAM;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<Asset>> assets;
    Wt::Dbo::collection<Wt::Dbo::ptr<ProbePackageParameter>> probePackageParameters;
    
    Wt::WString name;
    
    template<class Action>
    void persist(Action& a)
    { 
        mapClassAttributesStrings["NAME"]=&this->name;

        FIELD_FILLER();
        
        Wt::Dbo::hasMany(a, assets, Wt::Dbo::ManyToOne, TRIGRAM_ASSET SEP TRIGRAM_ASSET_DISTRIBUTION);
        Wt::Dbo::hasMany(a, probePackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_DISTRIBUTION);

   }
    
    
private:

};

#endif	/* ASSETDISTRIBUTION_H */

