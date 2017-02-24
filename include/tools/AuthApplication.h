/**
 * @file AuthApplication.h
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

#ifndef AUTHAPPLICATION_H
#define AUTHAPPLICATION_H

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/Auth/AuthWidget>
#include <Wt/Auth/PasswordService>

#include "tools/Session.h"

namespace Echoes
{
  namespace Dbo
  {

    class Session;

    class AuthApplication : public Wt::WApplication {
    public:

        AuthApplication(const Wt::WEnvironment& env)
        : Wt::WApplication(env),
        maSession("hostaddr=127.0.0.1 port=5432 dbname=echoes user=echoes password=toto") {
            maSession.login().changed().connect(this, &AuthApplication::authEvent);

            try {
                maSession.createTables();
                std::cerr << "Created database." << std::endl;
            } catch (std::exception& e) {
                std::cerr << e.what() << std::endl;
                std::cerr << "createTables problem : Session.cpp";
            }

            useStyleSheet("css/style.css");

            Wt::Auth::AuthWidget *authWidget
                    = new Wt::Auth::AuthWidget(Session::auth(), (maSession).users(),
                    (maSession).login());

            authWidget->model()->addPasswordAuth(&Session::passwordAuth());
            authWidget->model()->addOAuth(Session::oAuth());
            authWidget->setRegistrationEnabled(true);

            authWidget->processEnvironment();

            root()->addWidget(authWidget);
        }

        void authEvent() {
            if ((maSession).login().loggedIn())
                Wt::log("notice") << "User " << (maSession).login().user().id()
                << " logged in.";
            else
                Wt::log("notice") << "User logged out.";
        }

        Session maSession;
        //    PostgresConnector *pgc;

    private:

    };


  }
}

#endif // AUTHAPPLICATION_H
