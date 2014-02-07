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
#include <Wt/Dbo/Dbo>

#include <boost/optional.hpp>

namespace Echoes
{
  namespace Dbo
  {
    class AlertTrackingEvent : public Table
    {
        public:
            AlertTrackingEvent();
            AlertTrackingEvent(const AlertTrackingEvent& orig);
            virtual ~AlertTrackingEvent();
            static std::string TRIGRAM;
            //    boost::optional<std::string> eventValue;
            Wt::WString value;
            Wt::WDateTime date;

            Wt::Dbo::ptr<AlertTracking> alertTracking;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;
                mapClassAttributesDates["DATE"] = &this->date;
                FIELD_FILLER();
                Wt::Dbo::belongsTo(a, alertTracking, TRIGRAM_ALERT_TRACKING_EVENT SEP TRIGRAM_ALERT_TRACKING);
            }

            virtual std::string toJSON() const;

        private:
    };
  }
}

#endif	/* ALERTACKNOWLEDGEEVENT_H */

