/* 
 * Header of Organization Field Table
 * @author ECHOES Technologies (TSA)
 * @date 09/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ORGANIZATIONFIELD_H
#define	ORGANIZATIONFIELD_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class OrganizationField : public Table
    {
        public:
            OrganizationField();
            virtual ~OrganizationField();

            static std::string TRIGRAM;

            Wt::WString format;

            Wt::Dbo::collection<Wt::Dbo::ptr<OrganizationType> > organizationType;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["FORMAT"] = &this->format;
                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a,
                        organizationType,
                        Wt::Dbo::ManyToMany,
                        "TJ_OFI_OTY");
            }
    };
  }
}

#endif	/* ORGANIZATIONFIELD_H */

