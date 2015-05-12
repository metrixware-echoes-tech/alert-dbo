/* 
 * Header of Group Field Table
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

#ifndef GROUPFIELD_H
#define	GROUPFIELD_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class GroupField : public Table
    {
        public:
            GroupField();
            virtual ~GroupField();

            static std::string TRIGRAM;

            Wt::WString format;

            Wt::Dbo::collection<Wt::Dbo::ptr<GroupType> > groupType;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["FORMAT"] = &this->format;
                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a,
                        groupType,
                        Wt::Dbo::ManyToMany,
                        "TJ_OFI_OTY");
            }
    };
  }
}

#endif	/* GROUPFIELD_H */

