/**
 * @file AlertValue.h
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

#ifndef ALERTVALUE_H
#define ALERTVALUE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertValue : public Table
    {
        public:
            AlertValue();
            virtual ~AlertValue();

            static std::string TRIGRAM;

            int flapping;
            Wt::WString value;
            boost::optional<Wt::WString> keyValue;

            Wt::Dbo::ptr<InformationData> informationData;
            Wt::Dbo::ptr<AlertCriteria> alertCriteria;

            Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
            Wt::Dbo::collection<Wt::Dbo::ptr<AlertSequence> > alertSequences;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesInts["FLAPPING"] = &this->flapping;
                mapClassAttributesStrings["VALUE"] = &this->value;
                mapClassAttributesStringsNn["KEY_VALUE"] = &this->keyValue;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, informationData, TRIGRAM_ALERT_VALUE SEP TRIGRAM_INFORMATION_DATA);
                Wt::Dbo::belongsTo(a, alertCriteria, TRIGRAM_ALERT_VALUE SEP TRIGRAM_ALERT_CRITERIA);

                Wt::Dbo::hasMany(a, alerts, Wt::Dbo::ManyToOne, TRIGRAM_ALERT SEP TRIGRAM_ALERT_VALUE);
                Wt::Dbo::hasMany(a, alertSequences, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_SEQUENCE SEP TRIGRAM_ALERT_VALUE);
            }

        protected:
        private:
    };
  }
}

#endif // ALERTVALUE_H

