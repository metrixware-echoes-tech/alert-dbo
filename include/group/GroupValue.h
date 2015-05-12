/* 
 * Header of Group Value Table
 * @author ECHOES Technologies (RHI)
 * @date 03/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef GROUPVALUE_H
#define GROUPVALUE_H

#include "tools/MainIncludeFile.h"
#include "primaryKeys/GroupValueId.h"

namespace Echoes
{
  namespace Dbo
  {
    class GroupValue : public Table
    {
        public:
            GroupValue();
            virtual ~GroupValue();

            static std::string TRIGRAM;

            Wt::WString value;

            GroupValueId pk;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;

                Table::fieldFiller(a, *this);

                Wt::Dbo::id(a, pk, "OVA_ID");

            }
        private:
    };
  }
}

#endif // GROUPVALUE_H

