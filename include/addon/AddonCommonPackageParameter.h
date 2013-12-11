/* 
 * File:   AddonCommonPackageParameter.h
 * Author: mla
 *
 * Created on 8 octobre 2013, 13:51
 */

#ifndef ADDONCOMMONPACKAGEPARAMETER_H
#define	ADDONCOMMONPACKAGEPARAMETER_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>


namespace Echoes {
    namespace Dbo {

        class AddonCommonPackageParameter : public Table {
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

                FIELD_FILLER();

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

