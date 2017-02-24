/**
 * @file MessageTrackingEvent.h
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

#ifndef MESSAGETRACKINGEVENT_H
#define	MESSAGETRACKINGEVENT_H

#include <tools/MainIncludeFile.h>

#include "MessageStatus.h"

namespace Echoes
{
  namespace Dbo
  {
    class MessageTrackingEvent : public Table
    {
        public:
            MessageTrackingEvent();
            MessageTrackingEvent(const MessageTrackingEvent& orig);
            virtual ~MessageTrackingEvent();

            static std::string TRIGRAM;

            //    boost::optional<std::string> eventValue;
            
            Wt::WDateTime date;
            Wt::WString text;
            
            Wt::Dbo::ptr<MessageStatus> statut;
            Wt::Dbo::ptr<Message> message;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesDates["DATE"] = &this->date;
                mapClassAttributesStrings["MESSAGE"] = &this->text;
                
                Table::fieldFiller(a, *this);
                
                Wt::Dbo::belongsTo(a, statut, TRIGRAM_MESSAGE_TRACKING_EVENT SEP TRIGRAM_MESSAGE_STATUS);
                Wt::Dbo::belongsTo(a, message, TRIGRAM_MESSAGE_TRACKING_EVENT SEP TRIGRAM_MESSAGE);
            }

        private:
    };
  }
}

#endif	/* MESSAGETRACKINGEVENT_H */
