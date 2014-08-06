/* 
 * Header of Alert Acknowledge Table
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

#ifndef ALERTACKNOWLEDGE_H
#define ALERTACKNOWLEDGE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertAcknowledge : public Table 
    {
        public:
            AlertAcknowledge();
            virtual ~AlertAcknowledge();

            static std::string TRIGRAM;

            Wt::Dbo::ptr<Alert> alert;
            Wt::Dbo::ptr<User> user;

            Wt::WString ackState;
            Wt::WString isLast;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["STATE"] = &this->ackState;
                mapClassAttributesStrings["IS_LAST"] = &this->isLast;
                Table::fieldFiller(a, *this);
                Wt::Dbo::belongsTo(a, alert, "ACK_ALE");
                Wt::Dbo::belongsTo(a, user, "ACK_USR");
            }

        protected:
        private:
    };
  }
}

#endif // ALERTACKNOWLEDGE_H

