/**
 * @file Syslog.h
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

#ifndef SYSLOG_H
#define	SYSLOG_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Syslog : public Table
    {
        public:
            Syslog();
            Syslog(const Syslog& orig);
            virtual ~Syslog();

            static std::string TRIGRAM;

            Wt::WString sd;
            Wt::WDateTime rcptDate;
            Wt::WDateTime sentDate;
            Wt::WString hostname;
            Wt::WString appName;
            Wt::WString msgId;
            int priority;
            int procId;

            boost::optional<int> version;
            // state : 0 = pending, 1 = processing, 2 = done
            short state;

            Wt::Dbo::ptr<Probe> probe;
            Wt::Dbo::collection<Wt::Dbo::ptr<InformationValue> > values;
            Wt::Dbo::collection<Wt::Dbo::ptr<InformationHistoricalValue> > historicalValues;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["SD"] = &this->sd;
                mapClassAttributesDates["RCPT_DATE"] = &this->rcptDate;
                mapClassAttributesDates["SENT_DATE"] = &this->sentDate;
                mapClassAttributesStrings["HOSTNAME"] = &this->hostname;
                mapClassAttributesStrings["APP_NAME"] = &this->appName;
                mapClassAttributesStrings["MSG_ID"] = &this->msgId;
                mapClassAttributesInts["PROC_ID"] = &this->procId;
                mapClassAttributesInts["PRI"] = &this->priority;
                mapClassAttributesIntsNn["VERSION"] = &this->version;
                mapClassAttributesShorts["STATE"] = &this->state;


                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, probe, "SLO_PRB");

                Wt::Dbo::hasMany(a,
                        values,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_SYSLOG);
                Wt::Dbo::hasMany(a,
                        historicalValues,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_SYSLOG);

            }

        private:
    };
  }
}

#endif	/* SYSLOG_H */
