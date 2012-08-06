#ifndef AUTHAPPLICATION_H
#define AUTHAPPLICATION_H

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/Auth/AuthWidget>
#include <Wt/Auth/PasswordService>

//#include "PostgresConnector.h"
#include "tools/Session.h"

//class PostgresConnector;
class Session;

class AuthApplication : public Wt::WApplication
{
public:
    AuthApplication(const Wt::WEnvironment& env)
        : Wt::WApplication(env),
        maSession("hostaddr=127.0.0.1 port=5432 dbname=echoes user=echoes password=toto")
    {
        maSession.login().changed().connect(this, &AuthApplication::authEvent);

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

    void authEvent()
    {
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

#endif // AUTHAPPLICATION_H
