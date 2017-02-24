/**
 * @file Filter.h
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

#ifndef FILTER_H
#define	FILTER_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Filter : public Table {
        public:
            Filter();
            Filter(const Filter& orig);
            virtual ~Filter();

            static std::string TRIGRAM;

            int nbValue;
            int posKeyValue;

            Wt::Dbo::ptr<FilterType> filterType;
            Wt::Dbo::ptr<Search> search;        

            Wt::Dbo::collection<Wt::Dbo::ptr<InformationData>> informationDatas;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesInts["NB_VALUE"] = &this->nbValue;
                mapClassAttributesInts["POS_KEY_VALUE"] = &this->posKeyValue;
                Table::fieldFiller(a, *this);
                Wt::Dbo::belongsTo(a, filterType, TRIGRAM_FILTER SEP TRIGRAM_FILTER_TYPE);
                Wt::Dbo::belongsTo(a, search, TRIGRAM_FILTER SEP TRIGRAM_SEARCH);
                Wt::Dbo::hasMany(a, informationDatas, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_FILTER);
            }

        private:
    };
  }
}

#endif	/* FILTER_H */
