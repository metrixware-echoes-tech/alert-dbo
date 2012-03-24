#ifndef USERROLE_H
#define USERROLE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/WtSqlTraits>

#include "User.h"
#include "Constants.h"

class User;

class UserRole
{
public:
    UserRole();
    virtual ~UserRole();

    Wt::Dbo::collection<Wt::Dbo::ptr<User>> users;

    template<class Action>
    void persist(Action& a)
    {
        //Wt::Dbo::belongsTo(a, user, User::getName().c_str());
        Wt::Dbo::hasMany(a,
                         users,
                         Wt::Dbo::ManyToOne,
                         "URO");
    }



};

#endif // USERROLE_H
