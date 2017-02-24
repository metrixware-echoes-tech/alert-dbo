/**
 * @file PluginReference.h
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

#ifndef PLUGINREFERENCE_H
#define	PLUGINREFERENCE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class PluginReference : public Table {
        public:
            PluginReference();
            PluginReference(const PluginReference& orig);
            virtual ~PluginReference();

            static std::string TRIGRAM;

            Wt::WString desc;
            Wt::WString version;
            Wt::Dbo::collection<Wt::Dbo::ptr<Plugin>> plugins;
            Wt::Dbo::collection<Wt::Dbo::ptr<Source>> sources;
            Wt::Dbo::collection<Wt::Dbo::ptr<Group>> groups;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["DESC"] = &this->desc;
                mapClassAttributesStrings["VERSION"] = &this->version;
                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a, plugins, Wt::Dbo::ManyToOne, TRIGRAM_PLUGIN SEP TRIGRAM_PLUGIN_REFERENCE);

                //TJ
                Wt::Dbo::hasMany(a, sources, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN_REFERENCE SEP TRIGRAM_SOURCE);
                Wt::Dbo::hasMany(a, groups, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN_REFERENCE SEP TRIGRAM_GROUP);

            }

        private:
    };

  }
}

#endif	/* PLUGINREFERENCE_H */
