/**
 * @file Alert.h
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

#ifndef ALERT_H
#define ALERT_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Alert : public Table
    {
        public:
            Alert();
            virtual ~Alert();

            static std::string TRIGRAM;
            //   Wt::WString name;
            Wt::WDateTime creaDate; //creation date of the alert
            Wt::WDateTime lastAttempt; //last time an engine process the alert (use to detect a zombie alert thread)
            int threadSleep;


            //        const Wt::WString& name_() const {return *name;};

            Wt::Dbo::collection<Wt::Dbo::ptr<AlertAcknowledge> > alertAcks;
            Wt::Dbo::collection<Wt::Dbo::ptr<AlertTracking> > alertTrackings;
            Wt::Dbo::collection<Wt::Dbo::ptr<AlertMediaSpecialization> > alertMediaSpecializations;

            Wt::Dbo::ptr<AlertValue> alertValue;
            Wt::Dbo::ptr<AlertSequence> alertSequence;
            Wt::Dbo::ptr<Engine> engine;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesDates["CREA_DATE"] = &this->creaDate;
                mapClassAttributesDates["LAST_ATTEMPT"] = &this->lastAttempt;
                mapClassAttributesInts["THREAD_SLEEP"] = &this->threadSleep;


                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a, alertAcks, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_ACKNOWLEDGE SEP TRIGRAM_ALERT);
                Wt::Dbo::hasMany(a, alertTrackings, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_TRACKING SEP TRIGRAM_ALERT);
                Wt::Dbo::hasMany(a, alertMediaSpecializations, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_ALERT);

                Wt::Dbo::belongsTo(a, alertValue, TRIGRAM_ALERT SEP TRIGRAM_ALERT_VALUE);
                Wt::Dbo::belongsTo(a, alertSequence, TRIGRAM_ALERT_SEQUENCE SEP "FIRST_ID");
                Wt::Dbo::belongsTo(a, engine, TRIGRAM_ALERT SEP TRIGRAM_ENGINE);
            }

        protected:
        private:
    };
  }
}
#endif // ALERT_H

