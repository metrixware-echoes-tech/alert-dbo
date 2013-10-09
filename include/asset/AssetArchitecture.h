/* 
 * Header of Asset Architecture Table
 * @author ECHOES Technologies (TSA)
 * @date 25/01/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
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

