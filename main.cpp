#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WServer>

#include "Constants.h"
#include "Hierarchy.h"
#include "HistoricalAction.h"
#include "UserValue.h"
#include "UserAction.h"
#include "UserField.h"
#include "UserProfile.h"
#include "UserRole.h"
#include "User.h"

#include "Probe.h"

#include "Organization.h"

#include "PostgresConnector.h"
#include "AuthApplication.h"
#include "Session.h"

#include "Information.h"
#include "Value.h"
#include "HistoricalValue.h"

#include "Plugin.h"

#include "WidgetType.h"
#include "Widget.h"

#include "Unit.h"
#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"


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
