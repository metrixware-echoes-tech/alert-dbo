/* 
 * File:   MessageStatus.h
 * Author: cde
 *
 * Created on 26 juin 2015, 16:46
 */

#ifndef MESSAGESTATUS_H
#define	MESSAGESTATUS_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class MessageStatus : public Table
    {
        public:
            MessageStatus();
            virtual ~MessageStatus();

            static std::string TRIGRAM;

            Wt::Dbo::collection<Wt::Dbo::ptr<MessageTrackingEvent> > messagesTrackingEvent;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;

                Table::fieldFiller(a, *this);
                Wt::Dbo::hasMany(a,
                        messagesTrackingEvent,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_MESSAGE_TRACKING_EVENT SEP TRIGRAM_MESSAGE_STATUS);
            }

        protected:
        private:
    };
  }
}

#endif	/* MESSAGESTATUS_H */

