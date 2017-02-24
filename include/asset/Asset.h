/**
 * @file Asset.h
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

#ifndef ASSET_H
#define ASSET_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Asset : public Table
    {
        public:
            Asset();
            virtual ~Asset();

            static std::string TRIGRAM;

            bool assetIsHost;

            Wt::Dbo::ptr<Group> group;

            Wt::Dbo::ptr<AssetArchitecture> assetArchitecture;
            Wt::Dbo::ptr<AssetDistribution> assetDistribution;
            Wt::Dbo::ptr<AssetRelease> assetRelease;
            
            Wt::Dbo::collection<Wt::Dbo::ptr<Probe>> probes;
            Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;
            Wt::Dbo::collection<Wt::Dbo::ptr<InformationData> > informationDatas;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesBools["IS_HOST"] = &this->assetIsHost;

                Table::fieldFiller(a, *this);
                
                Wt::Dbo::belongsTo(a, group, TRIGRAM_ASSET SEP TRIGRAM_GROUP);

                Wt::Dbo::belongsTo(a, assetArchitecture, TRIGRAM_ASSET SEP TRIGRAM_ASSET_ARCHITECTURE);
                Wt::Dbo::belongsTo(a, assetDistribution, TRIGRAM_ASSET SEP TRIGRAM_ASSET_DISTRIBUTION);
                Wt::Dbo::belongsTo(a, assetRelease, TRIGRAM_ASSET SEP TRIGRAM_ASSET_RELEASE);

                Wt::Dbo::hasMany(a, probes, Wt::Dbo::ManyToOne, TRIGRAM_PROBE SEP TRIGRAM_ASSET);
                Wt::Dbo::hasMany(a, informationDatas, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_ASSET);
                Wt::Dbo::hasMany(a, plugins, Wt::Dbo::ManyToOne, TRIGRAM_PLUGIN SEP TRIGRAM_ASSET);
            }

        protected:
        private:
    };
  }
}

#endif // ASSET_H

