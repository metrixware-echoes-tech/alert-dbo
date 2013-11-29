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

#ifndef OPTION_H
#define	OPTION_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Option : public Table
    {
        public:
            Option();
            virtual ~Option();

            static std::string TRIGRAM;
            Wt::WString value;

            Wt::Dbo::ptr<OptionType> optionType;
            Wt::Dbo::ptr<Organization> organization;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;

                FIELD_FILLER();

                Wt::Dbo::belongsTo(a, optionType, TRIGRAM_OPTION SEP TRIGRAM_OPTION_TYPE);
                Wt::Dbo::belongsTo(a, organization, TRIGRAM_OPTION SEP TRIGRAM_ORGANIZATION);
            }

        private:
    };
  }
}

#endif	/* OPTION_H */

