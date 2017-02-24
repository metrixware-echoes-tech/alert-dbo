/**
 * @file Message.h
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

#ifndef MESSAGE_H
#define	MESSAGE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Message : public Table
    {
        public:
            Message();
            virtual ~Message();

            static std::string TRIGRAM;

            boost::optional<Wt::WString> content;
            boost::optional<Wt::WString> senderSrv;
            boost::optional<Wt::WString> senderPort;
            boost::optional<Wt::WString> receiverSrv;
            boost::optional<Wt::WString> receiverPort;


            boost::optional<Wt::WString> refAck;
            boost::optional<Wt::WString> dest;
            
            Wt::Dbo::ptr<User> user;
            Wt::Dbo::ptr<Alert> alert;

            Wt::Dbo::collection<Wt::Dbo::ptr<MessageTrackingEvent> > messageTrackingEvents;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStringsNn["CONTENT"] = &this->content;
                mapClassAttributesStringsNn["SENDER_SRV"] = &this->senderSrv;
                mapClassAttributesStringsNn["RECEIVER_SRV"] = &this->receiverSrv;
                mapClassAttributesStringsNn["SENDER_PORT"] = &this->senderPort;
                mapClassAttributesStringsNn["RECEIVER_PORT"] = &this->receiverPort;
                mapClassAttributesStringsNn["REF_ACK"] = &this->refAck;
                mapClassAttributesStringsNn["DEST"] = &this->dest;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, user, TRIGRAM_MESSAGE SEP TRIGRAM_USER);
                Wt::Dbo::belongsTo(a, alert, TRIGRAM_MESSAGE SEP TRIGRAM_ALERT);

                Wt::Dbo::hasMany(a,
                        messageTrackingEvents,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_MESSAGE_TRACKING_EVENT SEP TRIGRAM_MESSAGE);
            }

        protected:
        private:
    };
  }
}

#endif	/* MESSAGE_H */
