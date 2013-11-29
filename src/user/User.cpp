/* 
 * User Table
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

#include "user/User.h"

#include <Wt/Dbo/Impl>
#include <Wt/Auth/Dbo/AuthInfo>

//DBO_INSTANTIATE_TEMPLATES(Echoes::Dbo::User)

namespace Echoes
{
    namespace Dbo
    {
        std::string User::TRIGRAM(TRIGRAM_USER);

        User::User() : Table()
        {
            this->jsonName = "user";
        }

        User::User(std::string firstName, std::string lastName, std::string eMail, std::string password, std::string token) : Table()
        {
            this->firstName = firstName;
            this->lastName = lastName;
            this->eMail = eMail;
            this->password = password;
            this->token = token;
        }

        User::~User()
        {
        }

        std::string User::getName()
        {
            return Constants::T_USER_USR;
        }
    }
}

