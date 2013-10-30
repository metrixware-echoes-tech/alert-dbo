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

        std::string User::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();
            res += Table::formatJSONForDboPtr(this->userRole);
            res += Table::formatJSONForDboPtr(this->userProfile);
            res += Table::formatJSONForDboPtr(this->currentOrganization);

            res += Table::formatJSONForDboCollection(this->userValues, "user_values");
            res += Table::formatJSONForDboCollection(this->parents, "parents");
            res += Table::formatJSONForDboCollection(this->children, "children");
            res += Table::formatJSONForDboCollection(this->historicalActions, "historical_actions");
            res += Table::formatJSONForDboCollection(this->alertAcks, "alert_acks");
            res += Table::formatJSONForDboCollection(this->mediaValues, "media_values");
            res += Table::formatJSONForDboCollection(this->userFields, "user_fields");
            res += Table::formatJSONForDboCollection(this->organizations, "organizations", false);

            res += "}";
            return res;
        }

        /*template<>
        void QuiSuisJe<User>(const User & x)
        {
            cout << "Je suis un <User>" << endl;
        }*/

        std::string User::getName()
        {
            return Constants::T_USER_USR;
        }
    }
}

