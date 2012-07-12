#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WServer>

#include "tools/MainIncludeFile.h"

//#include "PostgresConnector.h"
#include "tools/AuthApplication.h"
#include "tools/Session.h"

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
//
//
//
///*
//
//    PostgresConnector *pc = new PostgresConnector("echoes","echoes","127.0.0.1","5432","toto");
//    Wt::Dbo::Session *maSession = pc->getSession();
//    pc->generateModel(false);
//
//
//
//int main(int argc, char **argv)
//{
//    run();
//}
//*/
