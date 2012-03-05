#ifndef USERROLE_H
#define USERROLE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/WtSqlTraits>

#include "Constants.h"
#include "User.h"

class User;

class UserRole
{
public:
    UserRole();
    virtual ~UserRole();
    Wt::Dbo::ptr<User> user;

    template<class Action>
    void persist(Action& a)
    {
        //Wt::Dbo::belongsTo(a, user, User::getName().c_str());
        Wt::Dbo::belongsTo(a, user, Constants::T_USER_USR);
    }
};

#endif // USERROLE_H
