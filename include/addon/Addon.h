/**
 * @file Addon.h
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

#ifndef ADDON_H
#define ADDON_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Addon : public Table
    {
        public:
            Addon();
            virtual ~Addon();

            static std::string TRIGRAM;

            Wt::Dbo::collection<Wt::Dbo::ptr<Source> > sources;
            Wt::Dbo::collection<Wt::Dbo::ptr<SourceParameter> > sourceParameters;
            Wt::Dbo::collection<Wt::Dbo::ptr<SearchType> > searchTypes;

            Wt::Dbo::collection<Wt::Dbo::ptr<AddonPackageParameter> > addonPackageParameter;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                Table::fieldFiller(a, *this);
                Wt::Dbo::hasMany(a,
                        sources,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_SOURCE SEP TRIGRAM_ADDON);

                //TJ
                Wt::Dbo::hasMany(a,
                        sourceParameters,
                        Wt::Dbo::ManyToMany,
                        TABLE_JOINT_PREFIX SEP TRIGRAM_ADDON SEP TRIGRAM_SOURCE_PARAMETER);

                Wt::Dbo::hasMany(a,
                        searchTypes,
                        Wt::Dbo::ManyToMany,
                        TABLE_JOINT_PREFIX SEP TRIGRAM_ADDON SEP TRIGRAM_SEARCH_TYPE);                        

                Wt::Dbo::hasMany(a,
                        addonPackageParameter, 
                        Wt::Dbo::ManyToOne, 
                        TRIGRAM_ADDON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON);
            }

        protected:
        private:
    };
  }
}

#endif // ADDON_H

