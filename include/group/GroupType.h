/* 
 * Header of Group Type Table
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

#ifndef GROUPTYPE_H
#define GROUPTYPE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class GroupType : public Table
    {
        public:
            GroupType();
            virtual ~GroupType();

            static std::string TRIGRAM;

            enum eType
            {
                Company = 1,
                Individual = 2,
                Association = 3,
                Default = 4
            };

            Wt::WString name;

            Wt::Dbo::collection<Wt::Dbo::ptr<Group> > group;
            Wt::Dbo::collection<Wt::Dbo::ptr<GroupField> > groupField;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                Table::fieldFiller(a, *this);
                Wt::Dbo::hasMany(a,
                        groupField,
                        Wt::Dbo::ManyToMany,
                        "TJ_GFI_GTY");

                Wt::Dbo::hasMany(a,
                        group,
                        Wt::Dbo::ManyToOne,
                        "GRP_GTY");


            }

        private:
    };
  }
}

#endif // GROUPTYPE_H

