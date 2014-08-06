/* 
 * Header of Session
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

#ifndef SESSION_H_
#define SESSION_H_

#include <Wt/Auth/Login>
#include "Wt/Auth/AuthService"
#include "Wt/Auth/HashFunction"
#include "Wt/Auth/PasswordService"
#include "Wt/Auth/PasswordStrengthValidator"
#include "Wt/Auth/PasswordVerifier"
#include "Wt/Auth/GoogleService"
#include "Wt/Auth/Dbo/AuthInfo"

#include <Wt/Dbo/Session>
#include <Wt/Dbo/ptr>
#include <Wt/Dbo/backend/Postgres>

#include "tools/EchoesAlertDatabase.h"
#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class User;
    class Search;

    typedef EchoesAlertDatabase<AuthInfo, User> UserDatabase;

    class Session : public Wt::Dbo::Session
    {
        public:
            static void configureAuth();

            Session();
            Session(std::string connectionParams);
            ~Session();

            Wt::Dbo::ptr<User> user() const;

            UserDatabase& users();

            Wt::Auth::Login& login()
            {
                return login_;
            }

            static const Wt::Auth::AuthService& auth();
            static const Wt::Auth::PasswordService& passwordAuth();
            static const std::vector<const Wt::Auth::OAuthService *>& oAuth();
            void initConnection(std::string connectionParams);
            void initMapClass();

        private:
            Wt::Dbo::backend::Postgres connection_;
            UserDatabase users_;
            Wt::Auth::Login login_;
    };
  }
}

#endif // SESSION_H_

