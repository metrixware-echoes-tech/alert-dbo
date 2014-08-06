/* 
 * User Action Table
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

#ifndef USERACTION_H
#define USERACTION_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class UserActionType : public Table
    {
        public:
            UserActionType();
            virtual ~UserActionType();

            static std::string TRIGRAM;

            // attributes


            // methods


            Wt::Dbo::collection<Wt::Dbo::ptr<UserHistoricalAction> > userHistoricalActions;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;

                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a,
                        userHistoricalActions,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_USER_HISTORICAL_ACTION SEP TRIGRAM_USER_ACTION_TYPE);
            }
    };
  }
}

#endif // USERACTION_H

