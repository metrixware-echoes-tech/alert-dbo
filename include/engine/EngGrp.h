/* 
 * Header of Engine Group Table
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

#ifndef ENGGRP_H
#define	ENGGRP_H

#include "tools/MainIncludeFile.h"
#include "primaryKeys/EngGrpId.h"

namespace Echoes
{
  namespace Dbo
  {
    class EngGrp : public Table
    {
        public:
            EngGrp();
            EngGrp(const EngGrp& orig);
            virtual ~EngGrp();

            static std::string TRIGRAM;

            EngGrpId pk;

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

#endif	/* ENGGRP_H */

