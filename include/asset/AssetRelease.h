/* 
 * File:   AssetRelease.h
 * Author: tsa
 *
 * Created on 25 janvier 2013, 16:10
 */

#ifndef ASSETRELEASE_H
#define	ASSETRELEASE_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

class AssetRelease : public Table {
public:
    AssetRelease();
    AssetRelease(const AssetRelease& orig);
    virtual ~AssetRelease();
    
    static std::string TRIGRAM;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<Asset>> assets;
    Wt::Dbo::collection<Wt::Dbo::ptr<ProbePackageParameter>> probePackageParameters;
    
    Wt::WString name;
    
    template<class Action>
    void persist(Action& a)
    { 
        mapClassAttributesStrings["NAME"]=&this->name;

        FIELD_FILLER();
        
        Wt::Dbo::hasMany(a, assets, Wt::Dbo::ManyToOne, TRIGRAM_ASSET SEP TRIGRAM_ASSET_RELEASE);
        Wt::Dbo::hasMany(a, probePackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_RELEASE);

   }
    
private:

};

#endif	/* ASSETRELEASE_H */

