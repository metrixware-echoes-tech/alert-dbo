/**
 * @file AddonCommonPackageParameter.h
 * @author Thomas Saquet, Florent Poinsaut
 * @date 
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Alert - Dbo is the database objects library, part of the Alert software
 * Copyright (C) 2013-2017
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
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
