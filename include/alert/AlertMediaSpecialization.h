/* 
 * Header of Alert Media Specialization Table
 * @author ECHOES Technologies (TSA)
 * @date 24/09/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ALERTMEDIASPECIALIZATION_H
#define	ALERTMEDIASPECIALIZATION_H

#include <Wt/Dbo/Dbo>
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

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesBools["NOTIF_END_OF_ALERT"] = &this->notifEndOfAlert;
                mapClassAttributesInts["SNOOZE"] = &this->snoozeDuration;
                mapClassAttributesDates["LAST_SEND"] = &this->lastSend;
                mapClassAttributesStrings["MESSAGE"] = &this->message;

                FIELD_FILLER();

                Wt::Dbo::belongsTo(a, alert, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_ALERT);
                Wt::Dbo::belongsTo(a, media, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_MEDIA);
            }

        private:
    };
  }
}

#endif	/* ALERTMEDIASPECIALIZATION_H */

