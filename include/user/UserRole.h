/* 
 * Header of User Role Table
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

#ifndef USERROLE_H
#define USERROLE_H

#include "tools/MainIncludeFile.h"
#include "primaryKeys/UserValueId.h"

namespace Echoes
{
  namespace Dbo
  {
    class UserRole : public Table
    {
        public:
            UserRole();
            virtual ~UserRole();

            static std::string TRIGRAM;

            Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

            Wt::Dbo::ptr<Group> group;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, group, TRIGRAM_USER_ROLE SEP TRIGRAM_GROUP);

                Wt::Dbo::hasMany(a,
                        users,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_USER SEP TRIGRAM_USER_ROLE);
            }
    };
  }
}

#endif // USERROLE_H

