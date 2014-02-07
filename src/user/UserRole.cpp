/* 
 * User Role Table
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

#include "user/UserRole.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string UserRole::TRIGRAM(TRIGRAM_USER_ROLE);

        UserRole::UserRole()
        {
            this->jsonName = "user_role";
            //ctor
        }

        UserRole::~UserRole()
        {

        }

        std::string UserRole::toJSON() const
        {
            std::string res = "";
            res += "\t";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->users, "users", false);

            res += "\t}";
            return res;
        }
    }
}

