/* 
 * Header of Engine Organization Table
 * @author ECHOES Technologies (TSA)
 * @date 21/04/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ENGORG_H
#define	ENGORG_H

#include "tools/MainIncludeFile.h"
#include "primaryKeys/EngOrgId.h"

namespace Echoes
{
  namespace Dbo
  {
    class EngOrg : public Table
    {
        public:
            EngOrg();
            EngOrg(const EngOrg& orig);
            virtual ~EngOrg();

            static std::string TRIGRAM;

            EngOrgId pk;

            Wt::WString token;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["TOKEN"] = &this->token;
                Table::fieldFiller(a, *this);

                Wt::Dbo::id(a, pk, "PRIMARY_KEY");
            }

        private:
    };
  }
}

#endif	/* ENGORG_H */

