/* 
 * Header of Alert Tracking Event Table
 * @author ECHOES Technologies (TSA)
 * @date 30/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ALERTACKNOWLEDGEEVENT_H
#define	ALERTACKNOWLEDGEEVENT_H

#include <tools/MainIncludeFile.h>

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
            Wt::WString value;
            Wt::WDateTime date;

            Wt::Dbo::ptr<Message> message;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;
                mapClassAttributesDates["DATE"] = &this->date;
                Table::fieldFiller(a, *this);
                Wt::Dbo::belongsTo(a, message, TRIGRAM_MESSAGE_TRACKING_EVENT SEP TRIGRAM_MESSAGE);
            }

        private:
    };
  }
}

#endif	/* ALERTACKNOWLEDGEEVENT_H */

