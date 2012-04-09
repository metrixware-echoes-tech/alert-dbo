/*
 * Copyright (C) 2010 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WServer>

#include <Wt/Auth/AuthWidget>
#include <Wt/Auth/PasswordService>

#include "PostgresConnector.h"
#include "Session.h"

class AuthApplication : public Wt::WApplication
{
public:
    AuthApplication(const Wt::WEnvironment& env)
        : Wt::WApplication(env)
    {
        PostgresConnector *pc = new PostgresConnector("echoes","echoes","127.0.0.1","5432","toto");
        maSession = pc->getSession();
        maSession->login().changed().connect(this, &AuthApplication::authEvent);

        useStyleSheet("css/style.css");

        Wt::Auth::AuthWidget *authWidget
            = new Wt::Auth::AuthWidget(Session::auth(), (*maSession).users(),
                                       (*maSession).login());

        authWidget->addPasswordAuth(&Session::passwordAuth());
        authWidget->addOAuth(Session::oAuth());
        authWidget->setRegistrationEnabled(true);

        authWidget->processEnvironment();

        root()->addWidget(authWidget);
    }

    void authEvent()
    {
        if ((*maSession).login().loggedIn())
            Wt::log("notice") << "User " << (*maSession).login().user().id()
                              << " logged in.";
        else
            Wt::log("notice") << "User logged out.";
    }

private:
    Session *maSession;
};

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    return new AuthApplication(env);
}

int main(int argc, char **argv)
{
    try
    {


        Wt::WServer server(argv[0]);

        server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);
        server.addEntryPoint(Wt::Application, createApplication,"", "/favicon.ico");

        Session::configureAuth();

        if (server.start())
        {
            Wt::WServer::waitForShutdown();
            server.stop();
        }
    }
    catch (Wt::WServer::Exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}



/*

    PostgresConnector *pc = new PostgresConnector("echoes","echoes","127.0.0.1","5432","toto");
    Wt::Dbo::Session *maSession = pc->getSession();
    pc->generateModel(false);



int main(int argc, char **argv)
{
    run();
}
*/
