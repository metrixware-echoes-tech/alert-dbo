/**
 * @file AddonCommonPackage.h
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

#ifndef ADDONCOMMONPACKAGE_H
#define	ADDONCOMMONPACKAGE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AddonCommonPackage : public Table
    {
        public:
            AddonCommonPackage();
            AddonCommonPackage(const AddonCommonPackage& orig);
            virtual ~AddonCommonPackage();

            static std::string TRIGRAM;

            Wt::WString filename;

            Wt::Dbo::collection<Wt::Dbo::ptr<AddonCommonPackageParameter >> addonCommonPackageParameters;

            template<class Action>
            void persist(Action& a) {
                mapClassAttributesStrings["FILENAME"] = &this->filename;

                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a, addonCommonPackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_ADDON_COMMON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON_COMMON_PACKAGE);
            }
        private:
    };
  }
}

#endif	/* ADDONCOMMONPACKAGE_H */
