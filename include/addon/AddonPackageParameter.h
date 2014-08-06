/* 
 * Header of Addon Package Parameter Table
 * @author ECHOES Technologies (MLA)
 * @date 09/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ADDONPACKAGEPARAMETER_H
#define	ADDONPACKAGEPARAMETER_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AddonPackageParameter : public Table
    {
        public:
            AddonPackageParameter();
            AddonPackageParameter(const AddonPackageParameter& orig);
            virtual ~AddonPackageParameter();

            static std::string TRIGRAM;

            Wt::Dbo::ptr<AssetArchitecture> assetArchitecture;
            Wt::Dbo::ptr<AssetDistribution> assetDistribution;
            Wt::Dbo::ptr<AssetRelease> assetRelease;

            Wt::Dbo::ptr<Addon> addon;

            Wt::Dbo::ptr<AddonPackage> addonPackage;

            Wt::WString addonVersion;
            Wt::WString packageVersion;
            Wt::WString minimumVersion;

            template<class Action>
            void persist(Action& a) {
                mapClassAttributesStrings["ADDON_VERSION"] = &this->addonVersion;
                mapClassAttributesStrings["PACKAGE_VERSION"] = &this->packageVersion;
                mapClassAttributesStrings["CPP_MINIMUM_VERSION"] = &this->minimumVersion;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, assetArchitecture, TRIGRAM_ADDON_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_ARCHITECTURE);
                Wt::Dbo::belongsTo(a, assetDistribution, TRIGRAM_ADDON_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_DISTRIBUTION);
                Wt::Dbo::belongsTo(a, assetRelease, TRIGRAM_ADDON_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_RELEASE);

                Wt::Dbo::belongsTo(a, addonPackage, TRIGRAM_ADDON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON_PACKAGE);
                Wt::Dbo::belongsTo(a, addon, TRIGRAM_ADDON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON);

            }
        private:
    };
  }
}

#endif	/* ADDONPACKAGEPARAMETER_H */

