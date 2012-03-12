/*
 * Copyright (C) 2010 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */


#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include <PostgresConnector.h>

#include "Constants.h"
#include "Hierarchy.h"
#include "UserRole.h"
#include "User.h"

class User;
class UserRole;

namespace odb = Wt::Dbo;
using namespace std;



void run()
{

    PostgresConnector *pc = new PostgresConnector("echoes","echoes","127.0.0.1","5432","toto");
    Wt::Dbo::Session *maSession = pc->getSession();
    maSession->mapClass<User>(Constants::T_USER_USR);
    maSession->mapClass<UserRole>(Constants::T_USER_ROLE_URO);
    maSession->mapClass<Hierarchy>(Constants::T_HIERARCHY_HRC);
    pc->generateModel(false);

    {
        odb::Transaction transaction(*maSession);
        User *user = new User("John","Smith","john@smith.com","toto");
        user->test();
        odb::ptr<User> userPtr = maSession->add(user);
        transaction.commit();
    }

    /*
    {
        odb::Transaction transaction(session);

        odb::ptr<User> joe = session.find<User>().where("name = ?").bind("Joe");

        std::cerr << "Joe has karma: " << joe->karma << std::endl;

        odb::ptr<User> joe2 = session.query< odb::ptr<User> >
                              ("select u from \"T_USER_USR\" u").where("name = ?").bind("Joe");

        transaction.commit();
    }

    {
        odb::Transaction transaction(session);

        typedef odb::collection< odb::ptr<User> > Users;

        Users users = session.find<User>();

        std::cerr << "We have " << users.size() << " users:" << std::endl;

        for (Users::const_iterator i = users.begin(); i != users.end(); ++i)
            std::cerr << " T_USER_USR " << (*i)->name
                      << " with karma of " << (*i)->karma << std::endl;

        transaction.commit();
    }
    */
    /*****
     * Dbo tutorial section 5. Updating objects
     *****/
    /*
    {
        odb::Transaction transaction(session);

        odb::ptr<User> joe = session.find<User>().where("name = ?").bind("Joe");

        joe.modify()->karma++;
        joe.modify()->password = "public";

        transaction.commit();
    }

    {
        odb::Transaction transaction(session);
        odb::ptr<User> joe = session.find<User>().where("name = ?").bind("Joe");
        if (joe)
            joe.remove();
        transaction.commit();
    }

    {
        odb::Transaction transaction(session);

        odb::ptr<User> silly = session.add(new User("Toto"));
        silly.modify()->name = "Silly";
        silly.remove();

        transaction.commit();
    }
    */
}

int main(int argc, char **argv)
{
    run();
}
