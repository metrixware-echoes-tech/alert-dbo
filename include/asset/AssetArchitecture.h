/* 
 * File:   AssetArchitecture.h
 * Author: tsa
 *
 * Created on 25 janvier 2013, 15:41
 */

#ifndef ASSETARCHITECTURE_H
#define	ASSETARCHITECTURE_H

#include <tools/MainIncludeFile.h>
#include <Wt/Dbo/Dbo>

class AssetArchitecture : public Table {
public:
    AssetArchitecture();
    AssetArchitecture(const AssetArchitecture& orig);
    virtual ~AssetArchitecture();
    
    static std::string TRIGRAM;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<Asset>> assets;
    Wt::Dbo::collection<Wt::Dbo::ptr<ProbePackageParameter>> probePackageParameters;
    
    Wt::WString name;
    
    template<class Action>
        void persist(Action& a)
        { 
            mapClassAttributesStrings["NAME"]=&this->name;
            
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a, assets, Wt::Dbo::ManyToOne, TRIGRAM_ASSET SEP TRIGRAM_ASSET_ARCHITECTURE);
            Wt::Dbo::hasMany(a, probePackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_ARCHITECTURE);
            
       }
    
private:

};

#endif	/* ASSETARCHITECTURE_H */

