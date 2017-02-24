/**
 * @file Session.h
 * @author Thomas Saquet, Florent Poinsaut
 * @date 
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Alert - Dbo is the database objects library, part of the Alert software
 * Copyright (C) 2013-2017
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
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
