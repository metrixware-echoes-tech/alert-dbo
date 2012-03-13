#ifndef USERFIELD_H
#define USERFIELD_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Constants.h"
#include "User.h"

class User;
class UserValue;

class UserField
{
    public:
        UserField();
        virtual ~UserField();

        Wt::Dbo::collection<Wt::Dbo::ptr<User>> users;

        Wt::Dbo::collection<Wt::Dbo::ptr<UserValue>> userValues;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             users,
                             Wt::Dbo::ManyToMany,
                             "TJ_USR_UFI");

            Wt::Dbo::hasMany(a,
                             userValues,
                             Wt::Dbo::ManyToOne,
                             "UVA_UFI");
        }
    protected:
    private:
};

#endif // USERFIELD_H
