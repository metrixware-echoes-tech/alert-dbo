/**
 * @file AlertMediaSpecialization.h
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

#ifndef ALERTMEDIASPECIALIZATION_H
#define	ALERTMEDIASPECIALIZATION_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertMediaSpecialization : public Table
    {
        public:
            AlertMediaSpecialization();
            AlertMediaSpecialization(const AlertMediaSpecialization& orig);
            virtual ~AlertMediaSpecialization();

            static std::string TRIGRAM;

            Wt::WDateTime lastSend; //last time the alert was send to a media
            bool notifEndOfAlert;
            int snoozeDuration;
            Wt::WString message;

            Wt::Dbo::ptr<Alert> alert;
            Wt::Dbo::ptr<Media> media;
            
            Wt::Dbo::collection<Wt::Dbo::ptr<AlertTimeSlot> > timeSlots;
            
            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesBools["NOTIF_END_OF_ALERT"] = &this->notifEndOfAlert;
                mapClassAttributesInts["SNOOZE"] = &this->snoozeDuration;
                mapClassAttributesDates["LAST_SEND"] = &this->lastSend;
                mapClassAttributesStrings["MESSAGE"] = &this->message;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, alert, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_ALERT);
                Wt::Dbo::belongsTo(a, media, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_MEDIA);
                Wt::Dbo::hasMany(a, timeSlots, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_TIMESLOT SEP TRIGRAM_ALERT_MEDIA_SPECIALIZATION);
            }

        private:
    };
  }
}

#endif	/* ALERTMEDIASPECIALIZATION_H */
