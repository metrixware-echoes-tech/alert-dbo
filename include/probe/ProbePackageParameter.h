/* 
 * Header of Probe Package Parameter Table
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

#ifndef PROBEPACKAGEPARAMETER_H
#define	PROBEPACKAGEPARAMETER_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

class ProbePackageParameter : public Table {
public:
    ProbePackageParameter();
    ProbePackageParameter(const ProbePackageParameter& orig);
    virtual ~ProbePackageParameter();
    
    static std::string TRIGRAM;
    
    Wt::Dbo::ptr<AssetArchitecture> assetArchitecture;
    Wt::Dbo::ptr<AssetDistribution> assetDistribution;
    Wt::Dbo::ptr<AssetRelease> assetRelease;
    
    Wt::Dbo::ptr<ProbePackage> probePackage;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<Probe>> probes;
    
    Wt::WString probeVersion;
    Wt::WString packageVersion;
    Wt::WString minimumVersion;
    
    template<class Action>
    void persist(Action& a)
    { 
        mapClassAttributesStrings["PROBE_VERSION"]=&this->probeVersion;
        mapClassAttributesStrings["PACKAGE_VERSION"]=&this->packageVersion;
        mapClassAttributesStrings["CPP_MINIMUM_VERSION"]=&this->minimumVersion;

        FIELD_FILLER();
        
        Wt::Dbo::belongsTo(a,assetArchitecture,TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_ARCHITECTURE);
        Wt::Dbo::belongsTo(a,assetDistribution,TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_DISTRIBUTION);
        Wt::Dbo::belongsTo(a,assetRelease,TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_RELEASE);
        
        Wt::Dbo::belongsTo(a,probePackage,TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_PROBE_PACKAGE);
        
        Wt::Dbo::hasMany(a,probes,Wt::Dbo::ManyToOne, TRIGRAM_PROBE SEP TRIGRAM_PROBE_PACKAGE_PARAMETER);

   }
    
private:

};

#endif	/* PROBEPACKAGEPARAMETER_H */

