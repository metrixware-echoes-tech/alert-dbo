/* 
 * Header of Alert Status Table
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

#ifndef ALERTSTATUS_H
#define ALERTSTATUS_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertStatus : public Table
    {
        public:
            AlertStatus();
            virtual ~AlertStatus();

            static std::string TRIGRAM;

            Wt::Dbo::collection<Wt::Dbo::ptr<AlertTrackingEvent> > alerts;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;

                Table::fieldFiller(a, *this);
                Wt::Dbo::hasMany(a,
                        alerts,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_ALERT SEP TRIGRAM_ALERT_STATUS);
            }

        protected:
        private:
    };
  }
}

#endif // ALERTSTATUS_H

