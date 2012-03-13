#ifndef USERVALUE_H
#define USERVALUE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "User.h"

class UserField;

class UserValue
{
    public:
        UserValue();
        virtual ~UserValue();

        Wt::Dbo::ptr<User> user;

        Wt::Dbo::ptr<UserField> userField;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, user, "UVA_USR");

            Wt::Dbo::belongsTo(a, userField, "UVA_UFI");
        }
    protected:
    private:
};

#endif // USERVALUE_H
