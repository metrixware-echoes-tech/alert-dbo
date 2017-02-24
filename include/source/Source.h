/**
 * @file Source.h
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

#ifndef SOURCE_H
#define	SOURCE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Source : public Table
    {
        public:
            Source();
            Source(const Source& orig);
            virtual ~Source();

            static std::string TRIGRAM;

            Wt::Dbo::ptr<Addon> addon;
            
            Wt::Dbo::collection<Wt::Dbo::ptr<Search>> searches;

            Wt::Dbo::collection<Wt::Dbo::ptr<Plugin>> plugins;

            template<class Action>
            void persist(Action& a)
            {
                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, addon, TRIGRAM_SOURCE SEP TRIGRAM_ADDON);
                
                Wt::Dbo::hasMany(a, searches, Wt::Dbo::ManyToOne, TRIGRAM_SEARCH SEP TRIGRAM_SOURCE);
                
                Wt::Dbo::hasMany(a, plugins, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN SEP TRIGRAM_SOURCE);
            }

        private:
    };
  }
}

#endif	/* SOURCE_H */
