/**
 * @file AlertTracking.h
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

#ifndef ALERTTRACKING_H
#define	ALERTTRACKING_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertTracking : public Table
    {
        public:
            AlertTracking();
            virtual ~AlertTracking();

            static std::string TRIGRAM;

            boost::optional<Wt::WString> content;
            boost::optional<Wt::WString> senderSrv;
            Wt::WDateTime sendDate;
            boost::optional<Wt::WString> receiverSrv;
            Wt::WDateTime receiveDate;
            boost::optional<Wt::WString> ackGw;
            boost::optional<Wt::WString> ackPort;
            boost::optional<Wt::WString> ackId;

            Wt::Dbo::ptr<Media> media;
            Wt::Dbo::ptr<Alert> alert;

            Wt::Dbo::collection<Wt::Dbo::ptr<AlertTrackingEvent> > alertTrackingEvents;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStringsNn["CONTENT"] = &this->content;
                mapClassAttributesStringsNn["SENDER_SRV"] = &this->senderSrv;
                mapClassAttributesStringsNn["RECEIVER_SRV"] = &this->receiverSrv;
                mapClassAttributesStringsNn["ACK_GW"] = &this->ackGw;
                mapClassAttributesStringsNn["ACK_PORT"] = &this->ackPort;
                mapClassAttributesStringsNn["ACK_ID"] = &this->ackId;
                mapClassAttributesDates["SEND_DATE"] = &this->sendDate;
                mapClassAttributesDates["RECEIV_DATE"] = &this->receiveDate;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, media, TRIGRAM_ALERT_TRACKING SEP TRIGRAM_MEDIA);
                Wt::Dbo::belongsTo(a, alert, TRIGRAM_ALERT_TRACKING SEP TRIGRAM_ALERT);

                Wt::Dbo::hasMany(a,
                        alertTrackingEvents,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_ALERT_TRACKING_EVENT SEP TRIGRAM_ALERT_TRACKING);
            }

        protected:
        private:
    };
  }
}

#endif	/* ALERTTRACKING_H */
