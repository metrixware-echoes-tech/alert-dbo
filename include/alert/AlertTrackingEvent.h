/* 
 * Header of Alert Tracking Event Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ALERTTRACKINGEVENT_H
#define ALERTTRACKINGEVENT_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertTrackingEvent : public Table
    {
        public:
            AlertTrackingEvent();
            virtual ~AlertTrackingEvent();

            static std::string TRIGRAM;

            Wt::WDateTime date;

            Wt::Dbo::ptr<AlertStatus> statut;
            Wt::Dbo::ptr<Alert> alert;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesDates["DATE"] = &this->date;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, statut, TRIGRAM_ALERT_TRACKING_EVENT SEP TRIGRAM_ALERT_STATUS);
                Wt::Dbo::belongsTo(a, alert, TRIGRAM_ALERT_TRACKING_EVENT SEP TRIGRAM_ALERT);
            }

        protected:
        private:
    };
  }
}

#endif // ALERTTRACKINGEVENT_H

