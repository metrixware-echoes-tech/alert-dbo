/* 
 * File:   AddonPackageParameter.h
 * Author: mla
 *
 * Created on 9 octobre 2013, 14:52
 */

#ifndef ADDONPACKAGEPARAMETER_H
#define	ADDONPACKAGEPARAMETER_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>


namespace Echoes {
    namespace Dbo {

        class AddonPackageParameter : public Table {
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

                FIELD_FILLER();

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

