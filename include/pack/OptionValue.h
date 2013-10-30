/* 
 * Header of Option Value Table
 * @author ECHOES Technologies (RHI)
 * @date 10/09/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef OPTIONVALUE_H
#define	OPTIONVALUE_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"
#include "primaryKeys/OptionValueId.h"

namespace Echoes
{
  namespace Dbo
  {
    class OptionValue : public Table
    {
        public:
            OptionValue();
            virtual ~OptionValue();

            static std::string TRIGRAM;
            Wt::WString value;

            OptionValueId pk;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;

                FIELD_FILLER();

                Wt::Dbo::id(a, pk, TRIGRAM_OPTION_VALUE SEP ID);
            }

            virtual std::string toJSON() const;

        private:
    };
  }
}

#endif	/* OPTIONVALUE_H */

