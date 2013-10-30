/* 
 * Header of Information Sub Unit Table
 * @author ECHOES Technologies (TSA)
 * @date 08/11/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef INFORMATIONSUBUNIT_H
#define	INFORMATIONSUBUNIT_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {
    class InformationSubUnit : public Table
    {
        public:
            InformationSubUnit();
            InformationSubUnit(const InformationSubUnit& orig);
            virtual ~InformationSubUnit();

            static std::string TRIGRAM;
            int factor;
            Wt::WString name;

            Wt::Dbo::ptr<InformationUnit> informationUnit;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesInts["FACTOR"] = &this->factor;

                FIELD_FILLER();

                Wt::Dbo::belongsTo(a, informationUnit, TRIGRAM_INFORMATION_SUB_UNIT SEP TRIGRAM_INFORMATION_UNIT);
            }

            virtual std::string toJSON() const;

        private:
    };
  }
}

#endif	/* INFORMATIONSUBUNIT_H */

