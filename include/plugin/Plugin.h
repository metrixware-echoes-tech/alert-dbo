/**
 * @file Plugin.h
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

#ifndef PLUGIN_H
#define PLUGIN_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Plugin : public Table
    {
        public:
            Plugin();
            virtual ~Plugin();

            static std::string TRIGRAM;

            Wt::WString desc;
            Wt::WString versionRef;
            Wt::WString versionClient;
            
            Wt::Dbo::ptr<PluginReference> pluginReference;
            Wt::Dbo::ptr<Group> group;
            Wt::Dbo::ptr<Asset> asset;
            
            Wt::Dbo::collection<Wt::Dbo::ptr<Source>> sources;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["DESC"] = &this->desc;
                mapClassAttributesStrings["VERSION_REF"] = &this->versionRef;
                mapClassAttributesStrings["VERSION_CLIENT"] = &this->versionClient;
                Table::fieldFiller(a, *this);
                
                Wt::Dbo::belongsTo(a, pluginReference, TRIGRAM_PLUGIN SEP TRIGRAM_PLUGIN_REFERENCE);
                Wt::Dbo::belongsTo(a, group, TRIGRAM_PLUGIN SEP TRIGRAM_GROUP);
                Wt::Dbo::belongsTo(a, asset, TRIGRAM_PLUGIN SEP TRIGRAM_ASSET);
                
                //TJ
                Wt::Dbo::hasMany(a, sources, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN SEP TRIGRAM_SOURCE);
                
            }

        protected:
        private:
    };
  }
}

#endif // PLUGIN_H

