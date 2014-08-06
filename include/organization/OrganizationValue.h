/* 
 * Header of Organization Value Table
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

#ifndef ORGANIZATIONVALUE_H
#define ORGANIZATIONVALUE_H

#include "tools/MainIncludeFile.h"
#include "primaryKeys/OrganizationValueId.h"

namespace Echoes
{
  namespace Dbo
  {
    class OrganizationValue : public Table
    {
        public:
            OrganizationValue();
            virtual ~OrganizationValue();

            static std::string TRIGRAM;

            Wt::WString value;

            OrganizationValueId pk;

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

#endif // ORGANIZATIONVALUE_H

