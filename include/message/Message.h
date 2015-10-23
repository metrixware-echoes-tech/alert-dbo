/* 
 * Header of Alert Tracking Table
 * @author ECHOES Technologies (TSA)
 * @date 23/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
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

