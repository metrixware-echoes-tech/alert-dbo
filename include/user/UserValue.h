/* 
 * Header of User Value Table
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

#ifndef USERVALUE_H
#define USERVALUE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class UserValue : public Table
    {
        public:
            UserValue();
            virtual ~UserValue();

            static std::string TRIGRAM;

            Wt::WString value;

            UserValueId uvid;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;
                Table::fieldFiller(a, *this);
                Wt::Dbo::id(a, uvid, "PRIMARY_KEY");
            }
        protected:
        private:
    };
  }
}

#endif // USERVALUE_H

