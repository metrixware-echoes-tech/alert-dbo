/* 
 * File:   ProbePackageParameter.h
 * Author: tsa
 *
 * Created on 25 janvier 2013, 16:36
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
    
    Wt::WString probeVersion;
    Wt::WString packageVersion;
    
    template<class Action>
    void persist(Action& a)
    { 
        mapClassAttributesStrings["PROBE_VERSION"]=&this->probeVersion;
        mapClassAttributesStrings["PACKAGE_VERSION"]=&this->packageVersion;

        FIELD_FILLER();
        
         Wt::Dbo::belongsTo(a,assetArchitecture,TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_ARCHITECTURE);
         Wt::Dbo::belongsTo(a,assetDistribution,TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_DISTRIBUTION);
         Wt::Dbo::belongsTo(a,assetRelease,TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_RELEASE);
         
         Wt::Dbo::belongsTo(a,probePackage,TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_PROBE_PACKAGE);

   }
    
private:

};

#endif	/* PROBEPACKAGEPARAMETER_H */

