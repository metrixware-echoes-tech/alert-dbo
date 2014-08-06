/* 
 * Header of Addon Common Package Parameter Table
 * @author ECHOES Technologies (MLA)
 * @date 08/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ADDONCOMMONPACKAGEPARAMETER_H
#define	ADDONCOMMONPACKAGEPARAMETER_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AddonCommonPackageParameter : public Table
    {
        public:
            AddonCommonPackageParameter();
            AddonCommonPackageParameter(const AddonCommonPackageParameter& orig);
            virtual ~AddonCommonPackageParameter();

            static std::string TRIGRAM;

            Wt::Dbo::ptr<AssetArchitecture> assetArchitecture;
            Wt::Dbo::ptr<AssetDistribution> assetDistribution;
            Wt::Dbo::ptr<AssetRelease> assetRelease;

            Wt::Dbo::ptr<AddonCommonPackage> addonCommonPackage;

            Wt::WString addonCommonVersion;
            Wt::WString packageVersion;
            Wt::WString minimumVersion;

            template<class Action>
            void persist(Action& a) {
                mapClassAttributesStrings["ADDON_COMMON_VERSION"] = &this->addonCommonVersion;
                mapClassAttributesStrings["PACKAGE_VERSION"] = &this->packageVersion;
                mapClassAttributesStrings["PPP_MINIMUM_VERSION"] = &this->minimumVersion;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, assetArchitecture, TRIGRAM_ADDON_COMMON_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_ARCHITECTURE);
                Wt::Dbo::belongsTo(a, assetDistribution, TRIGRAM_ADDON_COMMON_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_DISTRIBUTION);
                Wt::Dbo::belongsTo(a, assetRelease, TRIGRAM_ADDON_COMMON_PACKAGE_PARAMETER SEP TRIGRAM_ASSET_RELEASE);

                Wt::Dbo::belongsTo(a, addonCommonPackage, TRIGRAM_ADDON_COMMON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON_COMMON_PACKAGE);

            }
        private:
    };
  }
}

#endif	/* ADDONCOMMONPACKAGEPARAMETER_H */

