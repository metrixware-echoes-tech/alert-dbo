/**
 * @file Search.h
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

#ifndef SEARCH_H
#define	SEARCH_H

#include "Wt/Dbo/Dbo"

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Search : public Table
    {
        public:
            Search();
            Search(const Search& orig);
            virtual ~Search();

            static std::string TRIGRAM;
            int period;

            Wt::Dbo::ptr<SearchType> searchType;
            Wt::Dbo::ptr<Source> source;

            Wt::Dbo::collection<Wt::Dbo::ptr<Filter>> filters;
            
            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesInts["PERIOD"] = &this->period;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, searchType, TRIGRAM_SEARCH SEP TRIGRAM_SEARCH_TYPE);
                Wt::Dbo::belongsTo(a, source, TRIGRAM_SEARCH SEP TRIGRAM_SOURCE);
                Wt::Dbo::hasMany(a, filters, Wt::Dbo::ManyToOne, TRIGRAM_FILTER SEP TRIGRAM_SEARCH);
            }
        private:
    };
  }
}

#endif	/* SEARCH_H */
