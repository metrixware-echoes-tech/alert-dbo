#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Constants.h"
#include "User.h"

class Hierarchy
{
    public:
        Hierarchy();
        virtual ~Hierarchy();

        Wt::Dbo::ptr<User> userParent;
        Wt::Dbo::ptr<User> userChild;

        template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::belongsTo(a, userParent, "UPA");
        Wt::Dbo::belongsTo(a, userChild, "UCH");
    }
    protected:
    private:
};

#endif // HIERARCHY_H
