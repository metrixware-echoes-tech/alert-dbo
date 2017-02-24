/**
 * @file InformationData.h
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

#ifndef INFORMATIONDATA_H
#define	INFORMATIONDATA_H

#include "tools/MainIncludeFile.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    class InformationData : public Table {
    public:
        InformationData();
        InformationData(const InformationData& orig);
        virtual ~InformationData();

        static std::string TRIGRAM;

        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationValue> > informationValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationHistoricalValue> > informationHistoricalValues;
        
        Wt::Dbo::ptr<Information> information;
        Wt::Dbo::ptr<Filter> filter;
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<InformationUnit> informationUnit;
        int filterFieldIndex;

        template<class Action>
        void persist(Action& a) {
            mapClassAttributesInts["FILTER_FIELD_INDEX"] = &this->filterFieldIndex;
            Table::fieldFiller(a, *this);
            
            Wt::Dbo::belongsTo(a, information, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_INFORMATION);
            Wt::Dbo::belongsTo(a, filter, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_FILTER);
            Wt::Dbo::belongsTo(a, asset, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_ASSET);
            Wt::Dbo::belongsTo(a, informationUnit, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_INFORMATION_UNIT);

            Wt::Dbo::hasMany(a, alertValues, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_VALUE SEP TRIGRAM_INFORMATION_DATA);
            Wt::Dbo::hasMany(a, informationValues, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_INFORMATION_DATA);
            Wt::Dbo::hasMany(a, informationHistoricalValues, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_INFORMATION_DATA);
        }

    private:
    };
  }
}

#endif	/* INFORMATIONDATA_H */
