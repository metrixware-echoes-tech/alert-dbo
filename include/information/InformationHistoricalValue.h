/**
 * @file InformationHistoricalValue.h
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

#ifndef INFORMATIONHISTORICALVALUE_H
#define INFORMATIONHISTORICALVALUE_H

#include "tools/MainIncludeFile.h"

//#include "primaryKeys/InformationId.h"

namespace Echoes
{
  namespace Dbo
  {
    class InformationHistoricalValue : public Table
    {
        public:
            InformationHistoricalValue();
            virtual ~InformationHistoricalValue();

            static std::string TRIGRAM;

            Wt::WDateTime creationDate;
            Wt::WString value;

            short state;
            int lotNumber;
            int lineNumber;

            Wt::Dbo::ptr<Syslog> syslog;
            Wt::Dbo::ptr<InformationData> informationData;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesDates["CREA_DATE"] = &this->creationDate;
                mapClassAttributesStrings["VALUE"] = &this->value;
                mapClassAttributesShorts["STATE"] = &this->state;
                mapClassAttributesInts["LOT_NUM"] = &this->lotNumber;
                mapClassAttributesInts["LINE_NUM"] = &this->lineNumber;
                Table::fieldFiller(a, *this);
                Wt::Dbo::belongsTo(a, syslog, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_SYSLOG, Wt::Dbo::OnDeleteSetNull);
                Wt::Dbo::belongsTo(a, informationData, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_INFORMATION_DATA);
            }

        protected:
        private:
    };
  }
}

#endif // INFORMATIONHISTORICALVALUE_H

